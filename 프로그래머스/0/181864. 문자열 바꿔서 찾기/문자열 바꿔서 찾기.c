#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* myString, const char* pat) {
    int answer = 0; 
    int strSize = strlen(myString);
    char arr[strSize+1];
    for(int i =0 ; i < strSize ; i++)
    {   
        if(myString[i] == 'A')
        {
             arr[i] = 'B';
        }
        else
        {
             arr[i] = 'A';
        }
       printf("%c ",arr[i]);
    }
     arr[strSize] = '\0';
    if(strstr(arr,pat))
    {
        answer = 1;
        
    }
    return answer;
}