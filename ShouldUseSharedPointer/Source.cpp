#include <iostream>

class Project {

	std::string m_Name;

public:
	void setProjectname(std::string name)
	{
		m_Name = name;
	}

	void showProjectName() const
	{
		std::cout << "[ProjectName]: " << m_Name << std::endl;
	}

	~Project()
	{
		std::cout << "~Project()" << std::endl;
	}
};

class Employee {

	std::shared_ptr<Project> m_pProject;

public:
	void setProject(std::shared_ptr<Project>& p)
	{
		m_pProject = p;
	}

	const std::shared_ptr<Project>& getProject() const
	{
		return m_pProject;
	}
	~Employee()
	{
		std::cout << "~Employee()" << std::endl;
	}
};

void ShowInfo(const std::unique_ptr<Employee>& e)
{
	std::cout << "ShowInfo: ";
	e->getProject()->showProjectName();
}

int main()
{
	std::shared_ptr<Project> p1{ new Project{} };
	p1->setProjectname("Devices Project");

	std::unique_ptr<Employee> e1{ new Employee{} };
	e1->setProject(p1);

	std::unique_ptr<Employee> e2{ new Employee() };
	e2->setProject(p1); 

	std::unique_ptr<Employee> e3{ new Employee() };
	e3->setProject(p1);

	std::cout << "Reference count: " << p1.use_count() << std::endl;

	ShowInfo(e1);
	ShowInfo(e2);
	ShowInfo(e3);
	p1->showProjectName();

	//p1.reset(); // resetlersek p1 in sayýsý 0 olur ve bundan sonra p1 e eriþemeyiz
	//e1.reset();
	 //p1.reset( new Project {} ); // böyle yaparsak da resetleyip yeni bir obje yaratýrýz bu sfer count 1 olur
	std::cout << "Reference count: " << p1.use_count() << std::endl;

	return 0;
}

