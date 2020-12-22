#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;
/*
某高校有四类员工：教师、实验员、行政人员，教师兼行政人员；
共有的信息包括：编号、姓名、性别、年龄等。其中，
教师还包含的信息有：所在系部、专业、职称；
实验员还包含的信息由：所在实验室、职务；
行政人员还包含的信息有：政治面貌、职称等。
*/
class person
{
public:
    string id, name, sex, age;
};

class teacher :public person
{
public:
    string department, professional, rank;
};

class assistant :public person
{
public:
    string lab, work;
};

class staff :public person
{
public:
    string  political_status, rank;
};

class tstaff :public person
{
public:
    string  political_status, department, professional, rank;
};

/*
教师包含的信息有：编号、姓名、性别、年龄、所在系部、专业、职称；
实验员包含的信息由：编号、姓名、性别、年龄、所在实验室、职务；
行政人员包含的信息有：编号、姓名、性别、年龄、政治面貌、职称等。
教师兼行政人员包含的信息有：编号、姓名、性别、年龄、政治面貌、所在系部、专业、职称
若需要修改请按照上述格式输入，中间以一个空格隔开。
*/

class System
{
public:
    vector<teacher>tea;
    vector<assistant>ass;
    vector<staff>sta;
    vector<tstaff>tst;
    /*
    （1）添加功能：程序能够任意添加上述四类人员的记录，可提供选择界面供用户选择所要添加的人员类别，要求员工的编号要唯一，如果添加了重复编号的记录时，则提示数据添加重复并取消添加。
    （2）查询功能：可根据编号、姓名等信息对已添加的记录进行查询，如果未找到，给出相应的提示信息，如果找到，则显示相应的记录信息。
    （3）显示功能：可显示当前系统中所有记录，每条记录占据一行。
    （4）编辑功能：可根据查询结果对相应的记录进行修改，修改时注意编号的唯一性。
    （5）删除功能：主要实现对已添加的人员记录进行删除。如果当前系统中没有相应的人员记录，则提示“记录为空！”并返回操作；否则，输入要删除的人员的编号或姓名，根据所输入的信息删除该人员记录，如果没有找到该人员信息，则提示相应的记录不存。
    （6）统计功能：能根据多种参数进行人员的统计。能统计四类人员数量以及总数，
    统计男、女员工的数量。
    （7）保存功能：可将当前系统中各类人员记录存入文件中，存入方式任意。
    （8）读取功能：可将保存在文件中的人员信息读入到当前系统中，供用户进行使用。
    */
    void add(teacher t)
    {
        tea.push_back(t);
    }
    void add(assistant t)
    {
        ass.push_back(t);
    }
    void add(staff t)
    {
        sta.push_back(t);
    }
    void add(tstaff t)
    {
        tst.push_back(t);
    }
    void Add()
    {
        system("cls");
        cout << "/---------------高校人员信息管理系统---------------\\\n";
        cout << "|                                                  |\n";
        cout << "|                   0.添加功能                     |\n";
        cout << "|                                                  |\n";
        cout << "\\--------------------------------------------------/\n";
        cout << "教师包含的信息有：编号、姓名、性别、年龄、所在系部、专业、职称；\n";
        cout << "实验员包含的信息由：编号、姓名、性别、年龄、所在实验室、职务；\n";
        cout << "行政人员包含的信息有：编号、姓名、性别、年龄、政治面貌、职称等。\n";
        cout << "教师兼行政人员包含的信息有：编号、姓名、性别、年龄、政治面貌、所在系部、专业、职称\n";
        cout << "若需要添加请按照上述顺序输入，中间以一个空格隔开。\n\n";
        cout << "输入待添加人员类型：1.教师 2.实验员 3.行政人员 4.教师兼行政人员 0.放弃添加:";
        string a;
        cin >> a;
        if (a == "1")
        {
            teacher b;
            cin >> b.id >> b.name >> b.sex >> b.age >> b.department >> b.professional >> b.rank;
            if (search(b.id))
            {
                add(b);
                cout << "信息录入成功！" << endl;
            }
            else
                cout << "ID重复，录入失败" << endl;
        }
        else if (a == "2")
        {
            assistant b;
            cin >> b.id >> b.name >> b.sex >> b.age >> b.lab >> b.work;
            if (search(b.id))
            {
                add(b);
                cout << "信息录入成功！" << endl;
            }
            else
                cout << "ID重复，录入失败" << endl;
        }
        else if (a == "3")
        {
            staff b;
            cin >> b.id >> b.name >> b.sex >> b.age >> b.political_status >> b.rank;
            if (search(b.id))
            {
                add(b);
                cout << "信息录入成功！" << endl;
            }
            else
                cout << "ID重复，录入失败" << endl;
        }
        else if (a == "4")
        {
            tstaff b;
            cin >> b.id >> b.name >> b.sex >> b.age >> b.political_status >> b.department >> b.professional >> b.rank;
            if (search(b.id))
            {
                add(b);
                cout << "信息录入成功！" << endl;
            }
            else
                cout << "ID重复，录入失败" << endl;
        }
        system("pause");
    }
    bool search(string id)
    {
        for (auto i : tea)
            if (i.id == id)
                return 0;
        for (auto i : sta)
            if (i.id == id)
                return 0;
        for (auto i : ass)
            if (i.id == id)
                return 0;
        for (auto i : tst)
            if (i.id == id)
                return 0;
        return 1;
    }
    void find(string t)
    {
        system("cls");
        cout << "/---------------高校人员信息管理系统---------------\\\n";
        cout << "|                                                  |\n";
        cout << "|                   查询编辑功能                   |\n";
        cout << "|                                                  |\n";
        cout << "\\--------------------------------------------------/\n";
        cout << "教师包含的信息有：编号、姓名、性别、年龄、所在系部、专业、职称；\n";
        cout << "实验员包含的信息由：编号、姓名、性别、年龄、所在实验室、职务；\n";
        cout << "行政人员包含的信息有：编号、姓名、性别、年龄、政治面貌、职称等。\n";
        cout << "教师兼行政人员包含的信息有：编号、姓名、性别、年龄、政治面貌、所在系部、专业、职称\n";
        cout << "若需要修改请按照上述顺序输入，中间以一个空格隔开。\n\n";

        for (auto &i : tea)
            if (i.id == t || i.name == t)
            {
                cout << "找到目标。" << endl;
                cout << "目标信息为:" << endl;
                cout << i.id << " " << i.name << " " << i.sex << " " << i.age << " " << i.department << " " << i.professional << " " << i.rank << endl;
                cout << "请问是否需要修改?(1.是 2.否)" << endl;
                string a;
                cin >> a;
                if (a == "1")
                {
                    cout << "请依次输入信息:" << endl;
                    teacher b;
                    cin >> b.id >> b.name >> b.sex >> b.age >> b.department >> b.professional >> b.rank;
                    i = b;
                    cout << "信息录入成功！" << endl;
                }
                system("pause");
                return;
            }
        for (auto &i : ass)
            if (i.id == t || i.name == t)
            {
                cout << "找到目标。" << endl;
                cout << "目标信息为:" << endl;
                cout << i.id << " " << i.name << " " << i.sex << " " << i.age << " " << i.lab << " " << i.work << endl;;
                cout << "请问是否需要修改?(1.是 2.否)" << endl;
                string a;
                cin >> a;
                if (a == "1")
                {
                    cout << "请依次输入信息:" << endl;
                    assistant b;
                    cin >> b.id >> b.name >> b.sex >> b.age >> b.lab >> b.work;
                    i = b;
                    cout << "信息录入成功！" << endl;
                }
                system("pause");
                return;
            }
        for (auto &i : sta)
            if (i.id == t || i.name == t)
            {
                cout << "找到目标。" << endl;
                cout << "目标信息为:" << endl;
                cout << i.id << " " << i.name << " " << i.sex << " " << i.age << " " << i.political_status << " " << i.rank << endl;
                cout << "请问是否需要修改?(1.是 2.否)" << endl;
                string a;
                cin >> a;
                if (a == "1")
                {
                    cout << "请依次输入信息:" << endl;
                    staff b;
                    cin >> b.id >> b.name >> b.sex >> b.age >> b.political_status >> b.rank;
                    i = b;
                    cout << "信息录入成功！" << endl;
                }
                system("pause");
                return;
            }
        for (auto &i : tst)
            if (i.id == t || i.name == t)
            {
                cout << "找到目标。" << endl;
                cout << "目标信息为:" << endl;
                cout << i.id << " " << i.name << " " << i.sex << " " << i.age << " " << i.political_status << " " << i.department << " " << i.professional << " " << i.rank << endl;
                cout << "请问是否需要修改?(1.是 2.否)" << endl;
                string a;
                cin >> a;
                if (a == "1")
                {
                    cout << "请依次输入信息:" << endl;
                    tstaff b;
                    cin >> b.id >> b.name >> b.sex >> b.age >> b.political_status >> b.department >> b.professional >> b.rank;
                    i = b;
                    cout << "信息录入成功！" << endl;
                }
                system("pause");
                return;
            }
        cout << "未找到目标，请确认输入正确！" << endl;
        system("pause");
    }
    void output() {
        system("cls");
        cout << "/---------------高校人员信息管理系统---------------\\\n";
        cout << "|                                                  |\n";
        cout << "|                   2.显示功能                     |\n";
        cout << "|                                                  |\n";
        cout << "\\--------------------------------------------------/\n";
        cout << "教师信息" << endl;
        for (auto i : tea)
            cout << i.id << " " << i.name << " " << i.sex << " " << i.age << " " << i.department << " " << i.professional << " " << i.rank << endl;
        cout << endl;
        cout << "实验员信息" << endl;
        for (auto i : ass)
            cout << i.id << " " << i.name << " " << i.sex << " " << i.age << " " << i.lab << " " << i.work << endl;;
        cout << endl;
        cout << "行政人员信息" << endl;
        for (auto &i : sta)
            cout << i.id << " " << i.name << " " << i.sex << " " << i.age << " " << i.political_status << " " << i.rank << endl;
        cout << endl;
        cout << "教师兼行政人员信息" << endl;
        for (auto &i : tst)
            cout << i.id << " " << i.name << " " << i.sex << " " << i.age << " " << i.political_status << " " << i.department << " " << i.professional << " " << i.rank << endl;
        system("pause");
    }
    void del(string t)
    {
        system("cls");
        cout << "/---------------高校人员信息管理系统---------------\\\n";
        cout << "|                                                  |\n";
        cout << "|                   4.删除功能                     |\n";
        cout << "|                                                  |\n";
        cout << "\\--------------------------------------------------/\n";

        for (auto i = tea.begin(); i != tea.end(); ++i)
            if ((*i).id == t || (*i).name == t)
            {
                cout << "找到目标。" << endl;
                cout << "被删除目标信息为:" << endl;
                cout << (*i).id << " " << (*i).name << " " << (*i).sex << " " << (*i).age << " " << (*i).department << " " << (*i).professional << " " << (*i).rank << endl;
                tea.erase(i);
                system("pause");
                return;
            }
        for (auto i = ass.begin(); i != ass.end(); ++i)
            if ((*i).id == t || (*i).name == t)
            {
                cout << "找到目标。" << endl;
                cout << "被删除目标信息为:" << endl;
                cout << (*i).id << " " << (*i).name << " " << (*i).sex << " " << (*i).age << " " << (*i).lab << " " << (*i).work << endl;
                ass.erase(i);
                system("pause");
                return;
            }
        for (auto i = sta.begin(); i != sta.end(); ++i)
            if ((*i).id == t || (*i).name == t)
            {
                cout << "找到目标。" << endl;
                cout << "被删除目标信息为:" << endl;
                cout << (*i).id << " " << (*i).name << " " << (*i).sex << " " << (*i).age << " " << (*i).political_status << " " << (*i).rank << endl;
                sta.erase(i);
                system("pause");
                return;
            }
        for (auto i = tst.begin(); i != tst.end(); ++i)
            if ((*i).id == t || (*i).name == t)
            {
                cout << "找到目标。" << endl;
                cout << "被删除目标信息为:" << endl;
                cout << (*i).id << " " << (*i).name << " " << (*i).sex << " " << (*i).age << " " << (*i).political_status << " " << (*i).department << " " << (*i).professional << " " << (*i).rank << endl;
                tst.erase(i);
                system("pause");
                return;
            }
        cout << "未找到目标，请确认输入正确！" << endl;
        system("pause");
    }
    void calc()
    {
        string t = "男";
        system("cls");
        cout << "/---------------高校人员信息管理系统---------------\\\n";
        cout << "|                                                  |\n";
        cout << "|                   5.统计功能                     |\n";
        cout << "|                                                  |\n";
        cout << "\\--------------------------------------------------/\n";
        int cnt1 = tea.size(), cnt2 = ass.size(), cnt3 = sta.size(), cnt4 = tst.size();
        int sum = num();
        int tt = 0, yy = 0;
        for (auto i : tea)
            if (i.sex == "男")
                ++tt;
        for (auto i : ass)
            if (i.sex == "男")
                ++tt;
        for (auto i : sta)
            if (i.sex == "男")
                ++tt;
        for (auto i : tst)
            if (i.sex == "男")
                ++tt;
        cout << "教师总人数为:" << cnt1 << endl;
        cout << "实验员总人数为:" << cnt2 << endl;
        cout << "行政人员总人数为:" << cnt3 << endl;
        cout << "教师兼行政人员总人数为:" << cnt4 << endl;
        cout << "总人数为:" << sum << endl;
        cout << "男性人数为" << tt << endl;
        cout << "女性人数为:" << sum - tt << endl;
        system("pause");
    }
    void save() {
        ofstream out("data1.txt", ios::out);
        out << "教师信息" << endl;
        for (auto i : tea)
            out << i.id << " " << i.name << " " << i.sex << " " << i.age << " " << i.department << " " << i.professional << " " << i.rank << endl;
        out << endl;
        out << "实验员信息" << endl;
        for (auto i : ass)
            out << i.id << " " << i.name << " " << i.sex << " " << i.age << " " << i.lab << " " << i.work << endl;;
        out << endl;
        out << "行政人员信息" << endl;
        for (auto &i : sta)
            out << i.id << " " << i.name << " " << i.sex << " " << i.age << " " << i.political_status << " " << i.rank << endl;
        out << endl;
        out << "教师兼行政人员信息" << endl;
        for (auto &i : tst)
            out << i.id << " " << i.name << " " << i.sex << " " << i.age << " " << i.political_status << " " << i.department << " " << i.professional << " " << i.rank << endl;
        cout << "写入成功！" << endl;
        system("pause");
    }
    void read()
    {
        tea.clear();
        sta.clear();
        ass.clear();
        tst.clear();
        fstream is("data1.txt", ios::in);
        string t;
        is >> t;
        if (t == "教师信息")
        {
            teacher b;
            while (is >> b.id)
            {
                if (b.id[0] > '9' || b.id[0] < '0')
                    break;
                is >> b.name >> b.sex >> b.age >> b.department >> b.professional >> b.rank;
                tea.push_back(b);
            }
        }
        if (1)
        {
            assistant b;
            while (is >> b.id)
            {
                if (b.id[0] > '9' || b.id[0] < '0')
                    break;
                is >> b.name >> b.sex >> b.age >> b.lab >> b.work;
                ass.push_back(b);
            }
        }
        if (1)
        {
            staff b;
            while (is >> b.id)
            {
                if (b.id[0] > '9' || b.id[0] < '0')
                    break;
                is >> b.name >> b.sex >> b.age >> b.political_status >> b.rank;
                sta.push_back(b);
            }
        }
        if (1)
        {
            tstaff b;
            while (is >> b.id)
            {
                if (b.id[0] > '9' || b.id[0] < '0')
                    break;
                is >> b.name >> b.sex >> b.age >> b.political_status >> b.department >> b.professional >> b.rank;
                tst.push_back(b);
            }
        }

        is.close();
        cout << "读取成功！" << endl;
        system("pause");
    }
    int num()
    {
        return tea.size() + ass.size() + sta.size() + tst.size();
    }
};
System a;
void Main()
{
    try {
        system("cls");
        cout << endl;
        cout << "/---------------高校人员信息管理系统---------------\\\n";
        cout << "|                                                  |\n";
        cout << "|                   0.添加功能                     |\n";
        cout << "|                   1.查询功能                     |\n";
        cout << "|                   2.显示功能                     |\n";
        cout << "|                   3.编辑功能                     |\n";
        cout << "|                   4.删除功能                     |\n";
        cout << "|                   5.统计功能                     |\n";
        cout << "|                   6.读取文件                     |\n";
        cout << "|                   7.保存文件                     |\n";
        cout << "|                                                  |\n";
        cout << "\\--------------------------------------------------/\n";
        cout << endl << "请输入数字选项：";
        string T;
        cin >> T;
        int t = stoi(T);
        if (!a.num())
            if (t != 0 && t != 6)
                t = -1, cout << "数据信息为空,请先添加纪录或读取文件！\n", system("pause");
        string text;
        switch (t)
        {
        case 0:
            a.Add();
            break;
        case 1:
            cout << "请输入待查询的id或姓名：";
            cin >> text;
            a.find(text);
            break;
        case 2:
            a.output();
            break;
        case 3:
            cout << "请输入待编辑的id或姓名：";
            cin >> text;
            a.find(text);
            break;
        case 4:
            cout << "请输入待删除的id或姓名：";
            cin >> text;
            a.del(text);
            break;
        case 5:
            a.calc();
            break;
        case 6:
            a.read();
            break;
        case 7:
            a.save();
            break;
        default:
            break;
        }
        Main();
    }
    catch (exception e) {
        cout << "输入有误！程序出错！文件已保存！按任意键重新启动程序！" << endl;
        system("pause");
        a.save();
        a = System();
        Main();
    }
}
int main()
{
    Main();
    return 0;
}