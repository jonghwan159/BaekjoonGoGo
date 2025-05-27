#include <bits/stdc++.h>
using namespace std;
string answer;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    getline(cin,answer);
    for(int i = 0 ; i< answer.size(); i++)
    {
        char M = answer[i];
        if(M >='a' && M <='z')
        {
            if(M+13 >'z') answer[i] = M-13;
            else  answer[i] = M+13;
        }
        else if(M >='A' && M <='Z')
        {
            if(M+13 >'Z') answer[i] = M-13;
            else  answer[i] = M+13;
        }
        
    }
    cout << answer;
    return 0;
}