//
// Created by 吴淼杰 on 2021/1/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AQueue.h"

int ss;

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue* Q)
{
    Q->length = MAXQUEUE;//初始化长度

    for (int i = 0; i < MAXQUEUE; i++) {
        Q->data[i] = (void*)malloc(MAXQUEUE + 1);//动态分配
    }

    Q->front = 0;
    Q->rear = 0;
    ss = 1;
}

/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue* Q)
{
    ss = 0;

    if (Q->data[0] == NULL) {//判初始化
        printf("\t队列未初始化，请先进行初始化操作\n");
        return;
    }

    for (int i = 0; i < MAXQUEUE; i++) {
        free(Q->data[i]);//释放内存
    }

    Q->data[0] = NULL;//置空
}

/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue* Q)
{
    if (Q->data[0] == NULL)//判初始化
    {
        printf("\t队列未初始化，请先进行初始化操作\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q)) {//判空
        return FALSE;
    }
    if (LengthAQueue(Q) == MAXQUEUE - 1)//判满
    {
        return TRUE;
    }
        /*
        if (Q->rear + 1 % Q->length == Q->front)//判满(公式法)
        {
            return TRUE;
        }
        */
    else//不满则FALSE
        return FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue* Q)
{
    if (Q->data[0] == NULL) {//判初始化
        printf("\t队列未初始化，请先进行初始化操作\n");
        return FALSE;
    }

    return LengthAQueue(Q) == 0 ? TRUE : FALSE;//现长为0即为空
}

/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue* Q, void* e)
{
    if (Q->data[0] == NULL) {//判初始化
        printf("\t队列未初始化，请先进行初始化操作\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q))//判空
    {
        printf("\t队列为空，没有队头\n");
        return FALSE;
    }

    //memcpy(e, Q->data[Q->front], Q->length);
    switch (Q->type[Q->front])
    {
        case 1: {
            printf("\t队头元素为 %d\n", *(int*)Q->data[Q->front]);
            break;
        }
        case 2: {
            printf("\t队头元素为 %.2lf\n", *(double*)Q->data[Q->front]);
            break;
        }
        case 3: {
            printf("\t队头元素为 %c\n", *(char*)Q->data[Q->front]);
            break;
        }
    }

    return TRUE;
}

/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue* Q)
{
    return (Q->rear - Q->front + Q->length) % (Q->length);//公式
}

/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue* Q, void* data)
{
    if (Q->data[0] == NULL) {//判初始化
        printf("\t队列未初始化，请先进行初始化操作\n");
        return FALSE;
    }
    if (IsFullAQueue(Q)) {
        printf("\t队列满了，不能入队\n");
        return FALSE;
    }
    int size = 0;
    if (Q->type[Q->rear] == 1) {
        size = 4;
        //Q->data[Q->rear] = (int*)malloc(size);
    }
    if (Q->type[Q->rear] == 2) {
        size = 8;
        //Q->data[Q->rear] = (double*)malloc(size);
    }
    if (Q->type[Q->rear] == 3) {
        size = 1;
        //Q->data[Q->rear] = (char*)malloc(size);
    }
    memcpy(Q->data[Q->rear], data, size);//将data赋值给队尾
    //printf("调试展示：%c\n", *(char*)Q->data[Q->rear]);
    Q->rear = (Q->rear + 1) % Q->length;//rear位置后移一位
    return TRUE;
}

/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue* Q)
{
    if (Q->data[0] == NULL) {//判初始化
        printf("\t队列未初始化，请先进行初始化操作\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q))//判空
    {
        printf("\t队列为空,不能出队\n");
        return FALSE;
    }
    Q->front = (Q->front + 1) % Q->length;
    return TRUE;
}

/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue* Q)
{
    if (IsEmptyAQueue(Q))//判空
    {
        printf("\t队列为空\n");
        return;
    }
    Q->front = 0;
    Q->rear = 0;
    return;
}

/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : foo是什么
 */
Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q,int typeData))//一个指向任何类型变量 的 指针 的 引用
{
    if (Q->data[0] == NULL) {//判初始化
        printf("\t队列未初始化，请先进行初始化操作\n");
        return FALSE;
    }
    if (IsEmptyAQueue(Q))//判空
    {
        printf("\t队列为空\n");
        return FALSE;
    }
    int i = 0;
    while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {
        foo(Q->data[Q->front + i], Q->type[Q->front + i]);
        i = (i + 1) % MAXQUEUE;
    }
    return TRUE;
}

/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void* q, int typeData)
{
    if (typeData == 1)
        printf("--> %d ", *(int*)q);
    if (typeData == 2)
        printf("--> %.2lf", *(double*)q);
    if (typeData == 3)
        printf("--> %c", *(char*)q);
}

/**
 *  @name        : int menu()
 *    @description : 菜单初始化函数
 *    @param
 *  @notice      : None
 */
int menu()
{
    int choice;//用户选择
    printf(

        "\n\t _________________________________________________________\t\n"
        "\t|1:初始化队列                                             |\t\n"
        "\t|2:入队                                                   |\t\n"
        "\t|3:出队                                                   |\t\n"
        "\t|4:检测队列长度                                           |\t\n"
        "\t|5:判断队列是否为空                                       |\t\n"
        "\t|6:判断队列是否已满                                       |\t\n"
        "\t|7:销毁队列                                               |\t\n"
        "\t|8:清空队列                                               |\t\n"
        "\t|9:查看队列头部                                           |\t\n"
        "\t|10:退出程序                                              |\t\n"
        "\t|_________________________________________________________|\t\n\n");
    printf("\t请输入你想进行的操作(如果输入数字+字母,只会认定前头的数字)：");
    scanf("%d", &choice);
    rewind(stdin);//清空缓冲区
    //输入检测
    while (choice != 10 && (choice < 1 || choice > 9))//判断执行1-9，并且检测合法输入
    {
        printf("\t您的输入有误!请重新输入：");
        scanf_s("%d", &choice);
        rewind(stdin);//清空缓冲区
    }
    return choice;
}

/**
 *  @name        : void choose(int choice)
 *    @description : 判断操作函数
 *    @param
 *  @notice      : None
 */
void choose(int choice, AQueue* Q)
{
    int value;//用户输入数据
    switch (choice)
    {
        case 1:
            //system("cls");
            InitAQueue(Q);
            printf("\t默认创建长度为 20 的队列成功\n");
            //system("cls");
            break;
        case 2: {
            //system("cls");
            if (ss == 0) {
                printf("\t队列未初始化，请先进行初始化操作\n");
                break;
            }
            else {
                int type2 = chooseType(Q);
                switch (type2)
                {
                    case 1: {
                        int value;
                        printf("\t输入数值：");
                        scanf("%d", &value);
                        EnAQueue(Q, &value);
                        break;
                    }
                    case 2: {
                        double value;
                        printf("\t输入数值：");
                        scanf("%lf", &value);
                        EnAQueue(Q, &value);
                        break;
                    }
                    case 3: {
                        char value;
                        printf("\t输入数值：");
                        rewind(stdin);//清空缓冲区
                        scanf("%c", &value, 1);
                        EnAQueue(Q, &value);
                        break;
                    }
                }
                TraverseAQueue(Q, APrint);
                //system("cls");
                break;
            };
        }
        case 3:
            if (ss == 0) {
                printf("\t队列未初始化，请先进行初始化操作\n");
                break;
            }
            else {
                DeAQueue(Q);
                TraverseAQueue(Q, APrint);
                break;
            }
        case 4:
            //system("cls");
            if (ss == 0) {
                printf("\t队列未初始化，请先进行初始化操作\n");
                break;
            }
            else {
                printf("\t队列长度为 %d\n", LengthAQueue(Q));
                //system("cls");
                break;
            }
        case 5:
            //system("cls");
            if (ss == 0) {
                printf("\t队列未初始化，请先进行初始化操作\n");
                break;
            }
            else {
                if (IsEmptyAQueue(Q)) {
                    printf("\t队列为空\n");
                }//判空
                else {
                    printf("\t队列不为空\n");
                }
                //system("cls");
                break;
            }
        case 6:
            //system("cls");
            if (ss == 0) {
                printf("\t队列未初始化，请先进行初始化操作\n");
                break;
            }
            else {
                if (IsFullAQueue(Q)) {
                    printf("\t队列为满\n");
                }//判满
                else {
                    printf("\t队列不为满\n");
                }
                //system("cls");
                break;
            }
        case 7:
            //system("cls");
            if (ss == 0) {
                printf("\t队列未初始化，请先进行初始化操作\n");
                break;
            }
            else {
                DestoryAQueue(Q);
                printf("\t销毁队列成功\n");
                //system("cls");
                break;
            }
        case 8:
            if (ss == 0) {
                printf("\t队列未初始化，请先进行初始化操作\n");
                break;
            }
            else {
                //system("cls");
                ClearAQueue(Q);
                printf("\t清空队列成功\n");
                //system("cls");
                break;
            }
        case 9: {
            //system("cls");
            if (ss == 0) {
                printf("\t队列未初始化，请先进行初始化操作\n");
                break;
            }
            else {
                int e = 0;//队头元素暂存
                GetHeadAQueue(Q, &e);
                //system("cls");
                break;
            }
        }
    }
}

/**
 *  @name        : int chooseType(AQueue * Q);
 *    @description : 选择要入队的类型
 *    @param
 *    @return
 *  @notice
*/
int chooseType(AQueue * Q)
{
    int type1 = 0;
    printf("\t你想入队哪种类型？\n");
    printf(
        "\t|1:整形\n"
        "\t|2:浮点型(精确到小数点后2位)\n"
        "\t|3:字符型\n");
    printf("\t请入类型：");
    scanf("%d", &type1);
    while (type1 < 1 || type1 > 3)
    {
        printf("\t应输入在1-3之间的整数！\n请重新输入：");
        scanf_s("%d", &type1);
    }
    Q->type[Q->rear] = type1;
    return type1;
}
