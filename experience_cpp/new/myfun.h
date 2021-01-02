#ifndef MYFUN_H_INCLUDED
#define MYFUN_H_INCLUDED
 
#include<vector>
#include<map>
#include<fstream>
 
multimap<string, People *> sear;
vector<Tester*> tester;
vector<Teacher*> teacher;
vector<Administrator*> administrator;
vector<TeaAdmi*> teaadmi;
 
 
void informationLoad();        //信息加载
void addInformation();         //添加信息
bool queryInformation();       //显示查询信息
void browseInformation();      //浏览信息
void editInformation();        //修改信息
void deleteInformation();      //删除信息
void countInformation();       //统计信息
 
 
void informationLoad() //信息加载
{
    ifstream in;
    in.open("实验员.txt", ios::in);
    string name, id;
    int age;
    bool sex;
    while(in >> name)
    {
        string laboratory, title;
        in >> sex >> age >> id >> laboratory >> title;
        Tester *t = new Tester(name,sex,age,id,laboratory,title);
        tester.push_back(t);
        sear.insert(make_pair(name, t));
        sear.insert(make_pair(id, t));
    }
    in.close();
 
    in.open("教师.txt", ios::in);
    while(in >> name)
    {
        string department, profession, title;
        in >> sex >> age >> id >> department >> profession >> title;
        Teacher *t = new Teacher(name,sex,age,id,department,profession,title);
        teacher.push_back(t);
        sear.insert(make_pair(name, t));
        sear.insert(make_pair(id, t));
    }
    in.close();
 
    in.open("行政人员.txt", ios::in);
    while(in >> name)
    {
        string position;
        in >> sex >> age >> id >> position;
        Administrator *t = new Administrator(name,sex,age,id,position);
        administrator.push_back(t);
        sear.insert(make_pair(name, t));
        sear.insert(make_pair(id, t));
    }
    in.close();
 
    in.open("教师&行政人员.txt", ios::in);
    while(in >> name)
    {
        string department, profession, title, position;
        in >> sex >> age >> id >> department >> profession >> title >> position;
        TeaAdmi *t = new TeaAdmi(name,sex,age,id,department,profession,title,position);
        teaadmi.push_back(t);
        sear.insert(make_pair(name, t));
        sear.insert(make_pair(id, t));
    }
}
 

void addInformation()//添加信息
{
    
    cout << "请输入添加类型\n1：实验员\t2：教师\t\t3：行政人员\t4：教师及行政人员\n";
    int flag; cin >> flag;
    string name, se, id;
    int age;
    bool sex = 0;
    cout << "编号：\t\t"; cin >> id;
    for(unsigned int i = 0; i < id.length(); i++)
    {
        if(id[i] < '0' || id[i] > '9')
        {
            cout << "输入非法！n";
            
            return;
        }
    }
 
    multimap<string, People *>::iterator beg, en;
    beg = sear.lower_bound(id);
    en = sear.upper_bound(id);
    if(beg != en)
    {
        cout << "此编号已存在！\n";
        
        return;
    }
 
    cout << "姓名：\t\t"; cin >> name;
    for(unsigned int i = 0; i < name.length(); i++)
    {
        if(name[i] >= '0' && name[i] <= '9')
        {
            cout << "输入非法！\n";
            
            return;
        }
    }
 
    cout << "性别：\t\t"; cin >> se; if(se == "男") sex = 1;
    cout << "年龄：\t\t"; cin >> age;
    if(flag == 1)
    {
        string laboratory, title;
        cout << "实验室名称：\t"; cin >> laboratory;
        cout << "职务：\t\t"; cin >> title;
        Tester *t = new Tester(name,sex,age,id,laboratory,title);
        tester.push_back(t);
        sear.insert(make_pair(name, t));
        sear.insert(make_pair(id, t));
        ofstream out;
        out.open("实验员.txt", ios::app);
        out << name << " " << sex << " " << age << " " << id << " ";
        out << laboratory << " " << title << endl;
        out.close();
    }
    if(flag == 2)
    {
        string department, profession, title;
        cout << "院系：\t\t"; cin >> department;
        cout << "专业：\t\t"; cin >> profession;
        cout << "职称：\t\t"; cin >> title;
        Teacher *t = new Teacher(name,sex,age,id,department,profession,title);
        teacher.push_back(t);
        sear.insert(make_pair(name, t));
        sear.insert(make_pair(id, t));
        ofstream out;
        out.open("教师.txt", ios::app);
        out << name << " " << sex << " " << age << " " << id << " ";
        out << department << " " << profession << " " << title << endl;
        out.close();
    }
    if(flag == 3)
    {
        string position;
        cout << "职务：\t\t"; cin >> position;
        Administrator *t = new Administrator(name,sex,age,id,position);
        administrator.push_back(t);
        sear.insert(make_pair(name, t));
        sear.insert(make_pair(id, t));
        ofstream out;
        out.open("行政人员.txt", ios::app);
        out << name << " " << sex << " " << age << " " << id << " ";
        out << position << endl;
        out.close();
    }
    if(flag == 4)
    {
        string department, profession, title, position;
        cout << "院系：\t\t"; cin >> department;
        cout << "专业：\t\t"; cin >> profession;
        cout << "职称：\t\t"; cin >> title;
        cout << "职务：\t\t"; cin >> position;
        TeaAdmi *t = new TeaAdmi(name,sex,age,id,department,profession,title,position);
        teaadmi.push_back(t);
        sear.insert(make_pair(name, t));
        sear.insert(make_pair(id, t));
        ofstream out;
        out.open("教师&行政人员.txt", ios::app);
        out << name << " " << sex << " " << age << " " << id << " ";
        out << department << " " << profession << " " << title << " ";
        out << position << endl;
        out.close();
    }
    cout << "注册成功！\n";
    
}
 

void deleteInformation() //删除信息
{
    cout << "输入目标编号以确认\n";
    string aid;
    cin >> aid;
 
    for(unsigned int i = 0; i < aid.length(); i++)
    {
        if(aid[i] < '0' || aid[i] > '9')
        {
            cout << "输入非法！\n";
            
            return;
        }
    }
 
    multimap<string, People *>::iterator beg, en, iter;
    beg = sear.lower_bound(aid);
    en = sear.upper_bound(aid);
    if(beg == en)
    {
        cout << "目标不存在！\n";
        
        return;
    }
    string aid_name = beg -> second -> getName();
    sear.erase(beg);
    beg = sear.lower_bound(aid_name);
    en = sear.upper_bound(aid_name);
    for(iter = beg; iter != en; ++iter) if(iter -> second -> getId() == aid) {sear.erase(iter); break;}
 
    bool flag = 0;
    ofstream out;
    out.open("实验员.txt", ios::out);
    for(vector<Tester*>::iterator it = tester.begin(); it != tester.end();)
    {
        if((*it) -> getId() == aid){flag = 1; delete (*it); it = tester.erase(it); continue;}
        out << (*it) -> getName() << " " << (*it) -> getSex() << " ";
        out << (*it) -> getAge() << " " << (*it) -> getId() << " ";
        out << (*it) -> getLaboratory() << " " << (*it) -> getTitle() << endl;
        ++it;
    }
    out.close();
    if(flag) {cout << "删除成功！\n";  return;}
    out.open("教师.txt", ios::out);
    for(vector<Teacher*>::iterator it = teacher.begin(); it != teacher.end();)
    {
        if((*it) -> getId() == aid){flag = 1; delete (*it); it = teacher.erase(it); continue;}
        out << (*it) -> getName() << " " << (*it) -> getSex() << " ";
        out << (*it) -> getAge() << " " << (*it) -> getId() << " ";
        out << (*it) -> getDepartment() << " " << (*it) -> getProfession() << " " << (*it) -> getTitle() << endl;
        it++;
    }
    out.close();
    if(flag) {cout << "删除成功！\n";  return;}
    out.open("行政人员.txt", ios::out);
    for(vector<Administrator*>::iterator it = administrator.begin(); it != administrator.end();)
    {
        if((*it) -> getId() == aid){flag = 1; delete (*it); it = administrator.erase(it); continue;}
        out << (*it) -> getName() << " " << (*it) -> getSex() << " ";
        out << (*it) -> getAge() << " " << (*it) -> getId() << " ";
        out << (*it) -> getPosition() << endl;
        it++;
    }
    out.close();
    if(flag) {cout << "删除成功！\n";  return;}
    out.open("教师&行政人员.txt", ios::out);
    for(vector<TeaAdmi*>::iterator it = teaadmi.begin(); it != teaadmi.end();)
    {
        if((*it) -> getId() == aid){flag = 1; delete (*it); it = teaadmi.erase(it); continue;}
        out << (*it) -> getName() << " " << (*it) -> getSex() << " ";
        out << (*it) -> getAge() << " " << (*it) -> getId() << " ";
        out << (*it) -> getDepartment() << " " << (*it) -> getProfession() << " " << (*it) -> getTitle() << " ";
        out << (*it) -> getPosition() << endl;
        ++it;
    }
    out.close();
    cout << "删除成功！\n";
    
}
 

void editInformation() //修改信息
{
    cout << "输入目标编号以确认\n";
    string aid;
    cin >> aid;
    for(unsigned int i = 0; i < aid.length(); i++)
    {
        if(aid[i] < '0' || aid[i] > '9')
        {
            cout << "输入非法！\n";
            
            return;
        }
    }
 
    multimap<string, People *>::iterator beg, en, iter;
    beg = sear.lower_bound(aid);
    en = sear.upper_bound(aid);
 
    if(beg == en)
    {
        cout << "目标不存在！\n";
        
        return;
    }
    
    bool flag = 0;
    ofstream out;
    out.open("实验员.txt", ios::out);
    for(auto iter:tester)
    {
        if(iter -> getId() == aid)
        {
            iter -> show(), cout << "\n\n根据提示输入修改信息\n\n";
            while(iter -> change())
            {
                
                iter -> show();
                cout << "输入非法，请重新输入\n";
            }
            flag = 1;
        }
        out << iter -> getName() << " " << iter -> getSex() << " ";
        out << iter -> getAge() << " " << iter -> getId() << " ";
        out << iter -> getLaboratory() << " " << iter -> getTitle() << endl;
    }
    out.close();
    if(flag) {cout << "修改成功！\n";  return;}
    out.open("教师.txt", ios::out);
    for(auto iter:teacher)
    {
        if(iter -> getId() == aid)
        {
            iter -> show(), cout << "\n\n根据提示输入修改信息\n\n";
            while(iter -> change())
            {
                
                iter -> show();
                cout << "输入非法，请重新输入\n";
            }
            flag = 1;
        }
        out << iter -> getName() << " " << iter -> getSex() << " ";
        out << iter -> getAge() << " " << iter -> getId() << " ";
        out << iter -> getDepartment() << " " << iter -> getProfession() << " " << iter -> getTitle() << endl;
    }
    out.close();
    if(flag) {cout << "修改成功！\n";  return;}
    out.open("行政人员.txt", ios::out);
    for(auto iter:administrator)
    {
        if(iter -> getId() == aid)
        {
            iter -> show(), cout << "\n\n根据提示输入修改信息\n\n";
            while(iter -> change())
            {
                
                iter -> show();
                cout << "输入非法，请重新输入\n";
            }
            flag = 1;
        }
        out << iter -> getName() << " " << iter -> getSex() << " ";
        out << iter -> getAge() << " " << iter -> getId() << " ";
        out << iter -> getPosition() << endl;
    }
    out.close();
    if(flag) {cout << "修改成功！\n";  return;}
    out.open("教师&行政人员.txt", ios::out);
    for(auto iter:teaadmi)
    {
        if(iter -> getId() == aid)
        {
            iter -> show(), cout << "\n\n根据提示输入修改信息\n\n";
            while(iter -> change())
            {
                
                iter -> show();
                cout << "输入非法，请重新输入\n";
            }
            flag = 1;
        }
        out << iter -> getName() << " " << iter -> getSex() << " ";
        out << iter -> getAge() << " " << iter -> getId() << " ";
        out << iter -> getDepartment() << " " << iter -> getProfession() << " " << iter -> getTitle() << " ";
        out << iter -> getPosition() << endl;
    }
    out.close();
    cout << "修改成功！\n";
    
}
 

bool queryInformation() //查询函数
{
    
    cout << "输入目标姓名或编号以查询\n";
    string aid;
    cin >> aid;
    multimap<string, People *>::iterator beg, en, iter;
    beg = sear.lower_bound(aid);
    en = sear.upper_bound(aid);
 
    if(beg == en)
    {
        cout << "查询结果为空\n";
        
        return 0;
    }
    for(iter = beg; iter != en; ++iter)
    {
        iter -> second -> show();
        cout << endl;
    }
    return 1;
}
 

void browseInformation() //浏览函数
{
    
    cout << "===================实验员===================\n";
    cout << "姓名   " <<"性别   " << "年龄    " << "编号\t      " << "实验室名称  " << "职务"<< endl;
    for(auto iter:tester) iter -> showRow();
 
 
    cout << "\n==================行政人员==================\n";
    cout << "姓名   " <<"性别   " << "年龄    " << "编号\t      "  << "职务\n";
    for(auto iter:administrator) iter -> showRow();
 
 
    cout << "\n=====================教师===================\n";
    cout << "姓名   " <<"性别   " << "年龄    " << "编号\t      " << "院系\t " << "专业\t         " << "职称\n";
    for(auto iter:teacher) iter -> showRow();
 
 
    cout << "\n=================行政人员&教师==============\n";
    cout << "姓名   " <<"性别   " << "年龄    " << "编号\t      " << "职务\t  " << "院系\t     " << "专业\t     " << "职称\n";
    for(auto iter:teaadmi) iter -> showRow();
}
 

void countInformation() //统计信息
{
    
    cout << "员工总人数:\t\t" << People::getPersonSum() << endl;
    cout << "男性人数:\t\t" << People::getManSum() << endl;
    cout << "女性人数:\t\t" << People::getWomanSum() << endl;
    cout << "教师人数:\t\t" << Teacher::getTeacherSum() << endl;
    cout << "实验员人数:\t\t" << Tester::getTesterSum() << endl;
    cout << "行政管理人员人数:\t" << Administrator::getAdministratorSum() << endl;
    cout << "行政管理人员&教师人数:\t" << TeaAdmi::getTeaadmiSum() << endl;
    
}
 

#endif // MYFUN_H_INCLUDED