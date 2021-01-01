#include <iostream>
#include <memory>
#include <string>

class Person {
	//std::shared_ptr<Person> m_pFriend;
	std::weak_ptr<Person> m_pFriend; //! Person* m_pFriend;
public:
	std::string m_name;
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
	void makeFriend(std::shared_ptr<Person> f)
	{
		m_pFriend = f;
	}
	void showFriend()
	{
		//m_pFriend->m_name;
		//std::cout << "My friend is: " << m_pFriend.lock()->m_name << std::endl;
		/*if (!m_pFriend.expired())
			std::cout << "My friend is: " << m_pFriend.lock()->m_name << std::endl;
		std::cout << " He is owned by " << m_pFriend.use_count() << " pointers." << std::endl;*/
	}
};

 int main()
 {

	std::shared_ptr<Person> pD(new Person("A"));
	std::shared_ptr<Person> pD2(new Person("B"));
	pD->makeFriend(pD2);
	pD2->makeFriend(pD);
	//std::cout << pD.use_count();

	//pD->showFriend();
	return 0;

};