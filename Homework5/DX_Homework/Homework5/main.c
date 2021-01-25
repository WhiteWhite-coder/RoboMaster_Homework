#include <stdio.h> 
#include <stdlib.h>
#include "SqStack.h"
#include "Homework3.h"

int menu_first()
{
    int choose = 0;
    printf("****************** MENU ******************\n");
    printf("\t1 --- ��һ����ҵ\n");
    printf("\t2 --- �ڶ�����ҵ\n");
    printf("\t3 --- ����\n");//
    printf("******************************************\n");
    printf("\t����������ִ�еĲ���(1--3):");

    int i;
    scanf("%d", &choose);
    rewind(stdin);

    for (i = 0; choose < 1 || choose >3; i++) {
        printf("\t������һ����ȷ����ֵ:");
        scanf("%d", &choose);
        rewind(stdin);
        if (i == 3) {
            printf("\t�һ������ڶ����棬�ʴ˷��ؽ���\n");
            break;
        }
    }
    return choose;
}

int main()
{
	SqStack* S = (SqStack*)malloc(sizeof(SqStack));
	int flag_first = 1;//��һȦ�ı�־
	int choose_first = 0;//��һȦ��ѡ��
	int flag = 1;//��־
	int choose = 0;//ѡ��
	int num = 0;//���ݸ���
	int value = 0;//��ֵ
	int length = 0;//����
	int e = 0;

	do {
        choose_first = menu_first();
        system("cls");//����
        switch (choose_first) {
            case 1:
                Homework3();
                break;
            case 2:
                do {
                    choose = menu();
                    switch (choose) {
                        case 1:printf("\t������Ҫ����ջ�Ĵ�С:");
                            scanf("%d", &num);
                            initStack(S, num);

                            printf("\t��������:");
                            for (int i = 0; i < num; i++) {
                                scanf("%d", &value);
                                pushStack(S, value);
                            }
                            printf("\t����ջ�ɹ�\n");
                            traverseSqStack(S);
                            break;
                        case 2:
                            if (S->top == -2) {
                                printf("\tջ��δ���������ȴ���ջ\n");
                            } else if (S->top == -1) {
                                printf("\tջΪ�գ��������Ԫ��\n");
                            } else {
                                clearStack(S);
                                printf("\tջ��ճɹ�\n");
                            }
                            break;
                        case 3:
                            if (S->top == -2) {
                                printf("\tջ��δ���������ȴ���ջ\n");
                            } else {
                                destroyStack(S);
                                printf("\tջ���ٳɹ�\n");
                            }
                            break;
                        case 4:
                            if (S->top == -2) {
                                printf("\tջ��δ���������ȴ���ջ\n");
                            } else {
                                printf("\t��������:");
                                scanf("%d", &value);
                                pushStack(S, value);
                                traverseSqStack(S);
                            }
                            break;
                        case 5:
                            if (S->top == -2) {
                                printf("\tջ��δ���������ȴ���ջ\n");
                            } else if (S->top == -1) {
                                printf("\tջΪ�գ��������Ԫ��\n");
                            } else {
                                popStack(S, &value);//��ջ
                                traverseSqStack(S);
                            }
                            break;
                        case 6:
                            if (S->top == -2) {
                                printf("\tջ��δ���������ȴ���ջ\n");
                            } else {
                                printf("\tջ�շ�%d(1:�� 0:��)\n", isEmptyStack(S));
                            }
                            break;
                        case 7:
                            if (S->top == -2) {
                                printf("\tջ��δ���������ȴ���ջ\n");
                            } else if (S->top == -1) {
                                printf("\tջΪ�գ��������Ԫ��\n");
                            } else {
                                getTopStack(S, &e);
                                printf("\tջ��Ԫ��:%d\n", e);
                            }
                            break;
                        case 8:
                            if (S->top == -2) {
                                printf("\tջ��δ���������ȴ���ջ\n");
                            } else if (S->top == -1) {
                                printf("\tջΪ�գ��������Ԫ��\n");
                            } else {
                                stackLength(S, &length);//���ջ����
                                printf("\tջ����:%d\n", length);
                            }
                            break;
                        case 9:flag = 0;
                            system("cls");//����
                    }
                } while (flag);
                break;
            case 3:flag_first = 0;
                system("cls");//����
            }
	} while(flag_first);

	return 0;
}
