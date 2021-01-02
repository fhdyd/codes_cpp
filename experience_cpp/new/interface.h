#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
 
#include"teacher.h"
#include"tester.h"
#include"administrator.h"
#include"tea&admi.h"
 
#include<stdio.h>
#include<stdlib.h>
 
void interfaceManager();        //管理者界面
 
#include"myfun.h"
 
 
void interfaceManager() //管理界面
{
    int n=1;
    while(n)
    {
        
	    cout<<"==============================================================="<<endl;
	    cout<<"            欢迎使用南京信息工程大学人员管理系统"<<endl;
	    cout<<"==============================================================="<<endl;
        cout << "===========              输入1 添加信息              ==========\n";
        cout << "===========              输入2 查询信息              ==========\n";
        cout << "===========              输入3 浏览信息              ==========\n";
        cout << "===========              输入4 修改信息              ==========\n";
        cout << "===========              输入5 删除信息              ==========\n";
        cout << "===========              输入6 统计信息              ==========\n";
        cout << "===========              输入0 返回上一级            ==========\n";
        cout << "===============================================================\n";
        cout << "===============================================================\n";
        cout << "输入你的选择：";
        cin >> n;
        switch(n)
        {
            case 1:addInformation();break;
            case 2:
            {
                int a = 1;
                if(!queryInformation()) break;
                while(a)
                {
                    cout << "输入1 修改信息\n";
                    cout << "输入2 删除信息\n";
                    cout << "输入0 返回上一级\n";
                    cin >> a;
                    switch(a)
                    {
                        case 1:editInformation(); a = 0; break;
                        case 2:deleteInformation(); a= 0; break;
                    }
                }
                break;
            }
            case 3:
            {
                int a=1;
                while(a)
                {
                    browseInformation();
                    cout << "输入1 修改信息\n";
                    cout << "输入2 删除信息\n";
                    cout << "输入0 返回上一级\n";
                    cin >> a;
                    switch(a)
                    {
                        case 1:editInformation(); break;
                        case 2:deleteInformation(); break;
                    }
                }
                break;
            }
            case 4:editInformation(); break;
            case 5:deleteInformation(); break;
            case 6:countInformation(); break;
        }
    }
}
 


 
#endif // INTERFACE_H_INCLUDED