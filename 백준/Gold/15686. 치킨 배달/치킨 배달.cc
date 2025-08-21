#include <bits/stdc++.h>
using namespace std;

int n,m,a[54][54], result = 9e8;
vector<pair<int,int>> _home,chiken;
vector<vector<int>> chickenList;

void combi(int start, vector<int> b)
{

    if(b.size() == m)
    {
        chickenList.push_back(b);
        return;
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
            if(a[i][j] == 1) _home.push_back({i,j});
        
        }
    }
    //도시의 치킨 거리는 모든 집의 치킨 거리의 합
    //각각의 집은 치킨 거리를 가지고 있다
    //치킨 거리는 집과 가장 가까운 치킨집 사이의 거리
    //vector<pair<int,int>> chiken; 이거의 내용물의 모든 경우마다 실행해야함
    vector<int> b;
    combi(-1,b);
    
    
    for(auto cList : chickenList)
    {
        int sum = 0;
        for(auto home : _home)
        {
            int chickDist = 100;
            for(auto ch : cList)
            {
                int chikenY = chiken[ch].first;
                int chikenX = chiken[ch].second;
                //집 치킨 거리 계산
                int dist = abs(home.first - chikenY) + abs(home.second - chikenX);
                chickDist = min(chickDist,dist);
            }
            sum += chickDist;
        }
        result = min(result,sum);
    }
    cout << result;

    return 0;
}