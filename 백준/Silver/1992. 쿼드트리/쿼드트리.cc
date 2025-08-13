#include <bits/stdc++.h>
using namespace std;

int n,size;
string s;
char grid[65][65];

string quard(int y, int x, int size)
{
    if(size == 1)
    {
        return string(1, grid[y][x]);
    }
    char b = grid[y][x];
     //(y, x)부터 (y+size, x+size)까지 스캔
     // 4개일때 생각하기
    for(int i = y ; i < y+size; i++)
    {
        for(int j = x ; j < x+size ; j++)
        {
            if(b !=  grid[i][j])
            {
                string ret = "(";
                ret += quard(y,x,size/2);
                ret += quard(y,x+size/2,size/2);
                ret += quard(y+size/2,x,size/2);
                ret += quard(y+size/2,x+size/2,size/2);
                ret += ')';
                return ret;

            }    
         
        }
    }
    return string(1, grid[y][x]);
}

int main()
{
    ios:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> s;
        for(int j = 0 ; j < n ; j++)
        {
            grid[i][j] = s[j];
        }
    }

    cout << quard(0, 0, n);
  
    return 0;
}