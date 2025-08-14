#include <bits/stdc++.h>
using namespace std;
// 숫자, 개수, 인덱스
map<int, pair<int,int>> m;
vector<pair <int, int>> v;
int n,c;
bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.second == b.second)
    {
        //개수가 같을 경우 인덱스 빠른 순서
        return m[a.first].second < m[b.first].second;
    }
    return a.second > b.second;
}
int main()
{
    cin >> n >> c;
    for(int i = 0 ; i< n ;i++)
    {
        int temp;
        cin >> temp;
        m[temp].first++;
        if(m[temp].first == 1) m[temp].second = i + 1;
    }
    for(auto i : m)
    {
        //cout << "숫자 = " << i.first << ", 개수 = " << i.second.first << ", 인덱스 = " << i.second.second <<"\n";
        //숫자, 개수 삽입
        v.push_back({i.first,i.second.first});
    }

    sort(v.begin(),v.end(),cmp);
    //출력
    for (auto i : v)
    {
        //개수 만큼 반복
        for(int j = 0 ; j < i.second ;j++) cout << i.first << " ";
    }

    
    return 0;
}