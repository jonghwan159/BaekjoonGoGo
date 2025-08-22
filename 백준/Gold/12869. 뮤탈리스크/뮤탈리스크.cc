#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int a[64][64][64], scv[3], n ,visited[64][64][64];
int scv1,scv2,scv3;
int dp[6][3] = 
{
	{9, 3, 1}, 
	{9, 1, 3}, 
	{3, 1, 9}, 
	{3, 9, 1}, 
	{1, 3, 9}, 
	{1, 9, 3}
};

struct A
{
    int a, b, c;
};
queue<A>q;


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0 ; i <n ; i++)
    {
        cin >> scv[i];
    }
    visited[scv[0]][scv[1]][scv[2]] = 1;
    q.push({scv[0],scv[1],scv[2]});
    while(q.size())
    {
        scv1 = q.front().a;
        scv2 = q.front().b;
        scv3 = q.front().c;
        q.pop();
        if(visited[0][0][0])
        {
            cout <<  visited[0][0][0] - 1  << "\n";
            return 0;
        }
        for(int i =0 ; i < 6 ; i++)
        {
            int nscv1 = max(0,scv1 - dp[i][0]); 
            int nscv2 = max(0,scv2 - dp[i][1]); 
            int nscv3 = max(0,scv3 - dp[i][2]); 
            if(visited[nscv1][nscv2][nscv3]) continue;
            visited[nscv1][nscv2][nscv3] = visited[scv1][scv2][scv3] +1;
            q.push({nscv1,nscv2,nscv3});
            //cout << nscv1 << " : "<< nscv2 << " : "<< nscv3<< " visited =" <<  visited[nscv1][nscv2][nscv3] <<"\n";
            
        }
    }

    return 0;
}