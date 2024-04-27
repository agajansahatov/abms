#include "Person.h"
#include "Person.cpp"
#include <fstream>
#include <map>

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
			<<"3 Search A Card Item\n"
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
void insertTo(std::vector<Person> &people, std::string &filename){
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

		//Adding new person to vector in the memory
		people.push_back(person);

		//Adding new person to file in the storage
		ofstream file;
		file.open(filename, ios::binary | ios::out | ios::app);
		if (!file) {
			std::cout<<"Error in opening file! "
				<<"All data will be only stored in the memory.";
		}else{
			file.write((char*)&person, sizeof(person));
			file.close();
		}

		std::cout<<"Insertion Successful!"<<std::endl;
	}catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
}

void update(std::vector<Person> &people, std::string &filename){
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

		//Updating in storage file
		fstream original, temp;
		original.open(filename, ios::in | ios::binary);
		if(!original){
			std::cout<<"\nCouldn't open file. It hasn't been deleted from file!"<<std::endl;
		}else{
			temp.open("temp.bin", ios::out | ios::app | ios::binary);
			if(!temp){
				std::cout<<"\nCouldn't create new file. It hasn't been deleted from file!"<<std::endl;
			}else{
				bool isFound = false;
				Person p;
				while (original.read((char*)&p, sizeof(p))) {
					if(p.getName() == person.getName()){
						temp.write((char*)&person, sizeof(person));
						isFound = true;
					}else{
						temp.write((char*)&p, sizeof(p));
					}
				}
				if(isFound == false){
					temp.write((char*)&person, sizeof(person));
				}
				original.close();
				temp.close();

				std::remove(filename.c_str());
				std::rename("temp.bin", filename.c_str());
			}
		}

		std::cout<<"Modification successful!"<<std::endl;
	}catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}
}

void deleteFrom(std::vector<Person> &people, std::string &filename){
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

	Person person = *iterator;
	people.erase(iterator);

	//Deleting from file
	fstream original, temp;
	original.open(filename, ios::in | ios::binary);
	if(!original){
		std::cout<<"\nCouldn't open file. It hasn't been deleted from file!"<<std::endl;
	}else{
		temp.open("temp.bin", ios::out | ios::app | ios::binary);
		if(!temp){
			std::cout<<"\nCouldn't create new file. It hasn't been deleted from file!"<<std::endl;
		}else{
			Person p;
			while (original.read((char*)&p, sizeof(p))) {
				if(p.getName() != person.getName())
					temp.write((char*)&p, sizeof(p));
			}
			original.close();
			temp.close();

			std::remove(filename.c_str());
			std::rename("temp.bin", filename.c_str());
		}
	}

	std::cout<<name<<"'s deleted successfully!"<<std::endl;
}

//As long as, I store objects in both memory and storage,
//there is no need to pass filename and read from the file
//for this method
void showAll(std::vector<Person> &people){
	std::cout<<"\n";
	printAtCenter("ALL CARD ITEMS", '-', 40);

	std::cout<<"\nThere are " << people.size()
			<< " cards in total.\n"<<std::endl;

	for(int i=0; i<people.size(); ++i)
		std::cout<<"#CARD"<<i+1<<"\n"<<people[i]<<"\n\n";
}

//As long as, I store objects in both memory and storage,
//there is no need to pass filename and read from the file
//for this method
void search(std::vector<Person> &people){
	std::cout<<"\n";
	printAtCenter("SEARCH", '-', 46);

	std::string search;
	std::cout<<"Enter any information about cards for searching: ";
	std::cin>>search;

	int numberOfMatches = 0;
	std::map<int, Person> matches;
	for(int i=0; i<people.size(); ++i){
		if(people[i].getName() == search || people[i].getTel() == search ||
			people[i].getEmail() == search || std::to_string(people[i].getAge()) == search || 
			people[i].getGender() == search){
			matches.insert({i+1, people[i]});
			numberOfMatches++;
		}
	}
	std::cout<<"\nThere are " << numberOfMatches
			<< " cards match this information.\n\n";
	for(auto& [index, person] : matches)
		std::cout<<"#CARD"<<index<<"\n"<<person<<"\n\n";
}



int main(){

	std::cout<<"Welcome to ADDRESS BOOK MANAGEMENT SYSTEM!"<<std::endl;
	bool firstTime = true;

	//Actually, if I use a file to store the informations, 
	//there is no need for storing all person objects in the memory
	//but, as it is asked in the requirements of the experiment, so,
	//I stored them in the BOTH MEMORY(via vectors) and STORAGE(via file)
	std::vector<Person> people;
	std::string filename = "abms.bin";

	//Reading all informations from storage (from <filename> file)
	ifstream file;
	file.open(filename, ios::binary | ios::in);
	if (!file) {
		std::cout<<"Error in opening file! "
			<<"All data will be only stored in the memory.";
    }else{
    	Person person;
		while(file.read((char*)&person, sizeof(person))) {
			people.push_back(person);
		}
		file.close();
    }

	//SYSTEM DISPLAY
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
			insertTo(people, filename);
		}else if(option == 2) {
			showAll(people);
		}else if(option == 3) {
			search(people);
		}else if(option == 4) {
			update(people, filename);
		}else if(option == 5){
			deleteFrom(people, filename);
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

