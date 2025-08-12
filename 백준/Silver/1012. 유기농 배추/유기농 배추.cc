#include <bits/stdc++.h>
using namespace std;
int N,M,T,K, visited[51][51], arr[51][51],ret;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
void DFS(int y, int x)
{
    if(visited[y][x]) return;
    visited[y][x] = 1;
    for(int i =0; i< 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny <0 || ny >=N || nx <0 || nx >= M || visited[ny][nx] || arr[ny][nx] == 0) continue;
        DFS(ny,nx);

    }
    return;
}


int main()
{
    cin >> T;
    while(T--)
    {   
        // 초기화 추가로 넣어야함
        fill(&arr[0][0], &arr[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);   
        ret = 0;
        cin >> M >> N >> K;
        for(int i=0 ; i < K ; i++)
        {
            int X, Y;
            cin >> X >> Y;
            arr[Y][X] = 1;

        }
        

        for(int i = 0 ; i < N; i++)
        {
            for(int j = 0 ; j < M; j++)
            {
               
                if(!visited[i][j] && arr[i][j]){
                    ret++;
                    DFS(i,j);
                }
            }
        }

        cout << ret << "\n";




    }
    
    
    
    return 0;

}