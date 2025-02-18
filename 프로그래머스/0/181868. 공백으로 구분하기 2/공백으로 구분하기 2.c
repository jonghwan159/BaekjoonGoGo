#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 1000
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* my_string) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char** answer = (char**)malloc(strlen(my_string)*sizeof(char*));
    char* arr[strlen(my_string)+1];
    strcpy(arr, my_string);
    char* token = strtok(arr, " ");
    int index = 0;
    while(token)
    {
        answer[index] = (char*)malloc((strlen(token)+1) * sizeof(char));
        strcpy(answer[index++],token);
        token = strtok(NULL," ");
    }
    answer = (char**)realloc(answer, index*sizeof(char*));
    return answer;
}
