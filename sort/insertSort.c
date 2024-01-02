#include <stdio.h>

#define BUFFER_SIZE 7

/* 打印函数，数组做参数，自动弱化成指针 （*array） */
int printArray(int *array, int length)
{   
    int ret = 0;
    for (int idx = 0; idx < length; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }
    return ret;
}

int insertSort(int *array, int length)
{   
    int ret = 0;
    int copyNum = 0;
    int cur = 0;
    for (int idx = 1; idx < length; idx++)
    {
        cur = idx;
        /* 把需要排序的值拿出来 */
        copyNum = array[idx];
        /* 开始比较 */
        /* 截止条件：当idx=0 或者 找到比当前值小 (即一个不满足就跳出，也就是说要同时满足两个条件) */
        while (cur > 0 && copyNum < array[cur - 1])
        {
            /* 满足条件，前一个给后一个 */
            array[cur] = array[cur - 1];
            /* idx会影响上层循环 */
            cur--;
        }
        array[cur] = copyNum;    
    }
    return ret;
}

int main()
{
    int ret = 0;
    int array[BUFFER_SIZE] ={24, 30, 5, 28, 12, 39};
    int length = sizeof(array) / sizeof(array[0]);
    insertSort(array, length);
    printArray(array, length);
    return ret;
}