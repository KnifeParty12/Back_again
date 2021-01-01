#include <iostream>
#include <memory>
using namespace std;
int main()
{
	std::shared_ptr<int> p1 (new int(5));
	
	cout<<endl<<p1.use_count();
	std::shared_ptr<int> p2 = p1;
	cout<<endl<<p1.use_count();
	{
		std::shared_ptr<int> p3 = p1;
		cout<<endl<<p1.use_count();
	}
	cout<<endl<<p1.use_count();
	p1.reset();
	cout<<endl<<p2.use_count();
	cout << endl << p1.use_count();



	return 0;
}


