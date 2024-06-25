/*! \file       solution.h
 *  \author     ---=Put your name here=---
 *  \version    1.0
 *  \date       29.06.2022
 *
 *  Final Exam. Solution module. Put ALL the declarations and definitions right here.
 *  All the class methods must be defined here (do not put their in a separated
 *  file). If you need to create a non-member auxilliary function, put its defintion
 *  here as well.
 *
 *      → Provide your solution here and upload this only file to Ya.Contest! ←
 *
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>


//========================================
//==========< Problem 1 [3pts] >==========

class Teacher
{
public:
    Teacher(const std::string& name) : _name(name) {}

    virtual ~Teacher() {}

    const std::string& getName() const { return _name; }
    virtual double calcWages() const = 0;
    virtual Teacher* cloneMe() = 0;

    // TODO: For the Problem 4 add a pure virtual function Teacher* cloneMe() here and override
    // it properly in the descendant classes.

protected:
    std::string _name;
};

class AssociateTeacher : public Teacher
{
private:
    int _bonus;

public:
    AssociateTeacher(const std::string& name, int bonus) : Teacher(name), _bonus(bonus) {}
    static const int BASE_SALARY = 1500;
    // TODO: To complete...
    int getBonus()
    {
        return _bonus;
    };
    double calcWages() const override
    {
        return BASE_SALARY + _bonus;
    };
    Teacher* cloneMe() override
    {
        return new AssociateTeacher(_name, _bonus);
    }
};

class InvitedTeacher : public Teacher
{
private:
    int _stuGroups;

public:
    InvitedTeacher(const std::string& name, int stuGropus) : Teacher(name), _stuGroups(stuGropus) {}
    static const int GROUP_TAX = 2000;
    // TODO: To complete...
    int getStuGroups()
    {
        return _stuGroups;
    };
    double calcWages() const override
    {
        return GROUP_TAX * _stuGroups;
    };
    Teacher* cloneMe() override
    {
        return new InvitedTeacher(_name, _stuGroups);
    }
};

//========================================
//==========< Problem 2 [3pts] >==========

class TArray
{
public:
    ~TArray()
    {
        for (auto x: _arr)
        {
            delete x->cloneMe();
        }
    };
    AssociateTeacher* addAssociateTeacher(const std::string& name, int bonus)
    {
        AssociateTeacher* Ateacher = new AssociateTeacher(name, bonus);
        _arr.push_back(Ateacher);
        return (Ateacher);
    };
    InvitedTeacher* addInvitedTeacher(const std::string& name, int groupsNum)
    {
        InvitedTeacher* Iteacher = new InvitedTeacher(name, groupsNum);
        _arr.push_back(Iteacher);
        return (Iteacher);
    };
    Teacher* operator[](size_t index) const
    {
        Teacher* i;
        if (index > _arr.size() - 1)
        {
            throw std::out_of_range("blah");
        }
        else
        {
            return _arr[index];
        }
    }
    size_t getSize() const
    {
        return _arr.size();
    }

protected:
    std::vector<Teacher*> _arr;
};

std::ostream& operator<<(std::ostream& os, const TArray& tArr)
{
    for (int i = 0; i < tArr.getSize(); ++i)
    {
        os << tArr[i]->getName() << ',' << tArr[i]->calcWages() << '\n';
    }
    return os;
}

//========================================
//==========< Problem 3 [2pts] >==========

std::pair<int, int> totalWagesOfTopTeachers(const TArray& tArr, int minGroups, int minBonus)
{
    std::pair<int, int> res(0, 0);

    for (int i = 0; i < tArr.getSize(); i++)
    {
        if (dynamic_cast<InvitedTeacher*>(tArr[i]) != nullptr)
        {
            auto Iteacher = dynamic_cast<InvitedTeacher*>(tArr[i]);
            if (Iteacher->getStuGroups() >= minGroups)
            {
                res.first += Iteacher->calcWages();
            }
        }
        if (dynamic_cast<AssociateTeacher*>(tArr[i]) != nullptr)
        {
            auto Ateacher = dynamic_cast<AssociateTeacher*>(tArr[i]);
            if (Ateacher->getBonus() >= minBonus)
            {
                res.second += Ateacher->calcWages();
            }
        }
    }
    return res;
}


//========================================
//==========< Problem 4 [2pts] >==========

// TODO: Add all the stuff needed for the TArray class to comply with the Rule Of Three.
// What do you have to add into the class for that?

//========================================

#endif
