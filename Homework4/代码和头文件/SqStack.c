#include <stdio.h> 
#include <stdlib.h>
#include "SqStack.h"

/*typedef struct SqStack
{
	ElemType* elem;
	int top;
	int size;
} SqStack;   *///方便查看

void visit(ElemType e)
{
    printf("%d ", e);
}

//初始化栈
Status initStack(SqStack* s, int sizes)
{
	s->elem = (ElemType*)malloc(sizes * sizeof(ElemType));//创建数组
	if (s->elem == NULL)//判创建数组成功与否
	{
		return ERROR;
	}
	s->top = -1;//初始化栈顶
	s->size = sizes;//初始化大小
	return SUCCESS;
}
//判断栈是否为空
Status isEmptyStack(SqStack* s)
{
	if (s->top == -1) {
		return SUCCESS;
	}
	else {
		return ERROR;
	}
}
//得到栈顶元素
Status getTopStack(SqStack* s, ElemType* e)
{
	if (s == NULL || s->top == NULL) {//判空
		return ERROR;
	}
	else {
		*e = s->elem[s->top];//获取栈顶元素
		return SUCCESS;
	}
}
//清空栈
Status clearStack(SqStack* s)
{
	s->top = -1;
	return SUCCESS;
}
//销毁栈
Status destroyStack(SqStack* s)
{
	if (s == NULL) {//判空
		return ERROR;
	}
	s->top = -2;
	return SUCCESS;
}
//检测栈长度
Status stackLength(SqStack* s, int* length)
{
	if (s == NULL) {//判空
		*length = 0;//空即为0
		return ERROR;
	}
	else {
		*length = s->top + 1;//+1即为当前长度
		return SUCCESS;
	}
}
//入栈
Status pushStack(SqStack* s, ElemType data)
{
	if (s == NULL || s->top > s->size) {//判空判满
		return ERROR;
	}
	s->top++;//元素个数+1；
	s->elem[s->top] = data;//元素赋予栈顶
	return SUCCESS;
}
//出栈
Status popStack(SqStack* s, ElemType* data)
{
	if (s == NULL || s->top == -1) {//判空
		return ERROR;
	}
	*data = s->elem[s->top];//栈顶元素赋予data
	s->top--;//元素个数-1
	return SUCCESS;
}
//打印
Status traverseSqStack(SqStack* s)
{
	int l = s->top;//l用于防止s->top变动
	while (l != -1) {//判是否为最后
		if ((l - 1) != -1) {//判下一个是否为最后
			visit(s->elem[l]);
			printf("->");
		}
		else {
			visit(s->elem[l]);
		}
		l--;//下移
	}
	printf("\n");
	return SUCCESS;
}

int menu()
{
	int choose = 0;
	printf("****************** MENU ******************\n");
	printf("\t1 --- 创建栈\n");
	printf("\t2 --- 清空栈\n");
	printf("\t3 --- 销毁栈\n");
	printf("\t4 --- 入栈\n");
	printf("\t5 --- 出栈\n");
	printf("\t6 --- 判断栈是否为空\n");
	printf("\t7 --- 得到栈顶元素\n");
	printf("\t8 --- 检测栈长度\n");
	printf("\t9 --- 结束\n");//
	printf("******************************************\n");
	printf("\t请输入您想执行的操作(1--9):");

	int i;
	scanf("%d", &choose);
	rewind(stdin);

	for (i = 0; choose < 1 || choose >9; i++) {
		printf("\t请输入一个正确的数值:");
		scanf("%d", &choose);
		rewind(stdin);
		if (i == 3) {
			printf("\t我怀疑你在逗我玩，故此返回界面\n");
			break;
		}
	}
	return choose;
}
