#include <iostream>

class CEmployeeInfo
{
public:
    CEmployeeInfo(const std::string& jobTitle, int experience, int salary) 
        : fJobTitle( jobTitle ), fYearsOfExperience(experience), fSalary(salary) {}

    CEmployeeInfo(const CEmployeeInfo& other)
        : fJobTitle(other.fJobTitle), fYearsOfExperience(other.fYearsOfExperience), fSalary(other.fSalary) {}

    ~CEmployeeInfo() = default;

    void SetJobTitle(const std::string& jobTitle)
    {
        this->fJobTitle = jobTitle;
    }

    void SetYearsOfExperience(int experience)
    {
        this->fYearsOfExperience = experience;
    }

    void SetSalary(int salary)
    {
        this->fSalary = salary;
    }

    friend std::ostream& operator<<(std::ostream& os, const CEmployeeInfo& info)
    {
        return os << "Job: " << info.fJobTitle << ", Years of experience: " << info.fYearsOfExperience << " years, Salary: " << info.fSalary << " lea\n";
    }
private:
    std::string fJobTitle;
    int         fYearsOfExperience;
    int         fSalary;
};

class CEmployee
{
public:
    CEmployee(const std::string& name, CEmployeeInfo* jobInfo) : fName(name), fJobInfo(jobInfo) {}

    CEmployee(const CEmployee& other) : fName(other.fName), fJobInfo(new CEmployeeInfo(*other.fJobInfo)) {}

    ~CEmployee()
    {
        delete fJobInfo;
    }

    void SetName(const std::string& name)
    {
        fName = name;
    }

    void SetJobTitle(const std::string& jobTitle)
    {
        this->fJobInfo->SetJobTitle(jobTitle);
    }

    void SetYearsOfExperience(int experience)
    {
        this->fJobInfo->SetYearsOfExperience(experience);
    }

    void SetSalary(int salary)
    {
        this->fJobInfo->SetSalary(salary);
    }

    friend std::ostream& operator<<(std::ostream& os, const CEmployee& employee)
    {
        return os <<"Employee: " << employee.fName << ", " << *employee.fJobInfo;
    }
    
private:
    std::string     fName;
    CEmployeeInfo*  fJobInfo;
};

int main()
{
    CEmployee ivan("Ivan", new CEmployeeInfo("Senior Software Developer", 10, 5));

    CEmployee desi(ivan);
    desi.SetName("Desislava");
    desi.SetJobTitle("Software developer");
    desi.SetYearsOfExperience(5);

    std::cout << ivan << desi;
}

