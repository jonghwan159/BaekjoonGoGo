#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* n_str) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int n_strSize = strlen(n_str);
    char* answer = (char*)malloc(n_strSize);
    bool toggle = false;
    int index = 0 ;
    if(n_str[0] == '0')
    {
        for(int i = 0; i <n_strSize; i++ )
        {
            if(n_str[i] != '0')
            {
               toggle = true; 
            }
            if(toggle == true)
            {
                answer[index++] = n_str[i];
            }
        }
        
    }
        
    else
    {
        strcpy(answer,n_str);
        return answer;
    }
    
  
    answer[index] = '\0';
    
 
    return answer;
}