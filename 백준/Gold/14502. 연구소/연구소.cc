#include <bits/stdc++.h>
using namespace std;
int N,M;
int visited[10][10], originGrid[10][10], grid[10][10], ret;
vector<pair<int,int>> zeroSpace;
int dy[] = {1, -1, 0 ,0};
int dx[] = {0 ,0 ,-1, 1};

void print()
{
    cout << "\nvisited\n";
    for(int i=0 ; i <N ; i++)
    {
        for(int j =0 ; j < M ;j++)
        {
            cout <<visited[i][j] <<" ";
        }
        cout << "\n";
    } 
    return;
}

void printGrid()
{
    for(int i=0 ; i <N ; i++)
    {
        for(int j =0 ; j < M ;j++)
        {
            cout <<grid[i][j] <<" ";
        }
        cout << "\n";
    } 
    return;
}


void DFS(int y, int x)
{
    if(visited[y][x]) return;
    visited[y][x] = 1;

    for(int i =0 ; i < 4 ; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || nx >= M ||ny < 0 || ny >= N || visited[ny][nx] || grid[ny][nx]) continue;
        DFS(ny,nx);


    }
    return;
}

int CheckSafeSize()
{
    int cnt = 0;
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < M; j++)
        {
            if(!visited[i][j] && grid[i][j] == 0) cnt++;
        }
    }
    return cnt;
}
int main()
{  // 0은 빈 칸, 1은 벽, 2는 바이러스
    // 빈칸에 벽 무조건 3개 세워야
    cin >> N >> M;
    for(int i=0 ; i <N ; i++)
    {
        for(int j =0 ; j < M ;j++)
        {
            cin >> originGrid[i][j];
            // 1. 0인 공간 번호를 Check한다
            if(originGrid[i][j] == 0)zeroSpace.push_back({i,j});
        }
    } 
    // //
    // cout << zeroSpace.size()<<"\n";
    // for(int h = 0; h <zeroSpace.size() ; h++)
    // {
    //     cout << "y = "<< zeroSpace[h].first <<", x = " << zeroSpace[h].second <<"\n";
    // }




    // 2. 공간들을 조합으로 경우의 수 check
    for(int i =0; i<zeroSpace.size(); i++)
    {
        for(int j =i+1; j<zeroSpace.size(); j++)
        {
             for(int k = j+1; k<zeroSpace.size(); k++)
            {
                // if(zeroSpace[i].first == 5 && zeroSpace[i].second == 7 && zeroSpace[j].first == 6 && zeroSpace[j].second == 6 &&zeroSpace[k].first == 7 && zeroSpace[k].second == 5)
                // {
                    //3. 경우의 수마다 grid를 바꿈
                    fill(&visited[0][0],&visited[0][0]+10*10, 0);
                    memcpy(grid,originGrid,sizeof(originGrid));
                    // cout << "zeroSpace[i].first , y = "<<zeroSpace[i].first <<", x="<<zeroSpace[i].second <<"\n";
                    // cout << "zeroSpace[j].first , y = "<<zeroSpace[j].first <<", x="<<zeroSpace[j].second <<"\n";
                    // cout << "zeroSpace[k].first , y = "<<zeroSpace[k].first <<", x="<<zeroSpace[k].second <<"\n";
                    grid[zeroSpace[i].first][zeroSpace[i].second] = 1;
                    grid[zeroSpace[j].first][zeroSpace[j].second] = 1;
                    grid[zeroSpace[k].first][zeroSpace[k].second] = 1;

                    // //검증
                    // print();
                    // 4.바이러스 발생
                    for(int h = 0; h <N ; h++)
                    {
                        for(int l = 0; l < M ; l++)
                        {
                            if(grid[h][l] == 2 && !visited[h][l]) DFS(h,l);
                        }
                    }
                    // cout<<"\n DFS 이후\n";
                    // print();
                    // cout<<"\n Grid\n";
                    //printGrid();
                    //5. 안전구간 세기
                    // cout <<"CheckSafeSize = " <<CheckSafeSize() <<"\n";
                    ret = max(ret,CheckSafeSize());
                    //cout << "i = "<< i <<", j = "<< j << ", k = "<< k <<", ret = "<< ret <<"\n";
                //}
            }
        }
    }
    cout << ret;

    return 0;
}