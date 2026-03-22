#include <iostream>
#include <string>
#include <utility>

static int count = 0;
struct Person{
	std::string name;
	int age;
	int i;
	
	Person(): name("Master_SHI"), age(102), i(++count) {
		std::cout << "Defalt contructor: value no " << i << std::endl;
	}
	Person(std::string str, int age): name(str), age(age), i(++count) {
		std::cout << "Explicit condtructor: value no " << i << std::endl;
	}
	~Person() {
		std::cout << "Desturctor: value no " << i << std::endl;
	}
};

struct Student_ID{
	std::string regNo;
	int year;
	Person* person;
	
	Student_ID() : regNo("***/****/****"), year(2026), person(new Person()) {}
	Student_ID(std::string str, int y, Person* me) : regNo(str), year(y), person(me) {}
	
	Student_ID (Student_ID const& other) : 	
			regNo(other.regNo),
			year(other.year),
			person(new Person(*other.person))
	{}	
	
	/*Student_ID& operator=(Student_ID const& other){
		if(this != &other){
			regNo = other.regNo;
			year = other.year;
			Person* temp = new Person(*other.person);
			delete person;
			person = temp;
		}
		return *this;
	}*/
	Student_ID& operator=(Student_ID const& other){
			Student_ID temp(other);
			using std::swap;
			swap(regNo, temp.regNo);
			swap(year, temp.year);
			swap( person, temp.person);
		return *this;	
	} 
	Student_ID(Student_ID&& other) noexcept :
		regNo(std::move(other.regNo)),
		year(other.year),
		person( 
			std::exchange(other.person, nullptr)) {}
	~Student_ID(){
		delete person;
	}
};

int main( void )
{
	Student_ID king;
	Student_ID david;
	
	//king =  david;
	
	king.year = 2014;
	
	Student_ID mwas;
	 mwas = std::move(king);
	
	std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "DAVID" << std::endl;
	std::cout << "Reg_info: " << david.regNo << "\nYear: " << david.year << std::endl;
	std::cout << "NAME: " << david.person->name << "\nAGE: " << david.person->age << std::endl;
	std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "KING" << std::endl;
	std::cout << "Reg_info: " << king.regNo << "\nYear: " << king.year << std::endl;
	std::cout << "NAME: " << king.person->name << "\nAGE: " << king.person->age << std::endl;
	std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "MWAS" << std::endl;
	std::cout << "Reg_info: " << mwas.regNo << "\nYear: " << mwas.year << std::endl;
	std::cout << "NAME: " << mwas.person->name << "\nAGE: " << mwas.person->age << std::endl;
	std::cout << "-------------------------------------------------------------------------------------------------------" << std::endl;
	return 0;
}
