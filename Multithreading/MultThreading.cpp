#include <iostream>
#include <thread>
void thread1() 
{
	std::cout << "Helldo, Worlds" << std::endl;
}

int main() {
	std::thread t1(thread1);
	//t1.join();   // main thread wait for t1 to finish


	t1.detach();

	//t1.join();
	// main thread l
	std:cout << "Parent Thread"; //! t1 to run on its own: t1 is a daemon process.
				   // C++ runtime library is responsible returning t1's resources
				   // and main thread may finish before t2 prints "Hello"
	if(t1.joinable())
		t1.join();


	return 0;
}

// If exception happens in the main()'s for loop, t1.join() will not be called.

 //! Alternative way: RAII
class ThreadJoiner {
	std::thread& m_th;
public:
		if (m_th.joinable()) {//	ThreadJoiner(std::thread& t) :m_th(t) {}
	~ThreadJoiner() {

			m_th.join();

		}
	}
};

int main() {
	
	std::thread t1(thread1);
	ThreadJoiner tj(t1);
	for (int i = 0; i < 100; i++)
		std::cout << "from main: " << i << std::endl;

	
	return 0;
}

void Add1(unsigned char *src1, unsigned char*src2, int size)
{
	for (int i = 0; i < size; i++)
	{
		src1[i] += src2[i];
	}
}
void Add2(unsigned char *src1, unsigned char*src2, int size)
{
	for (int i = 0; i < size; i++)
	{
		src1[i] += src2[i];
	}
}

int main()
{
	unsigned char s1[1000];
	unsigned char s2[1000];
	memset(s1, 5, 1000);
	memset(s2, 10, 1000);
	std::thread thread_1(Add1, s1, s2, 500);
	std::thread thread_2(Add2, s1 + 500, s2 + 500, 500); // do other stuff
	//thread_1.join();
	//thread_2.join();

	for (int i = 0;  i< 1000; i++)
		std::cout << (int)s1[i] <<std::endl;
	thread_1.join();
	thread_2.join();
	return 0;

}

//
void threadCallback(int& x)
{
	x++;
	std::cout << "Inside Thread x = " << x << std::endl;
}
int main()
{
	int x = 9;
	std::cout << "In Main Thread : Before Thread Start x = " << x << std::endl;
	std::thread threadObj(threadCallback, std::ref(x));

	//std::thread t2 = std::move(threadObj);

	std::cout << "\nThread Id of parent thread is :" << std::this_thread::get_id;
	std::cout << "\nThread Id of child thread is :" << threadObj.get_id();
	threadObj.join();

	std::cout << "\nIn Main Thread : After Thread Joins x = " << x << std::endl;

	std::cout << "\nTotal cores avaialble are : " << std::thread::hardware_concurrency();
	return 0;
}
	
//..........................................................
//..........................................................
//..........................................................

//! Want to  execute class member function in a separate thread

class DummyClass {
private:
	int count;
public:
	DummyClass()
	{}
	DummyClass(const DummyClass & obj)
	{}
	void sampleMemberFunction(int x)
	{
		count = x;
		std::cout << "Inside sampleMemberFunction " << count << std::endl;
	}
};
int main() {

	DummyClass dummyObj;
	//dummyObj.sampleMemberFunction();
	int x = 10;
	std::thread threadObj(&DummyClass::sampleMemberFunction, &dummyObj, x);
	threadObj.join();
	return 0;
}