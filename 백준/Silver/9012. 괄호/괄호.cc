#include <bits/stdc++.h>
using namespace std;

int t;
string s;
bool check(string s)
{
    stack<char> stk;
    for(char c : s)
    {
        if(c == '(') stk.push(c);
        else
        {
            // ) 인경우
            if(!stk.empty()) stk.pop();
            else return false; 
        }
    }
    return stk.empty();
}



int main()
{
    cin >> t;
    for(int i=0; i < t; i++)
    {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        cin >> s;
        if(check(s)) cout << "YES\n";
        else cout << "NO\n";
    }   
    
    
    return 0;

}