#include <iostream>
#include <memory>
#include <string>

class Person {
	std::string m_name;
public:
	void display()
	{ 
		std::cout << "Person " << m_name << " rules!" << std::endl; 
	}
	Person(std::string name)
	{ 
		std::cout << "Person is created: " << name << std::endl; m_name = name;
	}
	Person() { std::cout << "Nameless person is created." << std::endl; m_name = "nameless"; }
	~Person() 
	{ 
		std::cout << "Person is destroyed: " << m_name << std::endl; 
	}
	
};

void CustomDeleter(Person* p)
{
	std::cout << "Customer Deleter is called" << std::endl;
	delete []p;
}




int main()
{
	std::shared_ptr<Person> pD(new Person("A"));
	//std::shared_ptr<Person> pD1 = std::make_shared<Person>("B"); // faster and safer

	//pD->display();

	//(*pD1).display();

	//std::shared_ptr<Person> pD2(pD);
	//pD = pD2;
	//std::cout << "Reference Count for pD2 is :" << pD2.use_count() << std::endl;
	//std::cout << "Reference Count for pD is :" << pD1.use_count() << std::endl;


	//std::shared_ptr<Person> p1(new Person());
	//Person* p = p1.get();
	//delete p;

	//pD.reset(new Person("C")); 
	//.reset(); //! Same effect as: pD3 = nullptr;
	    
		
/********** Custom Deleter ************/
	//std::shared_ptr<Person> pD4(new Person("D"), CustomDeleter);
	
	std::shared_ptr<Person[]> pD5(new Person[3]);

		

	return 0;
}














	