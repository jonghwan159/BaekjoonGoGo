#include <bits/stdc++.h>
using namespace std;

int n, root,r;
vector<int> adj[54];


int DFS(int here)
{
   

    int ret = 0;
    int cnt = 0;
    for(auto there : adj[here])
    {   
        //자식이 있으면 먹음
        if(r == there) continue;
        cnt++;
        ret += DFS(there);
    }
    //기저 사례
    if(cnt ==0) return 1;

   

    return ret;
}
int main()
{
    cin >> n;
    for(int i = 0 ; i < n; i++)
    {
        int temp;
        cin >> temp;
        if(temp == -1) root = i;
        adj[temp].push_back(i);
    }
    cin >> r;
    if(root == r) 
    {   
        cout << 0;
        return 0;
    }
    else{
        cout << DFS(root);  
    }
    return 0;
}