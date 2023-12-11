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
        //arraryNum[idx] = rand() % TARGET;
        printf("arrayNum[%d]:%d\n", idx, arrayNum[idx]);
        
    }
    int target;
    int first_num = 0; //用来存放第一个数
    int second_num = 0; //用来存放第二个数
   
    printf("请输入希望得到的两个数的和：");
    scanf("%d",&target);
    int flag = 0;
    
    /* 获取第一个数 */
    for(int idx = 0; idx < (BUFFER_TOTAL - 1); idx++)
    {
        first_num = arrayNum[idx]; 
        /* 接着找满足条件的第二个数,并且从第一个数之后开始遍历 */
        for (int  index = (idx + 1); index < BUFFER_TOTAL; index++)
        {
            second_num =  arrayNum[index] ;
            if(first_num + second_num == target) 
            {
                flag = 1;
                printf("符合条件的值分别是:arrayNum[%d]:%d,arrayNum[%d]:%d\n", idx, first_num, index, second_num);
            }
        }
    }
    if(flag == 0)//用flag记录如果没有符合条件的值则输出以下条件
    {
        printf("The array has no matching values.\n");
    }

    return 0;

}