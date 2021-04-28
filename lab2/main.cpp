#include <iostream>

class Employee;

class Accountant {
public:
	void setSalary(Employee &, float newSalary);	
};

class Employee {
	friend void getInfo(Employee &);
	friend class Accountant;
private:
	int id;
	static int idGenerator;
	std::string name;
	float salary;
public:
	Employee(std::string name, float salary) {
		if(id > 0) {
			id = idGenerator++;	
			this->salary = salary;
			this->name = name;
			std::cout << "object has created" << std::endl;
		}
	}
	Employee() {
		id = idGenerator++;
		name = "Employee";	
		salary = 0.0;
		std::cout << "object has created" << std::endl;
	}
	~Employee() {
		idGenerator--;
		std::cout << "object has deleted" << std::endl;
	}
};

int Employee::idGenerator = 1;

void getInfo(Employee &empl) {
	std::cout << "Full name: " << empl.name << "\nSalary: " << empl.salary << "$\n" << "id: " << empl.id << std::endl;
}

void Accountant::setSalary(Employee &empl, float newSalary) {
	empl.salary = newSalary;
}

int main(int argc, char const *argv[])
{	
	// Employee empl = Employee(1, "Example", 10.5);
	Accountant acc;
	// getInfo(empl);
	// acc.setSalary(empl, 12.5);
	// getInfo(empl);
	Employee empl[5];
	getInfo(empl[2]);
	for(int i = 0; i < 5; i++) {
		acc.setSalary(empl[i], 5.5);
	}
	getInfo(empl[2]);
	system("PAUSE");
	return 0;
}	