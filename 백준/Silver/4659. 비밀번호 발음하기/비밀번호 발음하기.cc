#include <bits/stdc++.h>
using namespace std;

string s;
char vowels[] = {'a','e','i','o','u'};
int qualpass, ret;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //여러개의 테스트 케이스
    while(cin >> s)
    {
        if(s =="end")
        {
            return 0;
        }
        /*  1. 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
            2. 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
            3. 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
        */
    
       int cnt = 0;
       int qualpass = 0;
       int vocnt = 0 , cocnt = 0;
       char prew = ' ';
       bool preIsVowel = false;
       bool isStrat =true;
       bool qualIsgood =true;
       for(char i : s)
       {
            bool isVowel = false;
           //Check 1
           //1. 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
            for(int j = 0; j < 5; j++)
            {
                if(vowels[j] ==  i) 
                {   cnt++;
                    isVowel = true;
                }
            }
            //Check 2
            //2. 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
            if(preIsVowel == true&& isVowel == true && !isStrat)
            {
                vocnt++;
            }
            else{
                vocnt = 0;
            }

            if(preIsVowel == false&& isVowel == false && !isStrat) 
            {
                cocnt++;
            } 
            else
            {
                cocnt = 0;
            }
            //cout <<"word = "<< i <<", vocnt = " << vocnt<< ", cocnt = " << cocnt << "\n";
            if(vocnt >=2 || cocnt >=2)
            {
                qualIsgood = false;
                //cout <<"hihi\n";
                break;
            }

            //Case 3
            if(prew == i)
            {
                if(!(prew == 'e' || prew == 'o'))
                {
                    qualIsgood = false;
                    break;
                }
            }
            
            prew = i;
            preIsVowel = isVowel;
            isStrat =false;
            //cout << "cnt = " << cnt << "\n";
            //cout << "vocnt = " << vocnt<< ", cocnt = " << cocnt << "\n";

       }

       if(cnt > 0 && qualIsgood)
       {
            qualpass = 1;
       }

        if(qualpass)
        {

            //높은 품질을 가진 비밀번호 안경우
            cout << "<"<< s << "> is acceptable.\n";
        }
        else{
             cout << "<"<< s << "> is not acceptable.\n";
        }

    
    }
    return 0;
}