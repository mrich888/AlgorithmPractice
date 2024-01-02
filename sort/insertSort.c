#include <stdio.h>

#define BUFFER_SIZE 7

int main()
{
    int ret = 0;
    int array[BUFFER_SIZE] ={24, 30, 5, 28, 12, 39};
    int pos = 0;
    for (int idx = 1; idx < BUFFER_SIZE; idx++)
    {
        int pos = idx;
        int cmp = array[idx];
        /* 当idx=0的时候截止 */
        while (idx == 0 || array[idx] < cmp)
        {
            /* 满足条件，前一个给后一个 */
            array[idx] = array[idx - 1];
            
        }
        
            
    }
}