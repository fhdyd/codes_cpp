#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
 
#include<string>
#include<iostream>
#include<iomanip>
 
using namespace std;


class Person
{
protected:
    string name;
    bool sex;
    int age;
    string id;
    static int person_sum;//静态成员变量，类共有
    static int man_sum;
    static int woman_sum;
public:
    Person(string a, bool b, int c, string d);//带参构造函数
    virtual ~Person();
    static int get_person_sum();
    static int get_man_sum();
    static int get_woman_sum();
    virtual void show(){}
    virtual void show_row(){}
    virtual bool change(){}
 
    string get_name(){return name;}
    bool get_sex(){return sex;}
    int get_age(){return age;}
    string get_id(){return id;}
};
 
int Person::person_sum = 0;
int Person::man_sum = 0;
int Person::woman_sum = 0;
 
int Person::get_person_sum()
{
    return person_sum;
}
 
int Person::get_man_sum()
{
    return man_sum;
}
 
int Person::get_woman_sum()
{
    return woman_sum;
}
 
Person::Person(string a, bool b, int c, string d): name(a), sex(b), age(c), id(d)
{
    person_sum++;
    if(b) man_sum++;
    else woman_sum++;
}
 
Person::~Person()
{
    person_sum--;
    if(sex) man_sum--;
    else woman_sum--;
}
 
#endif