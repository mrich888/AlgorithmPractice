#include <stdio.h>

#define BUFFER_SIZE 6
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
/* 快速排序 */
int quickSort(int *array, int startPos, int endPos)
{
    /* 需要判空 */
    if (array ==NULL)
    {
        return 0;
    }
    int ret = 0;
    int baseVal = 0;
    endPos--;
    /* 基准值 */
    baseVal = array[startPos];
    /* 前指针一定再后指针的前面 */
    /* 最外层循环截止条件就是当前后指针位置重合时跳出循环 */
    while (startPos < endPos)
    {
        /* 会出现两种情况：尾跟基做比较和头跟基做比较，肯定会做其中一个，并且这个比较循环的
        两个循环条件是一样的，只要前在后的前边就满足
        满足条件才会进入其中一个循环中，进入之后才会进行判断
        所以是while  while  if
        */
        while (startPos < endPos)
        {
            if (array[endPos] > baseVal)
            {
                /* 比基准值大的话 */
                endPos--;
            }
            else
            {
                array[startPos] = array[endPos];
                startPos++;
                break;
            }
        }

        while (startPos < endPos)
        {   
            /* 如果比基准值小 */
            if (array[startPos] < baseVal)
            {
                startPos++;
            }
            else
            {
                array[endPos] = array[startPos];
                endPos--;
                break;
            }
        } 
    }
    array[startPos] = baseVal;
        
    return ret;
}

static findBaseValPos(int *array, int startPos, int endPos)
{
    if (array ==NULL)
    {
        return 0;
    }
    int ret = 0;
    int baseVal = 0;
    endPos--;
    /* 基准值 */
    baseVal = array[startPos];
    while (startPos < endPos)
    {
        while (startPos < endPos)
        {
            if (array[endPos] > baseVal)
            {
                /* 比基准值大的话 */
                endPos--;
            }
            else
            {
                array[startPos] = array[endPos];
                startPos++;
                break;
            }
        }

        /* 如果比基准值小 */
        while (startPos < endPos)
        {
            if (array[startPos] < baseVal)
            {
                startPos++;
            }
            else
            {
                array[endPos] = array[startPos];
                endPos--;
                break;
            }
        } 
    }
    array[startPos] = baseVal;
    int baseValPos = startPos;
    return baseValPos;
}

int quickSort02(int *array, int startPos, int endPos)
{
    int ret = 0;
    int baseValPos = findBaseValPos(array, startPos, endPos);

    quickSort(array, startPos, baseValPos);
    quickSort(array, baseValPos + 1, endPos);

    return ret;
}

int main()
{
    int ret = 0;
    int array[BUFFER_SIZE] = {83,11, 36, 65, 107, 108};//
    int length = sizeof(array) / sizeof(array[0]);

    quickSort(array, 0, length);
    printArray(array, length);
    return 0; 

}