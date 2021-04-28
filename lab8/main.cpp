#include <fstream>
#include <iostream>
#include <string>

const char* FILE_NAME_TXT = "FileTxt.txt";
const char* FILE_NAME_BIN = "FileBin.txt";

class MyException {
    private:
        std::string error;
    public:
        MyException(std::string exception = "Undefined error") : error(exception) {};
        std::string what() {
            return error;
        }
};


class Autobus {
    private:
        int number;
        std::string name;
        std::string destination;
    public:
        Autobus(std::string _name = "", int _number = 0, std::string destination = "") : 
            name(_name), number(_number), destination(destination) {};
        ~Autobus() {};
        friend std::ostream& operator<< (std::ostream& os, Autobus &a) {
            os << a.name << '\n' << a.number << '\n' << a.destination;
            return os;
        }
        friend std::istream& operator>> (std::istream& is, Autobus &a) {
            is >> a.name >> a.number >> a.destination;
            return is;
        }
        bool operator> (Autobus &a) {
            return name > a.getNameUsual();
        }

        std::string getNameUsual() {
            return name;
        }

        std::string& getName() {
            return name;
        }
        std::string getDestinationUsual() {
            return destination;
        }

        std::string& getDestination() {
            return destination;
        }
        int& getNumber() {
            return number;
        }
        int getNumberUsual() {
            return number;
        }
        void setName(std::string name) {
            this->name = name;
        }
        void setNumber(int number) {
            this->number = number;
        }
        void setDestination(int number) {
            this->number = number;
        }
};


class MyFile {
    private:
        int size;
        std::fstream file;
        std::string type;
        Autobus obj;
    public:
        MyFile(std::string _type) : type(_type), size(0) {
            if(type == "txt") {
                file.open(FILE_NAME_TXT, std::ios::out);
                file.close();
            }else if(type == "bin") {
                file.open(FILE_NAME_BIN, std::ios::binary | std::ios::out);
                file.close();
            }
        }

        int getSize() {
            return size;
        }

        void open() {
            if(type == "txt") {
                this->file.open(FILE_NAME_TXT, std::ios::in | std::ios::out);
            }else if(type == "bin") {
                this->file.open(FILE_NAME_BIN, std::ios::binary | std::ios::in | std::ios::out);
            }    
        }

        void close() {
            this->file.close();
        }


        friend MyFile& operator<< (MyFile& file, Autobus &a) {
            if(file.type == "txt") {
                file.file.open(FILE_NAME_TXT, std::ios::app | std::ios::out);
                file.file << a.getName() << '\n' << a.getNumber() << '\n' << a.getDestination() << '\n';
                file.file.close();
                file.size++;
            } else if(file.type == "bin") {
                file.file.open(FILE_NAME_BIN, std::ios::binary | std::ios::app | std::ios::out);
                file.file.write((char*)&a, sizeof(a));
                file.file.close();
                file.size++;
            }
            return file;
        }

        friend MyFile& operator>> (MyFile &file, Autobus &a) {
            if(file.type == "txt") {
                file.file >> a.getName() >> a.getNumber() >> a.getDestination();
            } else if(file.type == "bin") {
                file.file.read((char*)&a, sizeof(a));
            }
            return file;
        }

        friend std::ostream& operator<< (std::ostream& os, MyFile &file) {
            Autobus tmp;
            int i = 0;
            file.open();
            while(i < file.getSize()) {
                file >> tmp;
                os << tmp << '\n';
                i++;
            }
            file.close();
            return os;
        }

        Autobus& operator[] (int index) {
            if(index >= this->getSize()) {
                throw MyException("No such element");
            }
            this->open();
            int i = 0;
            while(i < index + 1) {
                if(type == "txt") {
                    this->file >> obj.getName() >> obj.getNumber() >> obj.getDestination();
                }else if(type == "bin") {
                    this->file.read((char*)&obj, sizeof(obj));
                }
                i++;
            }
            this->close();
            return obj;
        }

        void swap(int index1) {
            if(index1 >= this->getSize()) throw MyException("No such element");
            this->open();
            Autobus a1, a2;
            int i = 0;
            while(i < index1 + 1) {
                if(type == "txt") {
                    this->file >> a1.getName() >> a1.getNumber() >> a1.getDestination();
                }else if(type == "bin") {
                    this->file.read((char*)&a1, sizeof(a1));
                }
                i++;
            }
            if(type == "txt") {
                this->file >> a2.getName() >> a2.getNumber() >> a2.getDestination();
            }else if(type == "bin") {
                this->file.read((char*)&a2, sizeof(a2));
            }
            i = 0;
            this->close();
            this->open();
            Autobus a3;
            while(i < index1) {
                if(type == "txt") {
                    this->file >> a3.getName() >> a3.getNumber() >> a3.getDestination();
                }else if(type == "bin") {
                    this->file.read((char*)&a3, sizeof(a3));
                }
                i++;
            }
            if(type == "txt") {
                if(index1 != 0) {
                    this->file.seekg(-3, std::ios_base::cur);
                }
                this->file << a2.getName() << '\n' << a2.getNumber() << a2.getDestination() << '\n' << a1.getName() << '\n' << a1.getNumber() << '\n' << a1.getDestination() << '\n';
            }else if(type == "bin") {
                this->file.write((char*)&a2, sizeof(a2));
                this->file.write((char*)&a1, sizeof(a1));
            }
            
            this->close();
        }

        void edit(int index, std::string newName, int newNumber, std::string newDestination) {
            if(index >= this->getSize()) {
                throw MyException("No such element");
            }
            int i = 0;
            this->open();
            Autobus a;
            while(i < index) {
                if(type == "txt") {
                    this->file >> a.getName() >> a.getNumber() >> a.getDestination();
                }
                else if(type == "bin") {
                    this->file.read((char*)&a, sizeof(a));
                }
                i++;
            }
            if(index != 0) {
                this->file.seekg(-3, std::ios_base::cur);
            }
            if(type == "txt") {
                this->file << newName << '\n' << newNumber << '\n' << newDestination << '\n';
            }else if(type == "bin") {
                a.setName(newName);
                a.setNumber(newNumber);
                this->file.write((char*)&a, sizeof(a));
            }
            this->close();
        }

};


void sort_by_name(MyFile &file) {
    for(int i = 0; i < file.getSize(); i++) {
        for(int j = 0; j < file.getSize() - i - 1; j++) {
            if(file[j].getNameUsual() > file[j+1].getNameUsual()) {
                file.swap(j);
            }
        }
    } 
}

void sort_by_places(MyFile &file) {
    for(int i = 0; i < file.getSize(); i++) {
        for(int j = 0; j < file.getSize() - i - 1; j++) {
            if(file[j].getNumberUsual() < file[j+1].getNumberUsual()) {
                file.swap(j);
            }
        }
    } 
}


int main() {

                            // TXT

    MyFile file("txt");
    Autobus a1("Bus9", 30, "MSK"), a2("Bus5", 25, "VTB"), a3("Bus2", 40, "SPB");

    file << a1 << a2 << a3;
    
    // Cчитывание 
    Autobus a4;
    file.open();
    file >> a4;
    std::cout << "Read object:\n" << a4 << '\n' << '\n';
    file.close();


    std::cout << "Conditional output:\n";
    for(int i = 0; i < file.getSize(); i++) {
        if(file[i].getNumberUsual() >= 30) {
            std::cout << file[i] << std::endl;
        }
    }

    std::cout << "Change of object #1:\n";
    file.edit(0, "Bus8", 20, "QQQ");
    std::cout << file << std::endl;

    try {
        file.edit(10, "OwO", 12, "ads");
    }catch(MyException &ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    }
    file.close();

                                // BINARY
    
    std::cout << '\n' << "BINARY" << '\n' << std::endl;

    MyFile filebin("bin");
    filebin << a1 << a2 << a3;

    std::cout << "Reverse output:\n";
    for(int i = filebin.getSize() - 1; i > -1; i--) {
        std::cout << filebin[i] << std::endl;
    }

    std::cout << "Sort by name:\n";
    sort_by_name(filebin);
    std::cout << filebin;

    std::cout << "Sort by places:\n";
    sort_by_places(filebin);
    std::cout << filebin;

    try {
        std::cout << filebin[10] << std::endl;
    }catch(MyException &ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    }

    std::cout << "With how many places do you want to find? ";
    int seats;
    std::cin >> seats;

    for(int i = 0; i < filebin.getSize(); i++) {
        if(filebin[i].getNumberUsual() == seats) {
            std::cout  << filebin[i] << std::endl;
        }
    }


    system("pause");
    return 0;
}