#include <stdio.h>
#define BUFFER_SIZE 6

/* 交换函数 */
int swap(int *val1, int * val2)
{
    int ret;
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
    return ret;
   
}
/* 打印函数，数组做参数，自动弱化成指针 （*array） */
int printArray(int *array, int arraySize)
{   
    int ret = 0;
    for (int idx = 0; idx < arraySize; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }
    return ret;
}
/* 优化01 */
/* 自定义冒泡函数 */
#if 0
void bubbleSort(int *array, int arraySize)
{
    /* 已经排好序的标志*/
    int sorted = 1;
    /* 从后往前便利 */
    for (int end = arraySize; end > 0; end--)
    {
        
        /* 并且使第二层的遍历到第一层开始的地方截止（【优化】即第二次循环就不和已经排好的数组做比较） */
        for (int begin = 1; begin < end; begin++)
        {
            /* 里层for循环只能在完成一轮的比较，将最大的放到最后一位 */
            if (array[begin] < array[begin - 1])
            {
                /* 后面比前面的数下，交换 */
                swap(&(array[begin]), &(array[begin - 1]));
                /* 数据使没有排好序的 */
                sorted = 0;
            }
        }
        if (sorted == 1)
        {
            break;
        }
    }
}
#endif

/* 优化02 */
void bubbleSort(int *array, int length)
{
    /* 已经排好序的标志*/
    int sortedIndex = 0;
    /* 从后往前遍历 */
    for (int end = length; end > 0; end--)
    {
        /* 标志：排好序的化就不进入if中，得不到sortedIndex的值，所以使得它等于1，它再--可直接跳出循环（即全部已排好序） */
        sortedIndex = 1;
        /* 并且使第二层的遍历到第一层开始的地方截止（【优化】即第二次循环就不和已经排好的数组做比较） */
        for (int begin = 1; begin < end; begin++)
        {
            /* 里层for循环只能在完成一轮的比较，将最大的放到最后一位 */
            if (array[begin] < array[begin - 1])
            {
                /* 后面比前面的数下，交换 */
                swap(&(array[begin]), &(array[begin - 1]));
                /* 记录排好序的下标 */
                sortedIndex = begin;
            }
        }

        end = sortedIndex;
    }
}

int main()
{
    int array[BUFFER_SIZE] = {11, 36,  83, 65, 107, 108};
    int length = sizeof(array) / sizeof(array[0]);

    bubbleSort(array, length);
    printArray(array, length);
    return 0; 
}


