#include <bits/stdc++.h>
using namespace std;

int Acnt, Bcnt, Ccnt, A, B ,C, Min = 101, Max = -1;
int Cnt[301];
vector<pair<int,int>> v(3);
int main()
{
    cin >> A >> B >> C;
    for(int i = 0 ; i < 3; i++) cin >> v[i].first >> v[i].second;
    
    for(auto t : v){
       // cout << "t.first = " << t.first <<" t.second =" << t.second << "\n";
        if (Min > t.first) Min = t.first;
        if (Max < t.second) Max = t.second;
        for(int i = t.first ; i < t.second ; i++)
        {
            Cnt[i]++;
        }
    }
  
    //cout<< "Min = " << Min << " Max = " << Max << "\n"; 
    for(int i = Min; i < Max; i++)
    {
        if(Cnt[i] == 1) Acnt++;
        else if(Cnt[i] == 2) Bcnt++;
        else if(Cnt[i] == 3) Ccnt++;
    }
    int answer = Acnt * A + Bcnt * B *2 + Ccnt * C * 3;

    cout << answer << "\n";
    return 0;
}