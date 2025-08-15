#include <bits/stdc++.h>
using namespace std;

int n ,m, grid[104][104], visited[104][104],ret,cnt;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
vector <pair<int,int>> v;

void printGrid()
{
    cout<<"\nGrid\n";
    for(int i =0 ; i < n ; i++)
    {
        for(int j = 0 ; j <m ; j++)
        {
            cout << grid[i][j]<< " ";
        }
        cout<< "\n";
    }
    return;
}

void go(int y, int x)
{
    
    if(visited[y][x]) return;
    visited[y][x] =1;

    if(grid[y][x])
    {
        grid[y][x] = 2;
        return;
    }

    for(int i =0 ; i< 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny <0 || ny >= n || nx <0 || nx >= m || visited[ny][nx] ) continue;
        go(ny, nx);
    }

    return;
}

int main()
{
    cin >> n >> m;
    for(int i =0 ; i < n ; i++)
    {
        for(int j = 0 ; j <m ; j++)
        {
            cin >> grid[i][j];
        }
    }

    while(true)
    {
        fill(&visited[0][0],&visited[0][0]+104* 104, 0);
        v.clear();
        cnt = 0;
        go(0,0);
       // printGrid();
        //줄이기
        for(int i =0 ; i < n ; i++)
        {
            for(int j = 0 ; j <m ; j++)
            {
                if(grid[i][j] == 2) 
                {
                    grid[i][j] = 0;
                    cnt++;
                }
                if(grid[i][j] == 1) v.push_back({i,j});

            }
        }
        //printGrid();
       // cout << "v.size = "<<v.size() << "\n";
        ret++;
        if(v.size() == 0) break;


    }
    cout<< ret<<"\n"<< cnt <<"\n";
    return 0;
}