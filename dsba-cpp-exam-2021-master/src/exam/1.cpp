#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

const double RUB_USD = 89.5;

class Human
{
private:
    std::string name;
    int age;

public:
    Human(std::string name, int age = 20) : name(name), age(age) { ++counter; };
    virtual std::string getInfo()
    {
        //        std::cout << "Name: " << name << ", age: " << age;
        return "Name: " + name + ", age: " + std::to_string(age);
    };
    virtual std::string getDegree() = 0;
    static size_t counter;
    int getAge() const
    {
        return age;
    }
    bool operator>(Human* other)
    {
        return this->age > other->age;
    }
};

class Student : public Human
{
private:
    double mark;

public:
    Student(std::string name, int age = 20, double mark = 0) : Human(name, age), mark(mark){};
    std::string getDegree()
    {
        return "Student";
    }
    std::string getInfo()
    {
        return Human::getInfo() + ", mark: " + std::to_string(mark);
        //        std::cout << " Mark: " << mark;
    }
};

class Professor : public Human
{
private:
    int salary;

public:
    Professor(std::string name, int age = 40, double salary = 5000) : Human(name, age), salary(salary){};
    std::string getDegree()
    {
        return "Professor";
    }
    std::string getInfo()
    {
        return Human::getInfo() + ", salary: " + std::to_string(salary);
        //        std::cout << " Salary: " << salary;
    }
    static double transformSalary(int value)
    {
        return value / RUB_USD;
    }
};

struct University {
    std::vector<Human*> members;
    friend std::ostream& operator<<(std::ostream& s, University uni)
    {
        for (auto i: uni.members)
        {
            s << i->getDegree() << ", " << i->getInfo() << std::endl;
        }
        return s;
    };
    Human* operator[](int ind)
    {
        if (0 <= ind && ind < members.size())
            return members[ind];
        else
            throw std::out_of_range("Wrong index");
    }
};

size_t Human::counter = 0;

int main()
{
    University uni{{new Student("Alice", {}, 10),
                    new Professor("Evgeniy", 40, 60000),
                    new Student("Pavel", 19, 5)}};
    std::sort(uni.members.begin(), uni.members.end(), [](Human* left, Human* right) { return left->getAge() < right->getAge(); });
    std::cout << uni;
    std::cout << "Classes were made: " << Human::counter << '\n';
    std::cout << Professor::transformSalary(10000) << ' ' << dynamic_cast<Professor*>(uni.members[1])->transformSalary(60000);
    try
    {

        std::cout << '\n'
                  << uni[-1]->getInfo();
    } catch (std::out_of_range& e)
    {
        std::cout << "[*] Error: " << e.what();
    } catch (...)
    {
        std::cout << "[*] Unknown error";
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

const double RUB_USD = 89.5;

class Human
{
private:
    std::string name;
    int age;

public:
    Human(std::string name, int age = 20) : name(name), age(age) { ++counter; };
    virtual std::string getInfo()
    {
        //        std::cout << "Name: " << name << ", age: " << age;
        return "Name: " + name + ", age: " + std::to_string(age);
    };
    virtual std::string getDegree() = 0;
    static size_t counter;
    int getAge() const
    {
        return age;
    }
    bool operator>(Human* other)
    {
        return this->age > other->age;
    }
};

class Student : public Human
{
private:
    double mark;

public:
    Student(std::string name, int age = 20, double mark = 0) : Human(name, age), mark(mark){};
    std::string getDegree()
    {
        return "Student";
    }
    std::string getInfo()
    {
        return Human::getInfo() + ", mark: " + std::to_string(mark);
        //        std::cout << " Mark: " << mark;
    }
};

class Professor : public Human
{
private:
    int salary;

public:
    Professor(std::string name, int age = 40, double salary = 5000) : Human(name, age), salary(salary){};
    std::string getDegree()
    {
        return "Professor";
    }
    std::string getInfo()
    {
        return Human::getInfo() + ", salary: " + std::to_string(salary);
        //        std::cout << " Salary: " << salary;
    }
    static double transformSalary(int value)
    {
        return value / RUB_USD;
    }
};

struct University {
    std::vector<Human*> members;
    friend std::ostream& operator<<(std::ostream& s, University uni)
    {
        for (auto i: uni.members)
        {
            s << i->getDegree() << ", " << i->getInfo() << std::endl;
        }
        return s;
    };
    Human* operator[](int ind)
    {
        if (0 <= ind && ind < members.size())
            return members[ind];
        else
            throw std::out_of_range("Wrong index");
    }
};

size_t Human::counter = 0;

int main()
{
    University uni{{new Student("Alice", {}, 10),
                    new Professor("Evgeniy", 40, 60000),
                    new Student("Pavel", 19, 5)}};
    std::sort(uni.members.begin(), uni.members.end(), [](Human* left, Human* right) { return left->getAge() < right->getAge(); });
    std::cout << uni;
    std::cout << "Classes were made: " << Human::counter << '\n';
    std::cout << Professor::transformSalary(10000) << ' ' << dynamic_cast<Professor*>(uni.members[1])->transformSalary(60000);
    try
    {

        std::cout << '\n'
                  << uni[-1]->getInfo();
    } catch (std::out_of_range& e)
    {
        std::cout << "[*] Error: " << e.what();
    } catch (...)
    {
        std::cout << "[*] Unknown error";
    }
    return 0;
}