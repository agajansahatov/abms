#ifndef PERSON
#define PERSON

	#include "Person.h"
	
	//Constructors
	Person::Person(){};
	Person::Person(std::string name, std::string tel, std::string email, int age, std::string gender){
		this->name = name;
		this->tel = tel;
		this->email = email;
		this->age = age;
		this->gender = gender;
	}
	Person::~Person(){};

	//Checkers
	bool Person::isNumber(const std::string &s){
		std::string expr = "[0-9]+";
		const std::regex pattern(expr);
		return regex_match(s, pattern);
	}
	bool Person::isValidPhoneNumber(const std::string &s){
		std::string expr = "^(\\+\\d{1,3}( )?)?((\\(\\d{1,3}\\))|\\d{1,3})[- .]?\\d{3,4}[- .]?\\d{4}$";
		const std::regex pattern(expr);
		return regex_match(s, pattern);
	}
	bool Person::isValidEmail(const std::string &s){
		std::string expr = "^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,7}$";
		const std::regex pattern(expr);
		return regex_match(s, pattern);
	}
	bool Person::isEmpty(const std::string &s){
		if(s == "")
			return true;
		for(int i=0; i<s.length(); ++i){
			if(s[i] != ' ')
				return false;
		}
		return true;
	}

	//Setters
	void Person::setName(const std::string &name){
		if(isEmpty(name))
			throw std::exception("Please enter a name first!");
		this->name = name;
	}
	void Person::setTel(const std::string &tel){
		if(!isValidPhoneNumber(tel))
			throw std::exception("Please enter a valid phone number!");
		
		this->tel = tel;
	}
	void Person::setEmail(const std::string &email){
		if(!isValidEmail(email))
			throw std::exception("Please enter a valid email!");
		
		this->email = email;
	}
	void Person::setAge(const std::string &s_age){
		if(!isNumber(s_age))
			throw std::exception("This field requires number. Please try again!");
		
		int age = std::stoi(s_age);
		if(age < 1)
			throw std::exception("Age should be greater than 0. Please try again!");
		
		this->age = age;
	}
	void Person::setGender(const std::string &gender){
		if(gender != "male" && gender != "female")
			throw std::exception("Enter 'male' or 'female' only!");
		this->gender = gender;
	}

	//Getters
	std::string Person::getName(){
		return this->name;
	}
	std::string Person::getTel(){
		return this->tel;
	}
	std::string Person::getEmail(){
		return this->email;
	}
	int Person::getAge(){
		return this->age;
	}
	std::string Person::getGender(){
		return this->gender;
	}

	//Overload
	std::ostream& operator<<(std::ostream &output, Person &person){
		output << "Name: " << person.name << "\nTel: " << person.tel << "\nEmail: " 
				<< person.email << "\nAge: " << person.age << "\nGender: " << person.gender;

		return output;
	}

#endif