#ifndef PEOPLE_H_INCLUDED
#define PEOPLE_H_INCLUDED
 
#include<string>
#include<iostream>
#include<iomanip>

using namespace std;


class People
{
protected:
    string name;
    bool sex;
    int age;
    string id;
    static int person_sum;
    static int man_sum;
    static int woman_sum;
public:
    People(string a, bool b, int c, string d);
    virtual ~People();
    static int getPersonSum();
    static int getManSum();
    static int getWomanSum();
    virtual void show(){}
    virtual void showRow(){}
 
    string getName(){return name;}
    bool getSex(){return sex;}
    int getAge(){return age;}
    string getId(){return id;}
};
 

int People::person_sum = 0;
int People::man_sum = 0;
int People::woman_sum = 0;
 

int People::getPersonSum()
{
    return person_sum;
}
 

int People::getManSum()
{
    return man_sum;
}
 

int People::getWomanSum()
{
    return woman_sum;
}
 

People::People(string a, bool b, int c, string d): name(a), sex(b), age(c), id(d)
{
    person_sum++;
    if(b) man_sum++;
    else woman_sum++;
}
 

People::~People()
{
    person_sum--;
    if(sex) man_sum--;
    else woman_sum--;
}
 

#endif // PEOPLE_H_INCLUDED