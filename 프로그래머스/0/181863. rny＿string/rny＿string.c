#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void replaceSubstr(char* str,const char* old_sub,const char* new_sub)
{
    char buffer[201];
    char* pos = 0;
    
    while((pos = strstr(str,old_sub))!= NULL)
    {
        strncpy(buffer,str,pos-str);
        buffer[pos-str] = '\0';
        strcat(buffer,new_sub);
        strcat(buffer, pos+strlen(old_sub));
        
        strcpy(str,buffer);
        
    }
}
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* rny_string) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int strSize = strlen(rny_string);
    char* answer = (char*)malloc((strSize)*sizeof(char)*2);
    strcpy(answer,rny_string);
    replaceSubstr(answer,"m","rn");
    
    return answer;
}