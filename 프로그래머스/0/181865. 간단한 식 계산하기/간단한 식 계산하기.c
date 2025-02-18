#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 14;
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* binomial) {
    int answer = 0;
    int strSize = strlen(binomial);
    int a = 0, b = 0;
    char op[1];
    
    sscanf(binomial,"%d %c %d",&a,&op,&b);
    
    printf("%d %c %d",a,op[0],b);
    if(op[0] == '+'){
        answer = a + b;
    }
    else if(op[0] == '-')
    {
         answer = a - b;
    }
    else if(op[0] == '*')
    {
        answer = a * b;
    }
    
    return answer;
}