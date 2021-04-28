#include <iostream>

class Literature {
	protected:
		std::string authorName;
		int pageNumber;
	public:
		Literature(std::string authorName = "", int pageNumber = 0) {
			this->authorName = authorName;
			this->pageNumber = pageNumber;
		}
		~Literature() {
			std::cout << "ojbect has deleted" << std::endl;
		}
		void outputData() {
			std::cout << authorName << "\n" << pageNumber << std::endl; 
		}
}; 

class Fiction : public Literature {
	protected:
		std::string mainHero;
	public:
		Fiction(std::string authorName = "", int pageNumber = 0, std::string mainHero = "") : 
		Literature(authorName, pageNumber){
			this->mainHero = mainHero;
		}
		~Fiction() {
			std::cout << "object has deleted" << std::endl;
		}
		void outputData() {
			std::cout << authorName << "\n" << pageNumber << "\n" << mainHero << std::endl; 
		}
};

class Verse : public Fiction {
	protected:
		int columnNumber;
	public:
		Verse(std::string authorName = "", int pageNumber = 0, std::string mainHero = "", int columnNumber = 0) :
		Fiction(authorName, pageNumber, mainHero) {
			this->columnNumber = columnNumber;
			
		}
		~Verse() {
			std::cout << "object has deleted" << std::endl;
		}
		void outputData() {
			std::cout << authorName << "\n" << pageNumber << "\n" << mainHero << "\n"  << columnNumber <<  std::endl; 
		}
};

class DocumentaryProse : public Literature {
	protected:
		int yearOfTheEvent;
		std::string nameOfTheEvent;
	public:
		DocumentaryProse(std::string authorName = "", int pageNumber = 0, int yearOfTheEvent = 0, std::string nameOfTheEvent = "") : 
		Literature(authorName, pageNumber) {
			this->yearOfTheEvent = yearOfTheEvent;
			this->nameOfTheEvent = nameOfTheEvent;
		}
		~DocumentaryProse() {
			std::cout << "object has deleted" << std::endl;
		}
		void outputData() {
			std::cout << authorName << "\n" << pageNumber << "\n" << yearOfTheEvent << "\n" << nameOfTheEvent << "\n" << std::endl; 
		}
};


class Biography : public DocumentaryProse {
	protected:
		std::string name;
	public:
		Biography(std::string authorName = "", int pageNumber = 0, int yearOfTheEvent = 0, std::string nameOfTheEvent = "", std::string name = "") : 
		DocumentaryProse(authorName, pageNumber, yearOfTheEvent, nameOfTheEvent) {
			this->name = name;
		}
		~Biography() {
			std::cout << "object has deleted" << std::endl;
		}
		void outputData() {
			std::cout << authorName << "\n" << pageNumber << "\n" << yearOfTheEvent << "\n" << nameOfTheEvent << "\n" << name << std::endl; 
		}
};

	class Boredom : public Verse , public Biography {
		protected:
			int boredomCounter;
		public:
		Boredom(std::string authorName = "", int pageNumber = 0, int yearOfTheEvent = 0, std::string nameOfTheEvent = "",
		 	std::string name = "", std::string mainHero = "", int columnNumber = 0, int boredomCounter = 0) : 
		Verse(authorName, pageNumber, 	mainHero, columnNumber), Biography(authorName, pageNumber, yearOfTheEvent, nameOfTheEvent, name)
		{
			this->boredomCounter = boredomCounter;				
		}
		~Boredom() {
			std::cout << "object has deleted" << std::endl;
		}
		void outputData() {
			std::cout << Verse::authorName << std::endl;
			std::cout << Verse::pageNumber << std::endl;
			std::cout << mainHero << std::endl;
			std::cout << columnNumber << std::endl;
			std::cout << yearOfTheEvent << std::endl;
			std::cout << nameOfTheEvent << std::endl;
			std::cout << name << std::endl;
			std::cout << boredomCounter << std::endl;
		}
};


int getInt() {
	while(true) {
		int a;
		std::cin >> a;
		if(std::cin.fail() || a < 0) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}
		else 
			return a;
	}
}



int main(int argc, char const *argv[])
{	

	int pageNumber = getInt();
	int yearOfTheEvent = getInt();
	int columnNumber = getInt();
	int boredomCounter = getInt();


	Boredom *b = new Boredom("author", pageNumber, yearOfTheEvent, "Event", "Name", "Name", columnNumber, boredomCounter);

	b->outputData();


	system("pause");
	return 0;
}