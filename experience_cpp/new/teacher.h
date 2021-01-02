#ifndef TEACHER_H_INCLUDED
#define TEACHER_H_INCLUDED
 
#include"people.h"
 

class Teacher: virtual public People
{
protected:
    string department;
    string profession;
    string title;
    static int teacher_sum;
public:
    Teacher(string a = "000", bool b = 1, int c = 0, string d = "000",
            string e = "000", string f = "000", string g = "000");
    ~Teacher();
 
    static int getTeacherSum();
    virtual void show();
    virtual void showRow();
    virtual bool change();
 
    string getDepartment(){return department;}
    string getProfession(){return profession;}
    string getTitle(){return title;}
};
 

int Teacher::teacher_sum = 0;
 

int Teacher::getTeacherSum()
{
    return teacher_sum;
}
 

Teacher::Teacher(string a, bool b, int c, string d, string e, string f, string g):
People(a,b,c,d), department(e), profession(f), title(g)
{
    teacher_sum++;
}
 

Teacher::~Teacher()
{
    teacher_sum--;
}


void Teacher::show()
{
    cout << "教师：\n";
    cout << "姓名:\t\t" << name << endl;
    cout << "姓别:\t\t";
    if(sex) cout << "男\n";
    else cout << "女\n";
    cout << "年龄:\t\t" << age << endl;
    cout << "编号:\t\t" << id << endl;
    cout << "院系:\t\t" << department << endl;
    cout << "专业:\t\t" << profession << endl;
    cout << "职称:\t\t" << title << endl;
}


void Teacher::showRow()
{
    cout << left << setw(10) << name;
    if(sex) cout << left << setw(8) << "男";
    else cout << left << setw(8) << "女";
    cout << left << setw(8) << age;
    cout << left << setw(16) << id;
    cout << left << setw(16) << department;
    cout << left << setw(20) << profession;
    cout << left << setw(16) << title;
    cout << endl;
}


bool Teacher::change()
{
    cout << "姓名:\t\t" ;
    string new_name;
    cin >> new_name;
    for(unsigned int i = 0; i < new_name.length(); i++)
    {
        if(new_name[i] >= '0' && new_name[i] <= '9')
        {
            cout << "输入非法，输入任意键返回\n";
            return 1;
        }
    }
    name = new_name;
 
    cout << "姓别:\t\t";
    string a;
    cin >> a;
    if(sex) man_sum--;
    else woman_sum--;
    if(a == "男") sex = 1, man_sum++;
    else sex = 0, woman_sum++;
 
    cout << "年龄:\t\t";
    cin >> age;
 
    cout << "院系:\t\t";
    cin >> department;
 
    cout << "专业:\t\t";
    cin >> profession;
 
    cout << "职务:\t\t";
    cin >> title;
    return 0;
}


#endif // TEACHER_H_INCLUDED