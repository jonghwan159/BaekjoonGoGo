#include <bits/stdc++.h>
using namespace std;
int val = 666;
int n;


int main()
{
    cin >> n;
    for( ; ; val++)
    {
        if(to_string(val).find("666") != string::npos) n--;
        if(n == 0)
        {
            break;
        }
    }
    cout << val;
    return 0;
}