#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* 宏定义在预处理阶段 被替换 */
#define BUFFER_SIZE 7
/* 二分查找适用于已经排好序的：
    ①先将数组进行排序
    ②找中间值 左小右大  (静态函数)
    ③循环遍历范围min = end
    
 */
static int findBaseValPos(int *array, int begin, int end);
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

/* ①快速排序*/
/* 第一次遍历找基准值 */
static int findBaseValPos(int *array, int begin, int end)
{
    end--;
    int baseVal = array[begin];
    
    while (begin < end)
    {
        /* 
        第一步：将第一位作为基准值，从后开始比较
        尾和基准值作比较,如果后面的值一直比基准值大的话会一直在第一个循环中，
        否则才会break跳出进入到第二个循环中
        */
        /* 
        没理解到位的点：
        ①纠结着如何再一次循环中实现指针前后跳动，只想到了for循环，事实上用while循环，
        只要前指针在后指针前面就可以进入循环（也就是直到前后指针重合才跳出循环）
        ②没有理解清楚后指针是如何跳到前面，前指针又如何变动到后面的
        其实指针的变动也是在一个循环中，首先它只有不满足后面这个比基准值大的时候就会跳到前面，此时就需要一个break跳出
        也只有break才实现了指针的转换，到前面的数与基准值作比较，并且决定指针跳不跳的是循环里的比较
        */
       /* 这也就明白了为什么是while（ while（if） while（if））*/
        while (begin < end)
        {
            if (array[end] < baseVal)
            {
                array[begin++] = array[end];
                break; 
            }
            else
            {
                end--;
            }
            
        }
        
        /* 前和基准值作比较 */
        while (begin < end)
        {
            if (array[begin] > baseVal)
            {
                array[end--] = array[begin];
                break; //作用是跳出循环
            }
            else
            {
                begin++;
            }   
        }

        /* 最后将基准值放入此时空缺的位置，使数组完整 */
        array[begin] = baseVal;
        return begin;
    }
}
/* 对基准值左右进行排序 */
int quickSort(int *array, int begin, int end)
{
    int ret = 0;
    /* 数组判空*/
    if (array == NULL)
    {
        return ret;
    }
    /* 只有一个值 */
    if (begin >= end)
    {
        return ret; 
    }
    /* 找到基准值 */
    int baseValPos = findBaseValPos(array, begin, end);
    /* 对基准值左边排序 */
    quickSort(array, begin, baseValPos);
    /* 对基准值右边排序 */
    quickSort(array, baseValPos + 1, end);
    return ret;
}


/* 返回值：1表示存在。0表示不存在。*/
/* 循环遍历范围min = end */
int binarySearchIsExist(int *array, int length, int val)
{
    int ret = 0;
    if (array == NULL)
    {
        return ret;
    }
    int begin = 0;
    int end = length - 1;
    int midIndex = 0;
    /*  比较它在索引位置的值的左边还是右边，比较在循环中 */

    while (begin <= end)
    {
        /* 确定中间索引 */
        midIndex = (begin + end) >> 1;
        /* 目标值在索引左边 */
        if (val < array[midIndex])
        {
            end = midIndex - 1;
        }
        /* 目标值在索引右边 */
        else if (val > array[midIndex])
        {
            begin = midIndex + 1;
        }
        else
        {
            return midIndex;
        }
    }
    
    return -1;
}

int main()
{
    /* 随机数种子 */
    srand(time(NULL));

    int buffer[BUFFER_SIZE] = { 0 };

    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        buffer[idx] = rand() % 100 + 1; 
    }
    
    int length = sizeof(buffer) / sizeof(buffer[0]);
    quickSort(buffer, 0, length);
    printArray(buffer, length);
    int val = 5;
    int isExist = binarySearchIsExist(buffer, length, val);
    printf("isExist:%d\n", isExist);

    return 0;
}