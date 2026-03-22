#include <iostream>
#include <string>

int count = 0;

struct Person {
	std::string name;
	int age;
	int i = 0;
	
	Person() : name("Mastery"), age(200), i(++count){
		std::cout << "DEFAULT CONSTRUCTION: Value No: " << i << std::endl;
	} 
	Person(std::string str, int me) : name(str), age(me), i(++count){
		std::cout << "CUSTOM CONSTRUCTION: Value NO: " << i << std::endl;
	} //custom constructor
	
	~Person() {
		std::cout << "Destruction: Value NO: " << i << std::endl;
	}
};

struct Student_ID {
	std::string regNo;
	int year;
	Person *person;
	Student_ID(): regNo("***/****/****"), year(2026), person( new Person()) {}
	Student_ID(Student_ID const& other) : regNo(other.regNo), year(other.year), person(new Person(*other.person)){} //explicitly imnplemented copy constructor
	~Student_ID(){
		delete person;
	}
};

int main( void )
{
	Student_ID david;
	Student_ID kamau = david;
	Person king("KING",  25);
	
	std::cout << "REG_NO: " << david.regNo << "\n" << "Year: " << david.year << "\n" << "Personal_Info: " << david.person << std::endl;
	std::cout << "REG_NO: " << kamau.regNo << "\n" << "Year: " << kamau.year << "\n" << "Personal_Info: " << kamau.person << std::endl;
	std::cout << "\n\n" << std::endl;
	std::cout << "NAME: " << king.name <<"		" << "AGE: " << king.age << std::endl;
	
	return 0;
}
