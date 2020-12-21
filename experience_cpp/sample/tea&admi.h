#ifndef TEAADMI_H_INCLUDED
#define TEAADMI_H_INCLUDED
 
#include"teacher.h"
#include"administrator.h"
 
class TEAADMI: public TEACHER, public ADMINISTRATOR
{
private:
    static int teaadmi_sum;
public:
    TEAADMI(std::string a = "maomao", bool b = 1, int c = 59, std::string d = "0",
            std::string e = "计算机与信息工程学院", std::string f = "计算机科学与技术", std::string g = "教师",
            std::string h = "群众", std:: string i = "社会主义新青年");
    ~TEAADMI();
    static int get_teaadmi_sum();
    virtual void show();
    virtual void show_row();
    virtual bool change();
};
 
int TEAADMI::teaadmi_sum = 0;
 
int TEAADMI::get_teaadmi_sum()
{
    return teaadmi_sum;
}
 
TEAADMI::TEAADMI(std::string a, bool b, int c, std::string d, std::string e, std::string f, std::string g, std::string h, std::string i):
COMMON(a,b,c,d), TEACHER(a,b,c,d,e,f,g), ADMINISTRATOR(a,b,c,d,h,i)
{
    teaadmi_sum++;
}
 
TEAADMI::~TEAADMI()
{
    teaadmi_sum--;
}
 
void TEAADMI::show()
{
    std::cout << "教师及行政人员：\n";
    std::cout << "姓名:\t\t" << name << std::endl;
    std::cout << "姓别:\t\t";
    if(sex) std::cout << "男\n";
    else std::cout << "女\n";
    std::cout << "年龄:\t\t" << age << std::endl;
    std::cout << "ID:\t\t" << id << std::endl;
    std::cout << "院系:\t\t" << department << std::endl;
    std::cout << "专业:\t\t" << profession << std::endl;
    std::cout << "职务:\t\t" << title << std::endl;
    std::cout << "政治面貌:\t" << politics << std::endl;
    std::cout << "职称:\t\t" << position << std::endl;
}
 
void TEAADMI::show_row()
{
    std::cout << std::left << std::setw(8) << name;
    if(sex) std::cout << std::left << std::setw(8) << "男";
    else std::cout << std::left << std::setw(8) << "女";
    std::cout << std::left << std::setw(8) << age;
    std::cout << std::left << std::setw(16) << id;
    std::cout << std::left << std::setw(16) << department;
    std::cout << std::left << std::setw(16) << profession;
    std::cout << std::left << std::setw(16) << title;
    std::cout << std::left << std::setw(16) << politics;
    std::cout << std::left << std::setw(16) << position;
    std::cout << std::endl;
}
 
bool TEAADMI::change()
{
    std::cout << "姓名:\t\t" ;
    std::string new_name;
    std::cin >> new_name;
    for(unsigned int i = 0; i < new_name.length(); i++)
    {
        if(new_name[i] >= '0' && new_name[i] <= '9')
        {
            std::cout << "输入非法，输入任意键返回\n";
            return 1;
        }
    }
    name = new_name;
 
    std::cout << "姓别:\t\t";
    std::string a;
    std::cin >> a;
    if(sex) man_sum--;
    else woman_sum--;
    if(a == "男") sex = 1, man_sum++;
    else sex = 0, woman_sum++;
 
    std::cout << "年龄:\t\t";
    std::cin >> age;
 
    std::cout << "院系:\t\t";
    std::cin >> department;
 
    std::cout << "专业:\t\t";
    std::cin >> profession;
 
    std::cout << "职务:\t\t";
    std::cin >> title;
 
    std::cout << "政治面貌:\t";
    std::cin >> politics;
 
    std::cout << "职称:\t\t";
    std::cin >> position;
    return 0;
}
 
#endif // TEA&ADMI_H_INCLUDED