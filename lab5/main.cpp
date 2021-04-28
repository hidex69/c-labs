#include <iostream>
#include <string>


bool isInt(std::string str) {
	for(int i = 0; i < str.size(); i++) {
		if(str[i] < '0' || str[i] > '9') return false;
	}
	return true;
}

int getInt() {
	while(true) {
		std::string str;
		std::cin >> str;
		if(isInt(str)) return std::stoi(str);
		else {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Invalid input, try again..." << std::endl;
		}
	}
}


class Literature {
	protected:
		int pageNumber;
	public:
		Literature(int pageNumber = 0) : pageNumber(pageNumber){};
		virtual void getType() = 0;
		virtual ~Literature() {
			std::cout << "object has deleted" << std::endl;
		}
		virtual void getData() = 0;
		virtual int getShit() = 0;
};


class Fiction : public Literature {
	protected:
		std::string mainHero;
	public:
		Fiction(int pageNumber = 0, std::string mainHero = "") : Literature(pageNumber) {
			this->mainHero = mainHero;
		}
		~Fiction() {
			std::cout << "object has deleted" << std::endl;
		}
		void getType() override {
			std::cout << "Fiction" << std::endl;
		}
		void getData() override {
			std::cout <<"Page number: " << pageNumber << '\n' << "Main hero: " << mainHero << std::endl;
		}
		int getShit() override {
			return pageNumber / 2;
		}
};


class Verse : public Fiction {
	protected:
		int columnNumber;
	public:
		Verse(int pageNumber = 0, std::string mainHero = "", int columnNumber = 0) : Fiction(pageNumber, mainHero) {
			this->columnNumber = columnNumber;
		}
		~Verse() {
			std::cout << "object has deleted" << std::endl;
		}
		void getType() override {
			std::cout << "Verse" << std::endl;
		}
		void getData() override {
			std::cout <<"Page number: " << pageNumber << '\n' << "Main hero: " << mainHero << '\n' << "Column number: " << columnNumber << std::endl;
		}
		int getShit() override {
			return pageNumber / 2;
		}
};


class DocumentaryProse : public Literature {
	protected:
		int yearOfTheEvent;
		std::string nameOfTheEvent;
	public:
		DocumentaryProse(int pageNumber = 0, int yearOfTheEvent = 0, std::string nameOfTheEvent = "") : Literature(pageNumber) {
			this->yearOfTheEvent = yearOfTheEvent;
			this->nameOfTheEvent = nameOfTheEvent;
		}
		~DocumentaryProse() {
			std::cout << "object has deleted" << std::endl;
		}
		void getType() override {
			std::cout << "Documentary prose" << std::endl;
		}
		void getData() override {
			std::cout <<"Page number: " << pageNumber << '\n' << "Year of the event: " << yearOfTheEvent
			<< '\n' << "Name of the event: " << nameOfTheEvent << std::endl;
		}
		int getShit() override {
			return pageNumber / 2;
		}
};

void getType(Literature &l) {
	std::cout << "Type is ";
	l.getType();
}


int getShitNumber(Literature &l) {
	return l.getShit();
}

void getType(Literature *l) {
	std::cout << "Type is ";
	l->getType();
}


int getShitNumber(Literature *l) {
	return l->getShit();
}


int main(int argc, char const *argv[])
{

	// std::cout << getInt() << std::endl;
	
	std::cout << "Enter page number.." << std::endl;
	int pageNumber = getInt();


	Verse v(pageNumber, "Hero", 50);
	v.getData();
		

	getType(v);

	std::cout << "Shit number : " << getShitNumber(v) << std::endl;



	Fiction f1(100, "Hero of fiction");
	Verse v1(120, "Hero of verse");
	DocumentaryProse d1(150, 1941, "World War");                                                                                                                                                                                                                     


	Literature *litP[] = {&f1, &v1, &d1};

	std::cout << "\nArray:\n" << std::endl;

	for(int i = 0; i < 3; i++) {
		getType(litP[i]);
		litP[i]->getData();
		std::cout << "Shit number: " << getShitNumber(litP[i]) << std::endl; 
		std::cout << std::endl;
	}


	system("pause");
	return 0;
}


