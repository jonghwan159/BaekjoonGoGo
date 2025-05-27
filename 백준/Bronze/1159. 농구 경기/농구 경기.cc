#include <bits/stdc++.h>
using namespace std;
map<char, int> searchMap;
int N, cnt;
int main()
{
    cin >> N;
    for(int i =0 ; i < N; i++)
    {
        string temp;
        cin >> temp;
        searchMap[temp[0]]++;
    }

    for(auto it : searchMap)
    {
        if(it.second >= 5)
        {
            cout << it.first;
             cnt++;
        }
       
    }

    if(cnt == 0)
    {
        cout << "PREDAJA";
    }
}