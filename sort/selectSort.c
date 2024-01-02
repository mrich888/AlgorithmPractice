#include <stdio.h>

#define BUFFER_SIZE 7

int main()
{
    int ret = 0;
    int array[BUFFER_SIZE] ={1, 30, 24, 5, 58, 12, 39};

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



    return 0;
}