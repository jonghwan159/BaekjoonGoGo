#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* myStr) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int strSize = strlen(myStr);
    char** answer = (char**)malloc(strSize * sizeof(char*));
    char* arr = (char*)malloc((strSize+1) * sizeof(char));
    strcpy(arr,myStr);
    int index = 0;
    
    char* token = strtok(arr,"abc");
    
    while(token)
    {   
        int tokLen = strlen(token);
        answer[index] = (char*)malloc((tokLen+1)*sizeof(char));
        strcpy(answer[index++],token);
        token = strtok(NULL,"abc");
    }
    if(index == 0){
        answer[index] = (char*)malloc(6*sizeof(char));
        answer[index++] = "EMPTY";
    }
    answer = (char**)realloc(answer,index *sizeof(char*));
    return answer;
}