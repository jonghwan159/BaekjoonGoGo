#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
char a[1004][1004];
int n,m,sx,sy,y,x,ret;
int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};
//불과 
int fire_visited[1004][1004], person_visited[1004][1004];

bool check_side(int y, int x)
{
    if(y ==0 || x == 0 || y == n -1 || x == m-1) return 1;

    return 0;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    queue<pair<int,int>> q;
    cin >> n >> m;
    fill(&fire_visited[0][0],&fire_visited[0][0] + 1004 * 1004, INF);
    for(int i =0 ; i <n ; i++)
    {
        for(int j =0 ; j < m ; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 'F')
            {
                fire_visited[i][j] = 1;
                q.push({i,j}); 
            }
            else if(a[i][j] == 'J')
            {
                sy = i;
                sx = j;
            }
        }
    }

    //불 BFS
    while(q.size())
    {
        tie(y,x) = q.front();
        q.pop();
        for(int i = 0 ; i < 4; i++)
        {
           	int ny = y + dy[i];
			int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || fire_visited[ny][nx] != INF || a[ny][nx] == '#') continue;
            fire_visited[ny][nx] = fire_visited[y][x] + 1;
            q.push({ny,nx}); 
        }
    }
    // queue에 아무것도 없음 이제
    person_visited[sy][sx] = 1;
    q.push({sy,sx});
    while(q.size())
    {
        tie(y,x) = q.front();
        q.pop();
        if(check_side(y,x))
        {
            ret = person_visited[y][x];
            break;
        }

        for(int i = 0 ; i < 4; i++)
        {
           	int ny = y + dy[i];
			int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || person_visited[ny][nx] || a[ny][nx] == '#') continue;
            if(fire_visited[ny][nx] <= person_visited[y][x] + 1) continue;
            person_visited[ny][nx] = person_visited[y][x] + 1;
            q.push({ny,nx}); 
        }
    }
    if(ret != 0) cout << ret<<"\n";
    else cout << "IMPOSSIBLE \n";
    return 0;
}
