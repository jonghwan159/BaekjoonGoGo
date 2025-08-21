#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
char a[54][54];
int visited[54][54];
int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};
vector<pair<int,int>> groundList;
vector<vector<int>> treasureList;
int maxVisited()
{
    int mx = -1;
    for(auto ground : groundList)
    {
            mx = max(mx,visited[ground.first][ground.second]);
    }
    return mx;
}

void BFS(int treasure1Y,int treasure1X)
{
    queue<pair<int,int>> q;
    q.push({treasure1Y,treasure1X});
    visited[treasure1Y][treasure1X] = 1;
    while(q.size())
    {
        int cx,cy;
        tie(cy,cx) = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ;i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny <0 || ny >=n || nx<  0 || nx >= m || visited[ny][nx] || a[ny][nx] == 'W') continue;
            visited[ny][nx] = visited[cy][cx] + 1;
            q.push({ny,nx});

        }
    }
   
    return ;


}


void combi(int start, vector<int> &b)
{
    if(b.size() == 2)
    {
        treasureList.push_back(b);
        return;
    }
    for(int i = start + 1; i < cnt ; i++)
    {
        b.push_back(i);
        combi(i,b);
        b.pop_back();
    }

    return;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0 ; i < n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0 ; j <m ; j++)
        {
            a[i][j] = s[j];
            if(a[i][j] == 'L')
            {
                groundList.push_back({i,j});
                cnt++;
            } 
        }
    }
    int ret = -1;
    for(auto ground : groundList )
    {
        memset(visited,0,sizeof(visited));
        int distTime = 0;
        int treasureY = ground.first;
        int treasureX = ground.second;
        BFS(treasureY,treasureX);
        distTime = maxVisited() - 1;
        // print();
        ret = max(ret,distTime);
        // cout << "ret = "<< ret <<"\n";

        // cnt1++;
    }
    cout << ret;
    return 0;
}