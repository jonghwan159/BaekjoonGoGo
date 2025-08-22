#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int visited[MAX+4];
long long cnt[MAX+4];

int main()
{

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    if(n == m)
    {
        puts("0");
        puts("1");
        return 0;
    }
    visited[n] = 1;
    cnt[n] = 1;
    queue<int> q;
    q.push(n);
    while(!q.empty())
    {
        int cx = q.front();
        q.pop();
        // cout << "cx = " << cx << ", cnt = " << cnt[cx] <<"\n";
        for(int nx :{cx+1,cx-1,cx*2} )
        {
            if(0 <= nx && nx <= 100000)
            {
                if(!visited[nx])
                {
                    q.push(nx);
                    visited[nx] =  visited[cx]+1;
                    cnt[nx] += cnt[cx];
                }
                //방문했고 값이 최단 거리이면
                else if(visited[nx] == visited[cx]+1 )
                {
                    cnt[nx] += cnt[cx];
                }
            }
        }
    }
    cout << visited[m] - 1 << "\n";
    cout << cnt[m] << " \n";
    return 0;

}