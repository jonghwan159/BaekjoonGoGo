#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

// arr_len은 배열 arr의 길이입니다.
int* solution(int arr[], size_t arr_len, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(arr_len *sizeof(int));
    int index = 0;
    for(int i = 0 ; i < arr_len ; i++)
    {
        uint8_t flag = 0;
        for(int j = 0 ; j < index; j++)
        {
            if(answer[j] == arr[i]){
                flag = 1;
            }
           
            if(flag == 1)
                break;
        }
        if(flag == 1)
                continue;
        else{
            answer[index++] = arr[i];
        }
        
    }
    if(index < k){
        while(index < k){
            answer[index++] = -1;
        }
    }
    return answer;
}