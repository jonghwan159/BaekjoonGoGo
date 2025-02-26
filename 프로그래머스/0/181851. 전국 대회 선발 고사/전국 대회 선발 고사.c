#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>


typedef struct
{
    int rank;
    int studenNum;
    
}People;

int func1(const void* a, const void* b)
{
  return( ((People*)a)->rank - ((People*)b)->rank);
}

// rank_len은 배열 rank의 길이입니다.
// attendance_len은 배열 attendance의 길이입니다.
int solution(int rank[], size_t rank_len, bool attendance[], size_t attendance_len) {
    int answer = 0;
    People* people = (People*)calloc(rank_len,sizeof(People));
    uint8_t index = 0;
    //참여 가능한사람일때 배열 넣기
    for(int i = 0 ; i < rank_len ; i++)
    {
       
        if(attendance[i] == true)
        {
            people[index].rank = rank[i];
            people[index++].studenNum = i;
        }
    }
    
    
     //정렬 1 2 3 등만 있으면 됨
    qsort(people,index,sizeof(people[0]),func1);
  
    int a = people[0].studenNum;
    int b = people[1].studenNum;
    int c = people[2].studenNum;
    answer = 10000 * a + 100 * b + c;
    return answer;
}