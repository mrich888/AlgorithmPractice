#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define BUFFER_TOTAL 20
#define RANGE 20

int main()
{
    /* 随机数种，保证每次随机出来的数组中的数字不一样 */
    srand(time(NULL));  
    /* 定义一个存放随机数的数组 */  
    int arrayNum[BUFFER_TOTAL];
    /* 初始化数组 */
    memset(arrayNum, 0, sizeof(arrayNum));
    /* 生成随机数组 */
    for(int idx = 0; idx < BUFFER_TOTAL; idx++)
    {
        arrayNum[idx] = rand() % RANGE;
        printf("随机数组arrayNum[%d]:%d\t", idx, arrayNum[idx]);
    }

    /* 由第一个开始遍历 */
    for(int idx = 0; idx < (BUFFER_TOTAL - 1); idx++)
    {
        /* 采用交换下标的方式，记录下最小值的下标 */
        int minNum = idx;
        for(int jdx = (idx + 1); jdx < BUFFER_TOTAL; jdx++)
        {
            if(arrayNum[minNum] > arrayNum[jdx])
            {
                minNum = jdx;
            }

        }
        /* 利用最小值的下标找到最小值，再将第idx个数和最小值交换 */
        /* idx是按顺序输出的，但数值是交换过的，按照从小到大的顺序输出的 */
        int temp = arrayNum[idx];
        arrayNum[idx] = arrayNum[minNum];
        arrayNum[minNum] = temp;
        printf("minum:%d\n", arrayNum[idx]);
    }
    return 0;
}