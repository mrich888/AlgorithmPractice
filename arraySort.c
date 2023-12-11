#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_NUM 10

int main()
{
    srand(time(NULL));
    int arraryNum[TOTAL_NUM];
    memset(arraryNum, 0 , sizeof(arraryNum));

    for(int idx = 0; idx < TOTAL_NUM; idx++)
    {
        arraryNum[idx] = rand() % 10;
        printf("arrayNum[%d]:%d\n", idx, arraryNum[idx]);
    }
    
    int minNum = 0;
    int midNum = 0;




}