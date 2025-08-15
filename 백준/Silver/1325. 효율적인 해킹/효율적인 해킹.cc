#include <bits/stdc++.h>
using namespace std;

int n, m,a[10004],mx;
vector<int> adj[10004];
int visited[10004];

int DFS(int here)
{
    if(visited[here]) return 0;
    visited[here] = 1;
    int ret = 1;
    for(auto there : adj[here])
    {   
        ret += DFS(there);
       
    }

    return ret;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >>  m;
    for(int i = 0 ; i < m; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        adj[temp2].push_back(temp1);
    }
    
    for(int i =1 ; i <= n ; i++)
    {
        memset(visited,0,sizeof(visited));
        a[i] = DFS(i);
        mx = max(a[i], mx);
    
    }
    for(int i = 1 ; i <= n ;i++)
    {
        if(a[i] == mx)
        {
            cout << i << " ";
        }
    }

    return 0;
}