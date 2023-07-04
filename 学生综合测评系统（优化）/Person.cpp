#include "Person.h"

// »ùÀà Person ======================================================================================================
Person::Person(std::string acc, std::string pass, std::string nm = "", std::string gend = "ÄĞ", std::string ph_num = "") {
	account = acc;
	password = pass;
	name = nm;
	gender = gend;
	phoneNumber = ph_num;
}

Person::~Person() {

}

void Person::view_per_info() {

}

void Person::modify_pass() {

}

//StudentÀà ==============================================================================================================================

Student::Student(std::string acc = ACCOUNT[STUDENT], std::string pass = PASSWORD[STUDENT], std::string nm, std::string gend, std::string ph_num, std::string addr = ""):Person(acc,pass,nm,gend,ph_num){
	address = addr;
}

Student::~Student() {

}

Student& Student::operator=(const Student& stu) {
	
}