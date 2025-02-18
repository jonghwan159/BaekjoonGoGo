#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100000
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* myString) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int strSize = strlen(myString);
    int* answer = (int*)malloc(strSize*sizeof(int));
    char* arr = (char*)malloc((strSize+1)*sizeof(char));
    int index = 0;
    int cnt = 0;
    strcpy(arr,myString);
    for(int i = 0; i <= strSize ; i++)
    {
        if(myString[i] == 'x'|myString[i] == '\0')
        {
            answer[index++] = cnt;
            cnt = 0;
        }
        else{
            cnt++;
        }
    }
    answer = realloc(answer, index*sizeof(int));
    free(arr);
    return answer;
}