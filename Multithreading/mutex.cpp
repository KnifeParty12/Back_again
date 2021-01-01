#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>
#include <string>

using namespace std;
static int sharedVariable = 0;

void myThread() {
	for (int i = 0; i < 1000000; i++)
		sharedVariable++;
}
int main() {
	thread t(myThread);
	
	for (int i = 0; i < 1000000; i++)
		sharedVariable--;

	t.join();

	
	cout << "sharedVariable=" << sharedVariable << endl;
}

int sharedVariable = 0;
std::mutex mu;

void myThread() {
	
	for (int i = 0; i < 100000; i++)
	{
		std::lock_guard<std::mutex> locker(mu);

		sharedVariable++;
		//mu.unlock();
	}
	

}
int main() {
	thread t(myThread);

	for (int i = 0; i < 100000; i++)
	{
		std::lock_guard<std::mutex> locker(mu);
		//std::unique_lock<mutex> locker(mu, std::defer_lock);
		//locker.lock();
		//std::unique_lock<mutex> locker(mu);
		sharedVariable--;


		//locker.unlock();
		
		////mu.unlock();
	}

	t.join();
	cout << "sharedVariable=" << sharedVariable << endl;
}
//std::lock_guard<std::mutex> locker(mu);

class Real {
	std::recursive_mutex mu;
	//! std::mutex mu;
	int i;

public:

	Real() : i(10) {}

	int mul(int x) {
		mu.lock();
		i *= x;
		mu.unlock();
		return i;
	}

	int div(int x) {
		mu.lock();
		i /= x;
		mu.unlock();
		return i;
	}
	int both(int x, int y) {
		mu.lock();
		mul(x);
		div(y);
		mu.unlock();
		return i;

	}
};

int main()
{

	Real r;
	int result = r.both(10, 5);
	cout << result;

	return 0;
}


class LogFile {
	std::mutex m_mutex;
	ofstream f;
public:
	LogFile() {
		f.open("log.txt");
	}
	void shared_print(string id, int value) {
		std::lock_guard<std::mutex> locker(m_mutex);
		f << "From " << id << ": " << value << endl;
		
	}
};

void threadt1(LogFile& log)
{
	for (int i = 0; i > -100; i--)
		log.shared_print("t1", i);
}

int main() {
	LogFile log;
	std::thread t1(threadt1,std::ref(log));

	for (int i = 0; i < 100; i++)
		log.shared_print("main", i);

	t1.join();

	return 0;
}

//! std::unique_lock<mutex> locker(m_mutex);
//! std::unique_lock<mutex> locker(m_mutex, std::defer_lock);