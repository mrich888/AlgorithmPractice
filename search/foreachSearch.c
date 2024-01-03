#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* 宏定义在预处理阶段 被替换 */
#define BUFFER_SIZE 10

/* 宏函数 无法调试,尽量短小精悍 */
//#define CHECK_PTR()
/* 打印函数，数组做参数，自动弱化成指针 （*array） */
int printArray(int *array, int length)
{   
    int ret = 0;
    if (array == NULL)
    {
        return ret;
    }
    
    for (int idx = 0; idx < length; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }
    return ret;
}

/* 找到指定数值 */
int findAppointValPos(int *array, int length, int val, int *pPos)
{
    int ret = 0;
    if (array == NULL)
    {
        return -1;
    }
    /* 打标记 */
    int flag = 0;
    for (int idx = 0; idx < length; idx++)
    {
        if (val == array[idx])
        {
            /* 找到了把下标传出去 */
            *pPos = idx;
            flag = 1;
        }
    }
    /* 没找到 */
    if (flag == 0)
    {
        /* 解引用 */
        *pPos = -1;
    }
    /* 只返回成功与否 */
    return ret;
}

int main()
{
    int ret;
    /* 随机数种子 */
    srand(time(NULL));

    int buffer[BUFFER_SIZE] = { 0 };

    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        buffer[idx] = rand() % 100 + 1; 
    }
    /* 打印数组 */
    int length = sizeof(buffer) / sizeof(buffer[0]);
    printArray(buffer, length);
    printf("\n");

    int findVal = 35;
    int Pos = 0;
    findAppointValPos(buffer, length, findVal, &Pos);
    printf("pos:%d\n", Pos);
    return 0;
}