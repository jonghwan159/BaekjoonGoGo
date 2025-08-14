#include <bits/stdc++.h>
using namespace std;
int n;
string s;
char a[65][65];
string quard(int y, int x, int size)
{
    if(size == 1)
    {
        return string(1, a[y][x]); 
    }

    char b = a[y][x];
    for(int i = y; i < y+size; i++)
    {
        for(int j = x; j < x+size; j++)
        {
            if(b != a[i][j])
            {
                string ret = "(";
                int sz =size/2;
                ret += quard(y,x,sz);
                ret += quard(y,x+sz,sz);
                ret += quard(y+sz,x,sz);
                ret += quard(y+sz,x+sz,sz);
                ret += ')';
                return ret;
            }
        }
    }
    return string(1, a[y][x]);

}


int main()
{
    ios::sync_with_stdio(false); cin.tie(); cout.tie();
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> s;
        for(int j = 0 ; j < n ; j++)
        {
            a[i][j] = s[j];
        }
    }
    cout << quard(0,0,n);
    return 0;
}