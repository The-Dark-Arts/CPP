#include <iostream>
#include <string>

int count = 0;
struct Person{
	std::string name;
	int age;
	int i;
	
	Person() : name("MASTER_SHIFU"), age(200), i(++count){
		std::cout << "Default constructor: Value No: " << i << std::endl;
	}
	Person(std::string str,  int me) : name(str), age(me), i(me) {
		std::cout << "Custom constructor: Value NO: " << i << i << std::endl;
	}
	~Person() {
		
		std::cout << "Destroctor: Value NO: " << i << std::endl;
	}
};

struct Student_ID{
	std::string regNo;
	int year;
	Person* person;
	
	Student_ID(): regNo("***/****/****"), year(2026), person(new Person()) {}
	Student_ID( Student_ID const& other): regNo(other.regNo), year(other.year), person(new Person(*other.person)) {} //copy constructor
	Student_ID& operator=(Student_ID const& other) {
		if(this != &other){
			regNo = other.regNo;
			year = other.year;
			Person* temp = new Person(*other.person);
			delete person;
			person = temp;
		}
		return *this;
	}
	~Student_ID(){
		delete person;
	}
};

int main( void )
{
	Student_ID david;
	Student_ID king ;
	david = king;
	
	std::cout << "REG_NO: " << david.regNo << "\n" << "Year: " << david.year << "\n" << "Personal_info: " << david.person << std::endl;
	std::cout << "\n\n\tKING\n";
	std::cout << "REG_NO: " << king.regNo << "\n" << "Year: " << king.year << "\n" << "Personal_info: " << king.person << std::endl;
}
