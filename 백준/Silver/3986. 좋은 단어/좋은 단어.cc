#include <bits/stdc++.h>
using namespace std;
int N,cnt;
string a;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0 ; i < N ; i++)
    {
        cin >> a;
        stack<char> stk;
        for(char j : a)
        {
            if(stk.empty() || j != stk.top())
            {
                stk.push(j);
            }
            else 
            {
                stk.pop();
            }

        }

        if(stk.empty()) cnt++;
    }
    cout << cnt;
    return 0;
}