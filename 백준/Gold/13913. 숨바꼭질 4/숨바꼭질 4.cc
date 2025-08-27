#include <bits/stdc++.h>
using namespace std;
#define prev aaaa
#define next aaa
const int MAX = 200004;
int n,k;
int visited[MAX];
queue<int> q;
int prev[MAX];
vector <int> v;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >>  n >> k;
    
    q.push(n);
    visited[n] = 1;
    while(!q.empty())
    {
        int here = q.front();
        q.pop();
        if(here == k)
        {
            break;
        }
        for(auto next : {here + 1,here - 1, 2 * here })
        {
            if(next < 0 || next >= MAX || visited[next]) continue;
            q.push(next);
            visited[next] = visited[here] + 1;
            prev[next] = here;

        }
    }
    cout << visited[k] -1 <<"\n";
    for(auto i = k ; i != n ; i = prev[i]) v.push_back(i);
    v.push_back(n);
    reverse(v.begin(),v.end());
    for(auto i : v) cout << i << " ";
    cout <<"\n";
    return 0;
}