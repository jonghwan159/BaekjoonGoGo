#include <bits/stdc++.h>
using namespace std;


string s;
bool isBracket(char c)
{
    return c == '(' || c == ')' || c == '[' || c == ']';
}

bool check(string s)
{
    stack<char> stk;
    for(char c : s)
    {
        if(!isBracket(c)) continue;
        else if(c == '('|| c == '[')
        {
            stk.push(c);
        }
        else if(stk.size() && stk.top() == '(' && c == ')' )
        {
            stk.pop();
        }
        else if(stk.size() && stk.top() == '[' && c == ']' )
        {
            stk.pop();
        }
        else if(!stk.size() && c == ')') return false;
        else if(!stk.size() && c == ']') return false;
        else
        {
            stk.push(c);
        }
  

    }
    return stk.empty();
}



int main()
{

        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        while(true)
        {
            getline(cin,s);
            if(s == ".") break;
            if(check(s)) cout << "yes\n";
            else cout << "no\n";
        }
    
    
    return 0;

}