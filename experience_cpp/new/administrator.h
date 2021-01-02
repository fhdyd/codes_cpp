#ifndef ADMINISTRATOR_H_INCLUDED
#define ADMINISTRATOR_H_INCLUDED
 
#include"people.h"
 

class Administrator: virtual public People
{
protected:
    string position;
    static int administrator_sum;
public:
    Administrator(string a = "000", bool b = 1, int c = 0, string d = "000",
                string f = "000");
    ~Administrator();
 
    static int getAdministratorSum();
    virtual void show();
    virtual void showRow();
    virtual bool change();
    string getPosition(){return position;}
};
 

int Administrator::administrator_sum = 0;
 

int Administrator::getAdministratorSum()
{
    return administrator_sum;
}
 

Administrator::Administrator(string a, bool b, int c, string d, string e):
People(a,b,c,d), position(e){
    administrator_sum++;
}
 

Administrator::~Administrator()
{
    administrator_sum--;
}


void Administrator::show()
{
    cout << "行政人员：\n";
    cout << "姓名:\t\t" << name << endl;
    cout << "姓别:\t\t";
    if(sex) cout << "男\n";
    else cout << "女\n";
    cout << "年龄:\t\t" << age << endl;
    cout << "编号:\t\t" << id << endl;
    cout << "职务:\t\t" << position << endl;
}


void Administrator::showRow()
{
    cout << left << setw(10) << name;
    if(sex) cout << left << setw(8) << "男";
    else cout << left << setw(8) << "女";
    cout << left << setw(8) << age;
    cout << left << setw(16) << id;
    cout << left << setw(16) << position;
    cout << endl;
}


bool Administrator::change()
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
 
 
    cout << "职务:\t\t";
    cin >> position;
    return 0;
}
 

#endif // ADMINISTRATOR_H_INCLUDED