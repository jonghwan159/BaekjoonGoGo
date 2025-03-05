#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* a, const char* b) {
    int alen = strlen(a);
    int blen = strlen(b);
    int maxLen = (alen > blen ? alen : blen) + 1;
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc((maxLen+1) * sizeof(char));
    
    int carry = 0 , i = alen -1 , j = blen - 1., k = maxLen;
    answer[k] = '\0';
    while( i >=0 || j >=0 || carry)
    {
        int sum = carry;
        if(i>=0) sum += a[i--] - '0';
        if(j>=0) sum += b[j--] - '0';
        answer[--k] = sum % 10 + '0';
        carry = sum / 10;
    }
    
    return answer+k;
}