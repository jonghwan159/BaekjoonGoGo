#include <bits/stdc++.h>
using namespace std;

int A,B,C,Acnt,Bcnt,Ccnt;
int Min = -1, Max = -1;
vector<pair<int,int>> timeArr(3);
int cnt[300];

int main()
{   
    ios :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B >> C ;
    for(int i = 0 ; i < 3 ; i++) cin >> timeArr[i].first >> timeArr[i].second;

    for(auto t : timeArr)
    {
        if(Min > t.first) Min = t.first;
        if(Max < t.second) Max = t.second;

        for(int i = t.first -1 ; i < t.second-1; i++) cnt[i]++;
        
    }

    for(int i = Min-1;  i < Max-1 ; i++ )
    {
        if(cnt[i] == 1) Acnt++;
        if(cnt[i] == 2) Bcnt++;
        if(cnt[i] == 3) Ccnt++;

        
    }

    //calcul
    int answer = A*Acnt + 2*B*Bcnt + 3*C*Ccnt;
    cout << answer;
    return 0;
}