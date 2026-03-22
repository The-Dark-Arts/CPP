//RULE_OF_THREE/Resource management
#include <iostream>
#include <string>

int count = 0;
struct Person{
	std::string name;
	int age;
	int i;
	
	Person() : name("Student"), age(25) , i(++count){
		std::cout << "Default constructor: Value NO: " << i << std::endl;
	}
	Person(std::string str, int my_age) : name(str), age(my_age), i(++count) {
		std::cout << "Custom constructor: Value NO: " << i << std::endl; 
	}
	~Person() {
		std::cout << "Destructor " << i << std::endl;
	}
};

struct Student_ID{
	std::string regNo;
	int year;
	Person* person;
	
	Student_ID() : regNo("***/****/****"), year(2026), person(new Person()) {}
	Student_ID(std::string str, int y, Person* me): regNo(str), year(y), person(me) {}
	
	Student_ID(Student_ID const& other) : regNo(other.regNo), year(other.year), person( new Person(*other.person)) {}
	Student_ID& operator=(Student_ID const& other){
		if(this != &other){
 			regNo = other.regNo;
			year = other.year;
			Person* temp = new Person(*other.person);
			delete person;
			person  = temp;
		}
		return *this;
	}
	~Student_ID() {
		delete person;
	}
};


int main( void)
{
	Student_ID david;
	Student_ID king;
	
	king = david;
	std::cout << "\tDAVID\n";
	std::cout << "RegNO: " << david.regNo << "\n" << "Year:" << david.year << "\n" << "Personal_info; " << david.person << std::endl;
	std::cout << "\n\n\tKING\n";
	std::cout << "RegNO: " << king.regNo << "\n" << "Year:" << king.year << "\n" << "Personal_info; " << king.person << std::endl;
	return 0;	
	
}
