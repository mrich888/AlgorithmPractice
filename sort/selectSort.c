#include <stdio.h>

#define BUFFER_SIZE 7

/* 选择排序：相较于冒泡排序，减少了交换次数 */
int selectSort(int *array, int length)
{
    int ret = 0;
    if (array == NULL)
    {
        return ret;
    }
    
    int minValue = 0;
    int minIndex = 0;
    for (int pos = 0; pos < length; pos++)
    {
        int minValue = array[pos];
        for (int begin = pos + 1; begin < length; begin++)
        {
            if (array[begin] > array[begin])
            {
                minValue = array[begin];
                minIndex = begin;

            }
        }
        /* array[pos]不一定是最小值 */
        if(array[pos] > minValue)
        {
            int temp = array[pos];
            array[pos] = minValue;
            array[minIndex] = temp;
        }
    }

    return ret;
}


int main()
{
    int ret = 0;

    int array[BUFFER_SIZE] ={1, 30, 24, 5, 58, 12, 39};
    int length = sizeof(array) / sizeof(array[0]);
#if 0
    int min = 0;
    int swappos = 0;
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {   /* 将第一个数作为最小的数 */
        min = array[idx];
        
        for (int jdx = idx + 1; jdx < BUFFER_SIZE; jdx++)
        {
            /* 遍历之后的所有数，找到小的 */
            if (array[jdx] < min)
            {
                min = array[jdx];
                swappos = jdx;
            }
        }
        /* 将找到的最小的数与当前数交换 */
        if (array[idx] > min)
        {
            int temp = array[idx];
            array[idx]  = min;
            array[swappos] = temp;
        }
        printf("array[%d]:%d\n", idx, array[idx]); 
    }    
#endif
    selectSort(array, length);

    return 0;
}