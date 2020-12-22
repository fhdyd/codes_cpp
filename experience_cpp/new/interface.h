#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
 
#include"teacher.h"
#include"tester.h"
#include"administrator.h"
#include"tea&admi.h"
 
#include<stdio.h>
#include<stdlib.h>
 
/*===========---函数声明===========------*/
 
//void interface_login();          //初始界面
void interface_Manager();        //管理者界面
void staff_list();               //管理者清单
 
#include"myfun.h"
 
/*===========---函数定义===========------*/
 
void interface_Manager() //管理界面
{
    int n=1;
    while(n)
    {
        
	    std::cout<<"==============================================================="<<std::endl;
	    std::cout<<"欢迎使用南京信息工程大学学生管理系统"<<std::endl;
	    std::cout<<"==============================================================="<<std::endl;
        std::cout << "==============     输入1 添加信息              ===================\n";
        std::cout << "==============     输入2 查询信息              ===================\n";
        std::cout << "==============     输入3 浏览信息              ===================\n";
        std::cout << "==============     输入4 修改信息              ===================\n";
        std::cout << "==============     输入5 删除信息              ===================\n";
        std::cout << "==============     输入6 统计信息              ===================\n";
        std::cout << "==============     输入0 返回上一级            ===================\n";
        std::cout << "=============================================================\n";
        std::cout << "=============================================================\n";
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
 


 
#endif // INTERFACE_H_INCLUDED