#include <iostream>
#include <string>
#include "Person.h"
#include "Person.cpp"

void printAtCenter(std::string str, char ch, int size) {
	size = size - str.length();
	for(int i=0; i<size; ++i) {
		if(i == size/2)
			std::cout<<str;
		std::cout<<ch;
	}
	std::cout<<"\n";
}
void showMenu(){
	std::cout<<"\n";
	printAtCenter("*", '*', 50);
	printAtCenter("*", '*', 50);
	std::cout<<"Address Book Management System"<<std::endl;
	printAtCenter("=", '=', 50);
	std::cout<<"\n1 Insert New Card Item\n" 
			<<"2 Show All Card Items\n"
			<<"3 Select A Card Item\n"
			<<"4 Modify A Card Item\n"
			<<"5 Delete A Card Item\n";
	printAtCenter("-", '-', 40);
	std::cout<<"\n6 Exit"<<std::endl;
	printAtCenter("=", '=', 50);
}

int getIndexOf(const std::string &name, std::vector<Person> &people){
	for(int i=0; i<people.size(); ++i){
		if(people[i].getName() == name)
			return i;
	}
	return -1;
}
void insertTo(std::vector<Person> &people){
	std::cout<<"\n";
	printAtCenter("INSERTION", '-', 41);
	std::cout<<"Please provide these informations "
			<<"to insert a new Card!"<<std::endl;
	try{
		Person person;
		std::string input;

		std::cout<<"Name: ";
		std::cin>>input;
		if(getIndexOf(input, people) > -1)
			throw std::exception("This user already exists!");
		person.setName(input);

		std::cout<<"Tel: ";
		std::cin>>input;
		person.setTel(input);

		std::cout<<"Email: ";
		std::cin>>input;
		person.setEmail(input);

		std::cout<<"Age: ";
		std::cin>>input;
		person.setAge(input);

		std::cout<<"Gender: ";
		std::cin>>input;
		person.setGender(input);

		people.push_back(person);
		std::cout<<"Insertion Successful!"<<std::endl;
	}catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
}

void update(std::vector<Person> &people){
	std::cout<<"\n";
	printAtCenter("MODIFICATION", '-', 38);
	
	std::string name;
	std::cout<<"Enter the name of card to modify: ";
	std::cin>>name;

	int index = getIndexOf(name, people);
	if(index == -1){
		std::cout<<"There isn't any card named "
				<<name<<std::endl;
		return;
	}

	auto& person = people[index];
	std::cout<<"Enter " << person.getName() 
			<< "'s new informations!"<<std::endl;
	try{
		std::string input;

		std::cout<<"Tel: ";
		std::cin>>input;
		person.setTel(input);

		std::cout<<"Email: ";
		std::cin>>input;
		person.setEmail(input);

		std::cout<<"Age: ";
		std::cin>>input;
		person.setAge(input);

		std::cout<<"Gender: ";
		std::cin>>input;
		person.setGender(input);

		std::cout<<"Modification successful!"<<std::endl;
	}catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
}

void showAll(std::vector<Person> &people){
	std::cout<<"\n";
	printAtCenter("ALL CARD ITEMS", '-', 40);

	std::cout<<"\nThere are " << people.size()
			<< " cards in total.\n"<<std::endl;

	for(int i=0; i<people.size(); ++i)
		std::cout<<"#CARD"<<i+1<<"\n"<<people[i]<<"\n\n";
}

void search(std::vector<Person> &people){
	std::cout<<"\n";
	printAtCenter("SEARCH", '-', 46);

	std::string name;
	std::cout<<"Enter the name of card to modify: ";
	std::cin>>name;

	int index = getIndexOf(name, people);
	if(index == -1){
		std::cout<<name<<" is not found!\n\n";
		return;
	}

	auto& person = people[index];
	std::cout<<"Found! "<<person.getName()<<"'s informations: "<<std::endl;
	std::cout<<"#CARD"<<index + 1<<std::endl;
	std::cout<<person<<"\n\n";
}

void deleteFrom(std::vector<Person> &people){
	std::cout<<"\n";
	printAtCenter("DELETION", '-', 42);
	
	std::string name;
	std::cout<<"Enter the name of card to delete: ";
	std::cin>>name;

	auto iterator = people.end();
	for (auto i = people.begin(); i != people.end(); ++i){
		if((*i).getName() == name){
			iterator = i;
		}
	}
	if(iterator == people.end()){
		std::cout<<"There isn't any card named "
				<<name<<std::endl;
		return;
	}

	people.erase(iterator);

	std::cout<<name<<"'s deleted successfully!"<<std::endl;
}

int main(){

	std::cout<<"Welcome to ADDRESS BOOK MANAGEMENT SYSTEM!"<<std::endl;
	bool firstTime = true;

	std::vector<Person> people;

	while(true) {
		std::string input;
		if(firstTime == false){
			std::cout<<"\nDo you want to continue? (y/n): ";
			std::cin>>input;
			if(input == "n" || input == "N") {
				break;
			}else if(input != "y" && input != "Y"){
				std::cout<<"Only 'y' or 'n' is allowed,"
						<<" please try again!"<<std::endl;
				continue;
			}
		}
		
		firstTime = false;
		showMenu();
		std::cout<<"Please select the operation serial number: ";	
		std::cin>>input;

		if(!Person::isNumber(input)) {
			std::cout<<"\nOnly numbers are allowed,"
					<<" please try again!"<<std::endl;
			continue;
		}
		
		int option = std::stoi(input);
		if(option == 1) {
			insertTo(people);
		}else if(option == 2) {
			showAll(people);
		}else if(option == 3) {
			search(people);
		}else if(option == 4) {
			update(people);
		}else if(option == 5){
			deleteFrom(people);
		}else if(option == 6) {
			std::cout<<"Exit"<<std::endl;
			break;
		}else {
			std::cout<<"The number you entered is not correct,"
					<<" please try again!"<<std::endl;
			continue; 
		}
	}
	std::cout<<"\nThanks for using. See you next time :)"
			<<std::endl;

	return 0;
}

