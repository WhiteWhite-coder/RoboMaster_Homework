#include <stdio.h> 
#include <stdlib.h>
#include "SqStack.h"

/*typedef struct SqStack
{
	ElemType* elem;
	int top;
	int size;
} SqStack;   *///����鿴

void visit(ElemType e)
{
    printf("%d ", e);
}

//��ʼ��ջ
Status initStack(SqStack* s, int sizes)
{
	s->elem = (ElemType*)malloc(sizes * sizeof(ElemType));//��������
	if (s->elem == NULL)//�д�������ɹ����
	{
		return ERROR;
	}
	s->top = -1;//��ʼ��ջ��
	s->size = sizes;//��ʼ����С
	return SUCCESS;
}
//�ж�ջ�Ƿ�Ϊ��
Status isEmptyStack(SqStack* s)
{
	if (s->top == -1) {
		return SUCCESS;
	}
	else {
		return ERROR;
	}
}
//�õ�ջ��Ԫ��
Status getTopStack(SqStack* s, ElemType* e)
{
	if (s == NULL || s->top == NULL) {//�п�
		return ERROR;
	}
	else {
		*e = s->elem[s->top];//��ȡջ��Ԫ��
		return SUCCESS;
	}
}
//���ջ
Status clearStack(SqStack* s)
{
	s->top = -1;
	return SUCCESS;
}
//����ջ
Status destroyStack(SqStack* s)
{
	if (s == NULL) {//�п�
		return ERROR;
	}
	s->top = -2;
	return SUCCESS;
}
//���ջ����
Status stackLength(SqStack* s, int* length)
{
	if (s == NULL) {//�п�
		*length = 0;//�ռ�Ϊ0
		return ERROR;
	}
	else {
		*length = s->top + 1;//+1��Ϊ��ǰ����
		return SUCCESS;
	}
}
//��ջ
Status pushStack(SqStack* s, ElemType data)
{
	if (s == NULL || s->top > s->size) {//�п�����
		return ERROR;
	}
	s->top++;//Ԫ�ظ���+1��
	s->elem[s->top] = data;//Ԫ�ظ���ջ��
	return SUCCESS;
}
//��ջ
Status popStack(SqStack* s, ElemType* data)
{
	if (s == NULL || s->top == -1) {//�п�
		return ERROR;
	}
	*data = s->elem[s->top];//ջ��Ԫ�ظ���data
	s->top--;//Ԫ�ظ���-1
	return SUCCESS;
}
//��ӡ
Status traverseSqStack(SqStack* s)
{
	int l = s->top;//l���ڷ�ֹs->top�䶯
	while (l != -1) {//���Ƿ�Ϊ���
		if ((l - 1) != -1) {//����һ���Ƿ�Ϊ���
			visit(s->elem[l]);
			printf("->");
		}
		else {
			visit(s->elem[l]);
		}
		l--;//����
	}
	printf("\n");
	return SUCCESS;
}

int menu()
{
	int choose = 0;
	printf("****************** MENU ******************\n");
	printf("\t1 --- ����ջ\n");
	printf("\t2 --- ���ջ\n");
	printf("\t3 --- ����ջ\n");
	printf("\t4 --- ��ջ\n");
	printf("\t5 --- ��ջ\n");
	printf("\t6 --- �ж�ջ�Ƿ�Ϊ��\n");
	printf("\t7 --- �õ�ջ��Ԫ��\n");
	printf("\t8 --- ���ջ����\n");
	printf("\t9 --- ����\n");//
	printf("******************************************\n");
	printf("\t����������ִ�еĲ���(1--9):");

	int i;
	scanf("%d", &choose);
	rewind(stdin);

	for (i = 0; choose < 1 || choose >9; i++) {
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
