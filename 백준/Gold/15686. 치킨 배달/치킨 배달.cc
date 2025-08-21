#include <bits/stdc++.h>
using namespace std;

int n,m,cnt;
int a[51][51];
int visited[51][51],ret = 9999999;
vector<pair<int,int>> chiken;
vector<pair<int,int>> home;
vector<vector<int>> chickList;

void combi(int start, vector<int> b)
{

    if(b.size() == m)
    {
        chickList.push_back(b);
    }
    for(int i = start + 1; i < chiken.size() ; i++)
    {
        b.push_back(i);
        combi(i,b);
        b.pop_back();

    }

    return;
}

int go(int y, int x,vector<pair<int,int>> &chicken)
{
    int chickDist = 100;
    for(auto i : chicken)
    {
        int chikenY = i.first;
        int chikenX = i.second;
        //집 치킨 거리 계산
        int dist = abs(y - chikenY) + abs(x - chikenX);
        chickDist = min(chickDist,dist);
    }


    return chickDist;
}


int main()
{
    cin >> n >> m ;
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 2) chiken.push_back({i,j});
            if(a[i][j] == 1) home.push_back({i,j});
        
        }
    }
    //도시의 치킨 거리는 모든 집의 치킨 거리의 합
    //각각의 집은 치킨 거리를 가지고 있다
    //치킨 거리는 집과 가장 가까운 치킨집 사이의 거리
    //vector<pair<int,int>> chiken; 이거의 내용물의 모든 경우마다 실행해야함
    vector<int> b;
    combi(-1,b);
    
    
    // for(int i = 0 ; i< chickList.size(); i++)
    // {
    //     for(auto j : chickList[i])
    //     {
    //         cout << j <<" ";
    //     }
    //     cout <<"\n";
    // }
    for(int chick = 0 ; chick< chickList.size(); chick++)
    {
        vector<pair<int,int>> hi;
         for(auto j : chickList[chick])
        {
            hi.push_back(chiken[j]);
        }
      
        // for(auto h : hi)
        // {
        //     cout <<"h.first =" <<h.first<<", h.second ="<<h.second <<"\n";
        // }
        // cout <<"\n";
       
        
        int sum = 0;
        for(auto i : home)
        {
            sum += go(i.first,i.second, hi);
        }
        ret = min(ret,sum);
    }
    cout << ret;

    return 0;
}