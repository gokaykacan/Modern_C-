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
};

class Employee {

	std::unique_ptr<Project> m_pProject;

public:
	void setProject(std::unique_ptr<Project> &p)
	{
		m_pProject = std::move(p);
	}

	const std::unique_ptr<Project>& getProject() const
	{
		return m_pProject;
	}
};

void ShowInfo(const std::unique_ptr<Employee>& e)
{
	std::cout << "ShowInfo: ";  
	e->getProject()->showProjectName();
}

int main()
{
	std::unique_ptr<Project> p1{ new Project{} };
	p1->setProjectname("Devices Project");

	std::unique_ptr<Employee> e1{ new Employee{} };
	e1->setProject(p1); 

	std::unique_ptr<Employee> e2{ new Employee() };
	e2->setProject(p1); // e1 ile setProject çaðýrdýgýmýzda pointer move oldugu için artýk e2 ve e3 te p1 e ulaþamayýz. O yüzden program crash olur

	std::unique_ptr<Employee> e3{ new Employee() };
	e3->setProject(p1);

	ShowInfo(e1);
	ShowInfo(e2);
	p1->showProjectName();

	return 0;
}

