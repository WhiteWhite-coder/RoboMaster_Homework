#include <stdio.h>
#include <stdlib.h>
#include "Homework3.h"

void gender(int num){
    if(num < 128)
        printf("\t男 ");
    else
        printf("\t女 ");
}

void student_id(int num){
    if(num < 128) {
        printf("%d\n",num);
    }
    else {
        printf("%d\n",num - 128);

    }
}

void easy_manage(){
    int num = 0;
    int information[8] = {0};
    while(scanf("%d",&num) != EOF) {
        if(num >= 0 && num <= 255) {
            //transform10_2(num,information);
            //gender(information);
            //student_id(information);

            gender(num);
            student_id(num);
            break;
        }
        else {
            break;
        }
    }
}

void for_apply(){
    for (int i = 15; i < 100; i = i + 10) {
        for (int j = 15; j < 100; j = j + 10) {
            if (i < j) {
                continue;
            }
            printf("%d*%d=%d ",i,j,i*j);
        }
        printf("\n");
    }
}

char init()
{
    char ch,temp;
    printf(

            "\n\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\t\n"
            "\t|a:简易信息管理系统                                      |\t\n"
            "\t|                                                        |\t\n"
            "\t|b:15+乘法表                                             |\t\n"
            "\t|                                                        |\t\n"
            "\t|q:退出程序                                              |\t\n"
            "\t|________________________________________________________|\t\n\n"
    );
    printf("\t请输入你想进行的操作(只有第一个字母有效)：");
    scanf(" %c",&ch);
    while((temp = getchar())!='\n')continue;
    //输入检测
    while(ch!='q' && (ch < 'a' || ch > 'b'))
    {
        printf("\t您的输入: '%c' 有误!请重新输入：",ch);
        scanf(" %c",&ch);
        while((temp = getchar())!='\n')continue;
    }
    return ch;
}

int Homework3() {
    char ch;

    while((ch = init()) && ch != 'q')
    {
        switch(ch){
            case 'a':{
                printf("\t请输入数字：");
                easy_manage();
                printf("\t按Enter键继续...");
                getchar();
                break;
            }
            case 'b':{
                printf("\n");
                for_apply();
                printf("\n");
                printf("\t按Enter键继续...");
                getchar();
                break;
            }
        };
        getchar();
        system("cls");
    }
    printf("\t谢谢您的使用！\n\t祝您生活愉快，谢谢\n");
    getchar();
    return 0;
}
