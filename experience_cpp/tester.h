#ifndef TESTER_H_INCLUDED
#define TESTER_H_INCLUDED
 
#include"person.h"
 

class Tester: public Person
{
private:
    string laboratory;
    string title;
    static int tester_sum;
public:
    Tester(string a = "nobody", bool b = 1, int c = 19, string d = "1",
           string e = "tt", string f = "学生");
    ~Tester();
 
    static int get_tester_sum();
    virtual void show();
    virtual void show_row();
    virtual bool change();
 
    string get_laboratory(){return laboratory;}
    string get_title(){return title;}
};
 

int Tester::tester_sum = 0;
 
int Tester::get_tester_sum()
{
    return tester_sum;
}
 

Tester::Tester(string a, bool b, int c, string d, string e, string f):
Person(a,b,c,d), laboratory(e), title(f)
{
    tester_sum++;
}
 

Tester::~Tester()
{
    tester_sum--;
}
 

void Tester::show()
{
    cout << "实验员：\n";
    cout << "姓名:\t\t" << name << endl;
    cout << "姓别:\t\t";
    if(sex) cout << "男\n";
    else cout << "女\n";
    cout << "年龄:\t\t" << age << endl;
    cout << "ID:\t\t" << id << endl;
    cout << "所属实验室:\t" << laboratory << endl;
    cout << "职务:\t\t" << title << endl;
}
 

void Tester::show_row()
{
    cout << left << setw(8) << name;
    if(sex) cout << left << setw(8) << "男";
    else cout << left << setw(8) << "女";
    cout << left << setw(8) << age;
    cout << left << setw(16) << id;
    cout << left << setw(16) << laboratory;
    cout << left << setw(16) << title;
    cout << endl;
}

bool Tester::change()
{
    cout << "姓名:\t\t" ;
    string new_name;
    cin >> new_name;
    for(int i = 0; i < new_name.length(); i++)
    {
        if(new_name[i] >= '0' && new_name[i] <= '9')
        {
            cout << "输入非法，输入任意键返回\n";
            return 1;
        }//名字含数字，错误
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
 
    cout << "所属实验室:\t";
    cin >> laboratory;
 
    cout << "职务:\t\t";
    cin >> title;
    return 0;
}
 
 
#endif 