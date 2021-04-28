#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>





namespace test {

    class Person {
        private:
            std::string name;
            int age;
        public:
            Person(std::string _name = "", int _age = 0) :
                age(_age), name(_name) {};
            ~Person(){};
            friend bool operator== (Person &p1, Person &p2) {
                return (p1.name == p2.name && p1.age == p2.age);
            }
            friend bool operator!= (Person &p1, Person &p2) {
                return !(p1.age == p2.age);
            }
            friend bool operator< (Person &p1, Person &p2) {
                return (p1.age < p2.age);
            }
            friend bool operator> (Person &p1, Person &p2) {
                return !(p1.age < p2.age);
            }
            Person& operator=(Person &p) {
                name = p.name;
                age = p.age;
                return *this;
            }
            friend std::ostream& operator<<(std::ostream &os, Person &p) {
                os << p.name << ' ' << p.age;
                return os;
            }
            friend std::istream& operator>>(std::istream &os, Person &p) {
                os >> p.name >> p.age;
                return os;
            }

    };


    void numberOfSymbols(std::fstream &file, char c) {
        file.open("file.txt", std::ios::in);
        std::list<char> l;
        while(!file.eof()) {
            l.push_back(file.get());
        }
        int counter = 0;
        for(auto i : l) {
            if(i == c) {
                counter++;
            }
        }
        file.close();
        std::fstream f;
        f.open("NewFile.txt", std::ios::out);
        if(f.is_open()) {
            std::cout << "File open" << std::endl;
        }else {
            std::cout << "Error" << std::endl;
        }
        f << counter << '\n';
        f.close();
    }

    std::list<Person>::iterator difference(std::list<Person>::iterator l1, std::list<Person>::iterator l2) {
        Person tmp;
        while(*l1 == *l2) {
            tmp = *l1;
            l1++;
            l2++;
        }
        if(*l1 == tmp) {
            return l2;
        }else return l1;
    }

    void changing(std::list<Person>::iterator i1, std::list<Person>::iterator i2, std::string condition, Person value){
        std::cout << "Enter new person ";
        Person newPerson;
        std::cin >> newPerson;

        for(auto i = i1; i != i2; i++) {
            if(condition == "<") {
                if(*i < value) {
                    *i = newPerson;
                }
            }else if(condition == ">") {
                if(*i > value) {
                    *i = newPerson;
                }
            }else if(condition == "!=") {
                if(*i != value) {
                    *i = newPerson;
                }
            }
        }
    };
}





int main() {
                // #1
    std::fstream f;
    f.open("File.txt", std::ios::out);
    f << "Hello";
    f.close();
    test::numberOfSymbols(f, 'l');


                // #2

    // std::list<test::Person> l1 = {{"Alex", 16}, {"Alex", 16},{"Alex", 16},{"Bob", 12}}, l2 = {{"Alex", 16},{"Alex", 16},{"John", 24}};
    // std::cout << *test::difference(l1.begin(), l2.begin()) << std::endl;


                // #3

    // std::list<test::Person> p1 = {{"Alex", 15}, {"Bob", 9}, {"John", 25}, {"Ros", 20} };
    // test::changing(p1.begin(), p1.end(), "!=", {"Rob", 9});
    // for(auto i : p1) {
    //     std::cout << i << std::endl;
    // }

  
    system("pause");
    return 0;
}