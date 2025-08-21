#include <bits/stdc++.h>
using namespace std;

int n,l,r, cnt =0,sum;
int a[54][54];
int visited[54][54];
vector<pair<int,int>> v;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void go(int y, int x)
{
    
    for(int i = 0 ; i < 4 ; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(nx <0 || nx >= n|| ny <0 || ny >= n || visited[ny][nx]) continue;
        if( l <= abs(a[ny][nx]-a[y][x]) && abs(a[ny][nx]-a[y][x]) <= r )
        {
            visited[ny][nx] = 1;
            v.push_back({ny,nx});
            sum += a[ny][nx];
            go(ny,nx);
        }
    }

    return;
}




int main()
{
    cin >> n >> l >> r;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin >> a[i][j];
        }
    }
    while(true)
    {
        memset(visited,0,sizeof(visited));
        int flag = 0;
       
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(!visited[i][j])
                {
                    v.clear();
                    visited[i][j] = 1;
                    v.push_back({i,j});
                    sum = a[i][j];
                    go(i,j);
                    if(v.size() == 1) continue;
                    for(auto group : v )
                    {
                        a[group.first][group.second] = sum /v.size();
                         
                    }
                    flag = 1; 
                   
                }
            
            }
        }
        //탈출 조건
        if(!flag) break;
        else cnt++;
 
    }
    cout << cnt;

   
    return 0;
}