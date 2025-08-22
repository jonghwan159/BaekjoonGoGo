#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int r,c,x,y;
char a[1004][1004];
int people_visited[1004][1004], fire_visited[1004][1004];
pair<int,int> start_point;
vector<pair<int,int>> fire_point;
queue<pair<int,int>> q;
int dy[] = {1, 0 , -1 ,0};
int dx[] = {0, 1 , 0 ,-1};
void printPeople()
{
    for(int i =0 ;i< r ;i++)
    {
        for(int j = 0 ; j< c ; j++)
        {
            cout << people_visited[i][j] <<" ";
        }
        cout <<"\n";
    }
    return;
}
void printFire()
{
     for(int i =0 ;i< r ;i++)
    {
        for(int j = 0 ; j< c ; j++)
        {
            cout << fire_visited[i][j] <<" ";
        }
        cout <<"\n";
    }
    return;
}

int main()
{
    cin >> r >> c;
    fill(&fire_visited[0][0],&fire_visited[0][0] + 1004 * 1004, INF);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i =0 ;i< r ;i++)
    {
        for(int j = 0 ; j< c ; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 'J') start_point = {i,j};
            else if(a[i][j] == 'F')
            {
                fire_point.push_back({i,j});
                q.push({i,j});
                fire_visited[i][j] = 1; 
            } 
        }
    }
    //불 BFS
    while(q.size())
    {
        tie(y,x) = q.front();
        q.pop();
        for(int i =0 ; i < 4 ; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >=r || nx <0 || nx >=c || fire_visited[ny][nx] != INF || a[ny][nx] == '#') continue;
            fire_visited[ny][nx] = fire_visited[y][x] + 1;
            q.push({ny,nx});
        }
    }
    //printFire();
    q.push({start_point.first,start_point.second});
    people_visited[start_point.first][start_point.second] = 1;
    //사람 BFS;
    while(q.size())
    {
        tie(y,x) = q.front();
        q.pop();
        if(y == 0 || y == r-1 || x == 0 || x == c-1)
        {
            cout << people_visited[y][x] <<"\n";
            //rintPeople();
            return 0;
        }
        for(int i =0 ; i < 4 ; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >=r || nx <0 || nx >=c || people_visited[ny][nx] || a[ny][nx] != '.') continue;
            if(fire_visited[ny][nx] <= people_visited[y][x] + 1) continue;
            people_visited[ny][nx] = people_visited[y][x] + 1;
            q.push({ny,nx});
        }
    }
    cout << "IMPOSSIBLE" <<"\n";
 

    return 0;
}