#include <bits/stdc++.h>
using namespace std;
int N,M,K, visited[101][101], grid[101][101], ldx[101],ldy[101],rux[101],ruy[101],ret;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0,-1};

void DFS(int y,int x, int &cnt)
{
    if(visited[y][x]) return;
    visited[y][x] = 1;
    cnt++;
    for(int i =0 ; i< 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(ny<0 || ny >=M || nx < 0 || nx >= N || visited[ny][nx] || grid[ny][nx]) continue;
        DFS(ny,nx,cnt);

    }
    return;
}


int main()
{
    cin >> M >> N >> K;
    for(int i =0 ; i < K ; i++)
    {
       cin >> ldx[i] >> ldy[i] >> rux[i] >> ruy[i];
       //색칠하기
       for(int cy = ldy[i]; cy< ruy[i]; cy++)
       {
            for(int cx = ldx[i]; cx < rux[i]; cx++)
            {
             
                grid[cy][cx] = 1;
               
            }
       }
    //    for(int k = 0 ; k< M; k++)
    //    {
    //         for(int h = 0; h < N; h++)
    //         {
             
    //             cout << grid[k][h]<<" ";
               
    //         }
    //         cout<<"\n";
    //    }
    }

    //DFS
    vector<int> area;
    for(int i = 0 ; i< M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            
           if(!visited[i][j] && grid[i][j] == 0)
           {    
                int cnt = 0;
                ret++;
                DFS(i,j, cnt);
                area.push_back(cnt);


           }
            
        }
   
    }
    cout << ret<<"\n";
    sort(area.begin(),area.end());
    for(auto i : area)
    {
        cout << i <<" ";
    }
    return 0;
}