#include <stdio.h> 
#include <stdlib.h>
#include "SqStack.h"

int main()
{
	SqStack* S = (SqStack*)malloc(sizeof(SqStack));
	int flag = 1;//��־
	int choose = 0;//ѡ��
	int num = 0;//���ݸ���
	int value = 0;//��ֵ
	int length = 0;//����
	int e = 0;

	do {
		choose = menu();
		switch (choose) {
		case 1:
			printf("\t������Ҫ����ջ�Ĵ�С:");
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
			}
			else if (S->top == -1) {
				printf("\tջΪ�գ��������Ԫ��\n");
			}
			else {
				clearStack(S);
				printf("\tջ��ճɹ�\n");
			}
			break;
		case 3:
			if (S->top == -2) {
				printf("\tջ��δ���������ȴ���ջ\n");
			}
			else {
				destroyStack(S);
				printf("\tջ���ٳɹ�\n");
			}
			break;
		case 4:
			if (S->top == -2) {
				printf("\tջ��δ���������ȴ���ջ\n");
			}
			else {
				printf("\t��������:");
				scanf("%d", &value);
				pushStack(S, value);
				traverseSqStack(S);
			}
			break;
		case 5:
			if (S->top == -2) {
				printf("\tջ��δ���������ȴ���ջ\n");
			}
			else if (S->top == -1) {
				printf("\tջΪ�գ��������Ԫ��\n");
			}
			else {
				popStack(S, &value);//��ջ
				traverseSqStack(S);
			}
			break;
		case 6:
			if (S->top == -2) {
				printf("\tջ��δ���������ȴ���ջ\n");
			}
			else {
				printf("\tջ�շ�%d(1:�� 0:��)\n", isEmptyStack(S));
			}
			break;
		case 7:
			if (S->top == -2) {
				printf("\tջ��δ���������ȴ���ջ\n");
			}
			else if (S->top == -1) {
				printf("\tջΪ�գ��������Ԫ��\n");
			}
			else {
				getTopStack(S, &e);
				printf("\tջ��Ԫ��:%d\n", e);
			}
			break;
		case 8:
			if (S->top == -2) {
				printf("\tջ��δ���������ȴ���ջ\n");
			}
			else if (S->top == -1) {
				printf("\tջΪ�գ��������Ԫ��\n");
			}
			else {
				stackLength(S, &length);//���ջ����
				printf("\tջ����:%d\n", length);
			}
			break;
		case 9:
			flag = 0;
			system("cls");//����
		}
	} while (flag);
	return 0;
}
