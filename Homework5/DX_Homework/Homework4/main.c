#include <stdio.h> 
#include <stdlib.h>
#include "SqStack.h"

int main()
{
	SqStack* S = (SqStack*)malloc(sizeof(SqStack));
	int flag = 1;//标志
	int choose = 0;//选择
	int num = 0;//数据个数
	int value = 0;//数值
	int length = 0;//长度
	int e = 0;

	do {
		choose = menu();
		switch (choose) {
		case 1:
			printf("\t请输入要创建栈的大小:");
			scanf("%d", &num);
			initStack(S, num);

			printf("\t输入数据:");
			for (int i = 0; i < num; i++) {
				scanf("%d", &value);
				pushStack(S, value);
			}
			printf("\t创建栈成功\n");
			traverseSqStack(S);
			break;
		case 2:
			if (S->top == -2) {
				printf("\t栈还未创建，请先创建栈\n");
			}
			else if (S->top == -1) {
				printf("\t栈为空，请先添加元素\n");
			}
			else {
				clearStack(S);
				printf("\t栈清空成功\n");
			}
			break;
		case 3:
			if (S->top == -2) {
				printf("\t栈还未创建，请先创建栈\n");
			}
			else {
				destroyStack(S);
				printf("\t栈销毁成功\n");
			}
			break;
		case 4:
			if (S->top == -2) {
				printf("\t栈还未创建，请先创建栈\n");
			}
			else {
				printf("\t输入数据:");
				scanf("%d", &value);
				pushStack(S, value);
				traverseSqStack(S);
			}
			break;
		case 5:
			if (S->top == -2) {
				printf("\t栈还未创建，请先创建栈\n");
			}
			else if (S->top == -1) {
				printf("\t栈为空，请先添加元素\n");
			}
			else {
				popStack(S, &value);//出栈
				traverseSqStack(S);
			}
			break;
		case 6:
			if (S->top == -2) {
				printf("\t栈还未创建，请先创建栈\n");
			}
			else {
				printf("\t栈空否：%d(1:空 0:否)\n", isEmptyStack(S));
			}
			break;
		case 7:
			if (S->top == -2) {
				printf("\t栈还未创建，请先创建栈\n");
			}
			else if (S->top == -1) {
				printf("\t栈为空，请先添加元素\n");
			}
			else {
				getTopStack(S, &e);
				printf("\t栈顶元素:%d\n", e);
			}
			break;
		case 8:
			if (S->top == -2) {
				printf("\t栈还未创建，请先创建栈\n");
			}
			else if (S->top == -1) {
				printf("\t栈为空，请先添加元素\n");
			}
			else {
				stackLength(S, &length);//检测栈长度
				printf("\t栈长度:%d\n", length);
			}
			break;
		case 9:
			flag = 0;
			system("cls");//清屏
		}
	} while (flag);
	return 0;
}
