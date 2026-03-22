#include <iostream>
#include <string>
//value_based language;


struct Person {
	std::string name;
	int age;
	//Person() : name("Darkarts"), age(0) {} //default constructor
	//Person(std::string str, int i) : name(str), age(i) {} //custom constrictor
	Person() = default;	//explicitly implemented default constructor
};
int main( void )
{
	Person david;
	//Person david("master", 109);
	Person king;
	
	std::cout << "NAME: " << david.name << "\n" << "AGE: " << david.age << std::endl;
	std::cout << "NAME: " << king.name << "\n" << "AGE: " << king.age << std::endl;
 
	return 0;
}
