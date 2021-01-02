#ifndef TEAADMI_H_INCLUDED
#define TEAADMI_H_INCLUDED
 
#include"teacher.h"
#include"administrator.h"
 

class TeaAdmi: public Teacher, public Administrator
{
private:
    static int teaadmi_sum;
public:
    TeaAdmi(string a = "000", bool b = 1, int c = 0, string d = "0",
            string e = "000", string f = "000", string g = "00",
            string i = "000");
    ~TeaAdmi();
    static int getTeaadmiSum();
    virtual void show();
    virtual void showRow();
    virtual bool change();
};
 

int TeaAdmi::teaadmi_sum = 0;
 

int TeaAdmi::getTeaadmiSum()
{
    return teaadmi_sum;
}
 

TeaAdmi::TeaAdmi(string a, bool b, int c, string d, string e, string f, string g, string i):
People(a,b,c,d), Teacher(a,b,c,d,e,f,g), Administrator(a,b,c,d,i)
{
    teaadmi_sum++;
}
 

TeaAdmi::~TeaAdmi()
{
    teaadmi_sum--;
}
 

void TeaAdmi::show()
{
    cout << "教师及行政人员：\n";
    cout << "姓名:\t\t" << name << endl;
    cout << "姓别:\t\t";
    if(sex) cout << "男\n";
    else cout << "女\n";
    cout << "年龄:\t\t" << age << endl;
    cout << "编号:\t\t" << id << endl;
    cout << "院系:\t\t" << department << endl;
    cout << "专业:\t\t" << profession << endl;
    cout << "职称:\t\t" << title << endl;
    cout << "职务:\t\t" << position << endl;
}
 

void TeaAdmi::showRow()
{
    cout << left << setw(10) << name;
    if(sex) cout << left << setw(8) << "男";
    else cout << left << setw(8) << "女";
    cout << left << setw(8) << age;
    cout << left << setw(16) << id;
    cout << left << setw(16) << position;
    cout << left << setw(16) << department;
    cout << left << setw(20) << profession;
    cout << left << setw(16) << title;
    cout << endl;
}
 

bool TeaAdmi::change()
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
 
    cout << "职称:\t\t";
    cin >> title;
 
    cout << "职务:\t\t";
    cin >> position;
    return 0;
}
 

#endif // TEAADMI_H_INCLUDED