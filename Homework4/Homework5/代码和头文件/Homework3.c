#include <stdio.h>
#include <stdlib.h>
#include "Homework3.h"

void gender(int num){
    if(num < 128)
        printf("\t�� ");
    else
        printf("\tŮ ");
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
            "\t|a:������Ϣ����ϵͳ                                      |\t\n"
            "\t|                                                        |\t\n"
            "\t|b:15+�˷���                                             |\t\n"
            "\t|                                                        |\t\n"
            "\t|q:�˳�����                                              |\t\n"
            "\t|________________________________________________________|\t\n\n"
    );
    printf("\t������������еĲ���(ֻ�е�һ����ĸ��Ч)��");
    scanf(" %c",&ch);
    while((temp = getchar())!='\n')continue;
    //������
    while(ch!='q' && (ch < 'a' || ch > 'b'))
    {
        printf("\t��������: '%c' ����!���������룺",ch);
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
                printf("\t���������֣�");
                easy_manage();
                printf("\t��Enter������...");
                getchar();
                break;
            }
            case 'b':{
                printf("\n");
                for_apply();
                printf("\n");
                printf("\t��Enter������...");
                getchar();
                break;
            }
        };
        getchar();
        system("cls");
    }
    printf("\tлл����ʹ�ã�\n\tף��������죬лл\n");
    getchar();
    return 0;
}
