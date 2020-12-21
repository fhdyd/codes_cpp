#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
 
#include"teacher.h"
#include"tester.h"
#include"administrator.h"
#include"tea&admi.h"
 
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
 
/*----------------函数声明-------------------*/
 
void interface_login();          //初始界面
void interface_Manager();        //管理者界面
void staff_list();               //管理者清单
 
#include"myfun.h"
 
/*----------------函数定义-------------------*/
 
void interface_Manager() //管理界面
{
    int n=1;
    while(n)
    {
        system("cls");
        std::cout << "------------欢迎来到只有神知道的领域 o(*≧▽≦)ツ----------\n";
        std::cout << "-----------------------------------------------------------\n";
        std::cout << "-----------------------------------------------------------\n";
        std::cout << "-------------     输入1 添加信息              -------------\n";
        std::cout << "-------------     输入2 查询信息              -------------\n";
        std::cout << "-------------     输入3 浏览信息              -------------\n";
        std::cout << "-------------     输入4 修改信息              -------------\n";
        std::cout << "-------------     输入5 删除信息              -------------\n";
        std::cout << "-------------     输入6 统计信息              -------------\n";
        std::cout << "-------------     输入0 返回上一级            -------------\n";
        std::cout << "-----------------------------------------------------------\n";
        std::cout << "-----------------------------------------------------------\n";
        std::cin >> n;
        switch(n)
        {
            case 1:Add_information();break;
            case 2:
            {
                int a = 1;
                if(!Query_information()) break;
                while(a)
                {
                    std::cout << "输入1 修改信息\n";
                    std::cout << "输入2 删除信息\n";
                    std::cout << "输入0 返回上一级\n";
                    std::cin >> a;
                    switch(a)
                    {
                        case 1:Edit_information(); a = 0; break;
                        case 2:Delete_information(); a= 0; break;
                    }
                }
                break;
            }
            case 3:
            {
                int a=1;
                while(a)
                {
                    Browse_information();
                    std::cout << "输入1 修改信息\n";
                    std::cout << "输入2 删除信息\n";
                    std::cout << "输入0 返回上一级\n";
                    std::cin >> a;
                    switch(a)
                    {
                        case 1:Edit_information(); break;
                        case 2:Delete_information(); break;
                    }
                }
                break;
            }
            case 4:Edit_information(); break;
            case 5:Delete_information(); break;
            case 6:count_information(); break;
        }
    }
}
 
void interface_login() //登入界面
{
    int n=1;
    while(n)
    {
        system("cls");
        std::cout << "----------欢迎进入高校人员信息管理系统 o(*≧▽≦)ツ--------\n";
        std::cout << "-----------------------------------------------------------\n";
        std::cout << "-----------------------------------------------------------\n";
        std::cout << "-------------     输入1 管理员账号登入        -------------\n";
        std::cout << "-------------     输入2 查询信息              -------------\n";
        std::cout << "-------------     输入3 浏览信息              -------------\n";
        std::cout << "-------------     输入4 统计信息              -------------\n";
        std::cout << "-------------     输入5 观看制作信息          -------------\n";
        std::cout << "-------------     输入0 关闭系统              -------------\n";
        std::cout << "-----------------------------------------------------------\n";
        std::cout << "-----------------------------------------------------------\n";
        std::cin >> n;
        switch(n)
        {
            case 1:login(); break;
            case 2:if(Query_information()) std::cout << "输入任意键，返回上一级\n", getch(); break;
            case 3:Browse_information(); std::cout << "输入任意键，返回上一级\n"; getch(); break;
            case 4:count_information(); break;
            case 5:staff_list(); break;
        }
    }
}
 
void staff_list() //制作人员名单
{
    system("cls");
    std::cout << "-----------------------------------------------------------\n";
    std::cout << "-----------------------------------------------------------\n";
    std::cout << "--------------Include the following members----------------\n";
    std::cout << "--------------           wzy               ----------------\n";
    std::cout << "--------------           ToRe              ----------------\n";
    std::cout << "-----------------------------------------------------------\n";
    std::cout << "-----------------------------------------------------------\n\n\n";
    std::cout << "\n输入任意键返回主菜单…\n";
    getch();
}
 
#endif // INTERFACE_H_INCLUDED