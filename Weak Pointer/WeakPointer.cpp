#include <iostream>

using namespace std;
class Employee;

class Printer
{
	std::weak_ptr<int> m_pVal{};

public:
	void setValue(weak_ptr<int> val)
	{
		m_pVal = val;
	}

	void getValue()
	{
		auto sp = m_pVal.lock();
		if (m_pVal.expired() == false)
			cout << "Value: " << *sp << endl;
		else
			cout << "m_pVal is expired" << endl;

		cout << "Ref count: " << sp.use_count() << endl;
	}

	~Printer()
	{
		cout << "~Printer() " << endl;
	}
};

class Project
{
public:
	shared_ptr<Employee> m_emp{};
	Project()
	{
		cout << "Project()" << endl;
	}
	~Project()
	{
		cout << "~Project()" << endl;
	}
};

class Employee
{
public:
	weak_ptr<Project> m_prj{};
	Employee()
	{
		cout << "Employee()" << endl;
	}
	~Employee()
	{
		cout << "~Employee()" << endl;
	}
};

int main()
{
	//Printer prn;
	//int num{};

	//cout << "Enter an integer: ";
	//cin >> num; cout << endl;

	//shared_ptr<int> p{ new int(num) };
	//prn.setValue(p);
	//if (*p > 10)
	//	p = nullptr;

	//prn.getValue();

	cout << "------------------------------" << endl;

	shared_ptr<Project> prj { new Project{} };
	shared_ptr<Employee> emp{ new Employee{} };

	prj->m_emp = emp;
	emp->m_prj = prj;

	return 0;
}