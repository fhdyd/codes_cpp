#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED
 
#include<string>
#include<iostream>
#include<iomanip>
 
class COMMON
{
protected:
    std::string name;
    bool sex;
    int age;
    std::string id;
    static int person_sum;
    static int man_sum;
    static int woman_sum;
public:
    COMMON(std::string a, bool b, int c, std::string d);
    virtual ~COMMON();
    static int get_person_sum();
    static int get_man_sum();
    static int get_woman_sum();
    virtual void show(){}
    virtual void show_row(){}
    virtual bool change(){}
 
    std::string get_name(){return name;}
    bool get_sex(){return sex;}
    int get_age(){return age;}
    std::string get_id(){return id;}
};
 
int COMMON::person_sum = 0;
int COMMON::man_sum = 0;
int COMMON::woman_sum = 0;
 
int COMMON::get_person_sum()
{
    return person_sum;
}
 
int COMMON::get_man_sum()
{
    return man_sum;
}
 
int COMMON::get_woman_sum()
{
    return woman_sum;
}
 
COMMON::COMMON(std::string a, bool b, int c, std::string d): name(a), sex(b), age(c), id(d)
{
    person_sum++;
    if(b) man_sum++;
    else woman_sum++;
}
 
COMMON::~COMMON()
{
    person_sum--;
    if(sex) man_sum--;
    else woman_sum--;
}
 
#endif // COMMON_H_INCLUDED