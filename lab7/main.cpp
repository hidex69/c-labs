#include <iostream>


class MyException {
    private:
        std::string error;
    public:
        MyException(std::string _error = "Something wrong") : error(_error) {};
        const char* what() {
            return error.c_str();
        }
};


class Employee {
    private:
        std::string name;
        float salary;
    public:
        Employee(std::string name = "", float salary = 0.0) : name(name), salary(salary) {};
        bool operator< (Employee empl) {
            return this->name < empl.name;
        }
        bool operator== (Employee empl) {
            return (this->name == empl.name) && (this->salary == empl.salary);
        }
        friend std::ostream& operator<<(std::ostream &os, Employee empl);
        Employee& operator=(Employee empl) {
            this->name = empl.name;
            this->salary = empl.salary;
            return *this;
        }
        std::string getName() {
            return name;
        }
};

std::ostream& operator<<(std::ostream &os, Employee empl) {
    os << "Name: " << empl.name << "    " << "Salary: " << empl.salary << "$";
    return os;
}


template <typename T>
class Double_list {
    public:
        static int size;

        class Node {
            public:
                Node *next;
                Node *prev;
                T data;
                Node() {};
                Node(T _data) {
                    size++;
                    this->data = _data;
                }
        };

        class Iterator {
            private:
                Node *node;
            public:
                Iterator() : node() {};
                Iterator(Iterator &it) : node(it.node) {};
                Iterator(Node *node) : node(node) {};
                Iterator& operator++() {
                    node = node->next;
                    return *this;
                }
                Iterator& operator+(int value) {
                    int i = 0;
                    while(i < value) {
                        node = node -> next;
                        i++;
                    }
                    return *this;
                }
                Iterator& operator-(int value) {
                    int i = 0;
                    while(i < value) {
                        node = node -> prev;
                        i++;
                    }
                    return *this;
                }
                Iterator& operator--() {
                    node = node->prev;
                    return *this;
                }
                Iterator& operator=(Iterator it) {
                    this -> node = it.node;
                    return *this;
                }
                T& operator*() {
                    return node->data;
                }
                bool operator==(Iterator it) {
                    return this->node == it.node;
                }
                bool operator!=(Iterator it) {
                    return this->node != it.node;
                }
                bool operator>(Iterator it) {
                    return this->node > it.node;
                }
                bool operator<(Iterator it) {
                    return this->node < it.node;
                }

        };

        int getSize() {
            return size;
        }

    private:
        Node *head;
        Node *tail;
        Iterator *headIterator;
        Iterator *tailIterator;

    public:
        Double_list() {
            head = tail = nullptr;
        }

        Double_list(T _data) {
            tail = head = new Node(_data);
            headIterator = tailIterator = new Iterator(head);
        }  

        int find(T _data) {
            Node *tmp = head;
            int index = 0;
            while(tmp != nullptr) {
                if(tmp -> data == _data) {
                    return index; 
                }
                index++;
                tmp = tmp->next;
            }
            return index;
        }

        void remove_back() {
            Node *tmp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete tmp;
            size--;
            tailIterator = new Iterator(tail);
        }

        void remove_front() {
            Node *tmp = head;
            head = head->next;
            head->prev = nullptr;
            delete tmp;
            size--;
            headIterator = new Iterator(head);
        }

        void push_back(T _data) {
            Node *current = new Node(_data);
            if(head == nullptr) {
                current->next = nullptr;
                current->prev = nullptr;
                tail = current;
                head = current;
            }else {
                current->next = nullptr;
                current->prev = tail;
                tail->next = current;
                tail = current;
                tailIterator = new Iterator(tail);
            }
        }

        void push_front(T _data) {
            Node *current = new Node(_data);
            if(head == nullptr) {
                current->next = nullptr;
                current->prev = nullptr;
                tail = current;
                head = current;
            }else {
                current->prev = nullptr;
                current->next = head;
                head->prev = current;
                head = current;
                headIterator = new Iterator(head);
            }
        }

        void add_without_duplicates(T _data) {
            Node *tmp = head;
            while(tmp != nullptr) {
                if(tmp->data == _data) {
                    throw MyException("Duplicate");
                    return;
                }
                tmp = tmp->next;
            }
            Node *current = new Node(_data);
            current->next = nullptr;
            current->prev = tail;
            tail->next = current;
            current->data = _data;
            tail = current;
            tailIterator = new Iterator(tail);
        }

        void print_list() {
            if(size != 0) {
                Node *tmp = head;
                while(tmp != nullptr) {
                    std::cout << tmp->data << std::endl;
                    tmp = tmp->next;
                }
            }
            else {
                throw MyException("Empty list");
            }
        }

        Iterator& begin() {
            return *headIterator;
        }

        Iterator& end() {
            return *tailIterator;
        }

        bool is_empty() {
            return head == tail;
        }

        T& operator[](int index) {
            Node *tmp = head;
            int cnt = 0;
            while(cnt != index) {
                cnt++;
                tmp = tmp->next;
            }
            return tmp->data;
        }

};

template <typename T>
void bubble_sort(Double_list<T> &list) {
    for(int i = 0; i < list.getSize() - 1; i++) {
        for(int j = 0; j < list.getSize() - 1 - i; j++) {
            if(list[j + 1] < list[j]) {
                T tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
            }
        }
    }
}


template <typename T>
int Double_list<T>::size = 0;


int main() {


    Double_list<Employee> list;
    
    try {
        list.print_list();
    }catch(MyException &ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    }
    
    list.push_back({"John", 1500});
    list.push_back({"Alex", 800});
    list.push_front({"Leo", 1200});
    
    try {
        list.add_without_duplicates({"Alex", 800});
    }catch(MyException &ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    }

    list.add_without_duplicates({"Bob", 6000});
    list.remove_back();

    std::cout << "Before sort: " << std::endl;
    list.print_list();

    bubble_sort(list);

    std::cout << "First element after sort: " << *list.begin() << std::endl;
    
    
    

    std::cout << "Index of Alex: " << list.find({"Alex", 800}) << std::endl;
    std::cout << "Size of list: " << list.getSize() << std::endl;

    std::cout << std::endl;

    list.print_list();

    std::cout << "After changing" << std::endl;

    auto i = list.begin();
    *i = {"Harry", 12356};
    *(i + 1) = {"Joseph", 1234};

    list.print_list();



    system("pause;");
    return 0;
}   