#include <bits/stdc++.h>
using namespace std;
int N,M, visited[101][101], adj[101][101];
int dy[] = {-1, 0 , 1, 0};
int dx[] = {0, 1, 0 , -1};
void BFS(int y, int x)
{   
    queue<pair<int, int>> q;
    visited[y][x] = 1;
    q.push({y,x});
    while(q.size())
    {
        int cy, cx;
        tie(cy,cx) = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M || adj[ny][nx] == 0 || visited[ny][nx]) continue;
            visited[ny][nx] = visited[cy][cx] + 1;
            q.push({ny,nx});
        }
    }
    
    return;
}


int main()
{
    cin >> N >> M;
    for(int i = 0 ; i < N; i++)
    {
        for(int j = 0 ; j < M; j++)
        {
            scanf("%1d",&adj[i][j]);
        }
    }


    BFS(0,0);
    cout << visited[N-1][M-1];
    return 0;
}