 //!Unique Pointers: exclusive owenership

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

int main()
{

	std::unique_ptr<Person> pU(new Person("A"));
	std::unique_ptr<Person> pU = std::make_unique<Person>("A");
	
	Person* p = new Person("A");
	 //Bunch of different things which causes an excpetion

	delete p;

	//std::unique_ptr<Person> pA = pU; //! Compiler Error.
	std::unique_ptr<Person> pA = std::move(pU);
	if (!pU)
		std::cout << std::endl << "pU is empty\n";

	Person*p = pU.release(); //! return the raw pinter also ownersip is released.
	Person* p1 = pU.get();  //! return the raw pinter also ownersip is not  released.

	pU.reset(); //! Similar to pU = nullptr;




	return 0;
}