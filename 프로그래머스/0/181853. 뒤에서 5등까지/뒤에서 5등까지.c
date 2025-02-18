#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// num_list_len은 배열 num_list의 길이입니다.
int func1(const void* a , const void* b)
{
    return(*(int*)a-*(int*)b);
}


int* solution(int num_list[], size_t num_list_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(5* sizeof(int));
    
    // 1. 정렬
    qsort(num_list,num_list_len,sizeof(int),func1);
    // 2. 5개
    for(int i = 0 ; i < 5 ; i++)
    {
        answer[i] = num_list[i];
    }
    
    return answer;
}