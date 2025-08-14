#include <bits/stdc++.h>
using namespace std;

int n,winTeam,teamScore[2],sum_1,sum_2;
string s, prevStr;
string print(int sum)
{
    string a = "00" + to_string(sum/60);
    string b = "00" + to_string(sum%60);
    return a.substr(a.size()-2,2)+":"+b.substr(b.size()-2,2);
}
int calculSecond(string a)
{
    return atoi(a.substr(0,2).c_str())*60 + atoi(a.substr(3,2).c_str());
}

void go(int &sum, string s)
{
    sum += (calculSecond(s) - calculSecond(prevStr));
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i =0 ; i< n ;i++)
    {
        cin >> winTeam >> s;
        //cout << "i ="<< i << ", teamScore[0]  = "<< teamScore[0] << ", teamScore[1] = "<< teamScore[1] << "\n";
        //cout << "s = " << s << ", prevStr = " <<prevStr<<"\n";
        if(teamScore[0] > teamScore[1]) go(sum_1,s);
        else if(teamScore[0] < teamScore[1]) go(sum_2,s);
        //cout << "sum_1 = " << sum_1 << ", sum_2 = " <<sum_2<<"\n\n";
        winTeam == 1 ? teamScore[0]++ : teamScore[1]++;
        prevStr = s;
    }
    s = "48:00";
    if(teamScore[0] > teamScore[1]) go(sum_1,s);
    else if(teamScore[0] < teamScore[1]) go(sum_2,s);
    cout << print(sum_1)<<"\n"<< print(sum_2)<<"\n";
    return 0;
}