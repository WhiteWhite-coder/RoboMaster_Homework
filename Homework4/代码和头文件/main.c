//
// Created by 吴淼杰 on 2021/1/19.
//

#include <stdio.h>
#include <stdlib.h>
#include "AQueue.h"

int main()
{
    AQueue* Q = (AQueue*)malloc(sizeof(AQueue));
    int choice;
    while ((choice = menu()) && choice != 10)
    {
        printf("\n\t程序在进行\n");
        choose(choice,Q);
    }
    printf("\n\t程序结束，感谢您的使用谢谢\n");
    system("pause");
    return 0;
}
