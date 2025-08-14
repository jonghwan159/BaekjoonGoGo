#include <bits/stdc++.h>
using namespace std;
int h,w;
int a[104][104];
bool NoCloud = true;

void go(int y, int x)
{
    
    int nx = x + 1;
    if(nx >= w || a[y][nx] >= 0) return;
    a[y][nx] = a[y][x] + 1;
    go(y,nx);


    return;
}
int main()
{
    cin >> h >> w;
    for(int i =0 ; i < h; i++)
    {
        for(int j = 0 ; j < w ; j++)
        {
            char temp;
            cin >> temp;
            if(temp == 'c') 
            {
                a[i][j] = 0;
                NoCloud = false;
            }
            else a[i][j] = -1;
        }
    }
    
    //구름이 없는 경우
    if(NoCloud)
    {
        for(int i =0 ; i < h; i++)
        {
            for(int j = 0 ; j < w ; j++)
            {
                cout << a[i][j] <<" ";
            }
            cout<<"\n";
        }
        return 0;

    }


    for(int i =0 ; i < h; i++)
    {
        for(int j = 0 ; j < w ; j++)
        {
            if(a[i][j] == 0)
            {
                go(i,j);
            }
        }
       
    }

    for(int i =0 ; i < h; i++)
    {
        for(int j = 0 ; j < w ; j++)
        {
            cout << a[i][j] <<" ";
        }
        cout<<"\n";
    }
 


    return 0;
}