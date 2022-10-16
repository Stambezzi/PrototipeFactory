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

class CEmployeeFactory
{
public:
    static std::unique_ptr<CEmployee> CreateNewJuniorEmployee(const std::string& name, int salary)
    {
        static CEmployee prototypeJunior("", new CEmployeeInfo("Junior Software Developer", 0, salary));
        std::unique_ptr<CEmployee> newEmpoyee = std::make_unique<CEmployee>(prototypeJunior);
        newEmpoyee.get()->SetName(name);
        newEmpoyee.get()->SetSalary(salary);
        return newEmpoyee;
    }

    static std::unique_ptr<CEmployee> CreateNewRegularEmployee(const std::string& name, int salary)
    {
        static CEmployee prototypeRegular("", new CEmployeeInfo("Software Developer", 5, salary));
        std::unique_ptr<CEmployee> newEmpoyee = std::make_unique<CEmployee>(prototypeRegular);
        newEmpoyee.get()->SetName(name);
        newEmpoyee.get()->SetSalary(salary);
        return newEmpoyee;
    }

    static std::unique_ptr<CEmployee> CreateNewSeniorEmployee(const std::string& name, int salary)
    {
        static CEmployee prototypeSenior("", new CEmployeeInfo("Senior Software Developer", 10, salary));
        std::unique_ptr<CEmployee> newEmpoyee = std::make_unique<CEmployee>(prototypeSenior);
        newEmpoyee.get()->SetName(name);
        newEmpoyee.get()->SetSalary(salary);
        return newEmpoyee;
    }
};

int main()
{
    std::unique_ptr<CEmployee> ivan = CEmployeeFactory::CreateNewSeniorEmployee("Ivan", 5);

    std::unique_ptr<CEmployee>  desi = CEmployeeFactory::CreateNewRegularEmployee("Desislava", 5);

    std::cout << *ivan << *desi;
}

