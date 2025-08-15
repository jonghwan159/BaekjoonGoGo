#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main()
{
    cin >> t;
    for(int i=0; i < t; i++)
    {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        cin >> s;
        stack<char> stk;
        for(int j = 0 ; j < s.size(); j++)
        {
            if(stk.size() == 0)
            {
                stk.push(s[j]);
                continue;
            }
            else if(stk.size() && stk.top() == '(' && s[j] == ')')
            {
                stk.pop();
            }
            else{
                stk.push(s[j]);
            }
           
        }

        if(stk.size())
        {
            cout<<"NO" <<"\n";
        }
        else
        {
            cout<<"YES" <<"\n";
        }
    }
    
    
    return 0;

}