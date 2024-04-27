#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <regex>
#include <exception>

class Person{
	std::string name;
	std::string tel;
	std::string email;
	int age;
	std::string gender;
	friend std::ostream& operator<<(std::ostream&, Person&);

public:
	//Constructors
	Person();
	Person(std::string, std::string, std::string, int, std::string);
	~Person();

	//Checkers
	static bool isNumber(const std::string&);
	static bool isValidPhoneNumber(const std::string&);
	static bool isValidEmail(const std::string&);
	static bool isEmpty(const std::string&);

	//Setters
	void setName(const std::string&);
	void setTel(const std::string&);
	void setEmail(const std::string&);
	void setAge(const std::string&);
	void setGender(const std::string&);
	
	//Getters
	std::string getName();
	std::string getTel();
	std::string getEmail();
	int getAge();
	std::string getGender();

};

#endif