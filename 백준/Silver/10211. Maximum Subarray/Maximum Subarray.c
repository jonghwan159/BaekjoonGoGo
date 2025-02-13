#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int maxSubArrSum(int* a, int size)
{
    int pastAndNowMaxSum = a[0], currentMaxSum = a[0];
    for(int i = 1 ; i < size ; i++)
    {
        currentMaxSum = (currentMaxSum > 0)?currentMaxSum + a[i] :a[i];
        if(currentMaxSum > pastAndNowMaxSum)
        {
            pastAndNowMaxSum = currentMaxSum;
        }
    }
    return pastAndNowMaxSum;
}

int main(void)
{   
   int N = 0, T = 0;
   scanf("%d",&T);
   
   for(int i = 0 ; i < T ; i++)
   {
    scanf("%d",&N);
    //printf("N = %d, T = %d\n",N,T);
    int* arr = (int*)malloc(N*sizeof(int));
    for(int j = 0 ; j < N; j++)
    {
        scanf(" %d",&arr[j]);
    }
    //    for(int k = 0 ; k < N; k++)
    // {
    //     printf("%d ",arr[k]);
    // }
   // printf("\n");
    int maxSum = maxSubArrSum(arr,N);
    printf("%d\n",maxSum);
    free(arr);
   } 
  
 
    return 0;
}