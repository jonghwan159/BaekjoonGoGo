#include <bits/stdc++.h>
using namespace std;
int n;
string s;
vector<string> v;
void go(string &ret)
{
    //숫자가 들어옴
    ///앞에 0인 경우 제거
    while(true)
    {
        if(ret.size() && ret.front() == '0')
        {
            ret.erase(ret.begin());
        } 
        else break;
    }
    if(ret.size() == 0)
    {
        ret = "0";
    }
    v.push_back(ret);
    ret = "";
    return;
}

bool cmp(string a, string b)
{
    if(a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> s;
        string ret = "";
        for(auto j : s)
        {
            //숫자 인지 문자인지 판별
            if(j >= '0' && j <='9')
            {
                //숫자이면
                ret += j;

            }
            else
            {
                //문자이면
                if(ret.size()) go(ret);
                
            }
        }
        //순회 했는데 남아있으면
        if(ret.size()) go(ret);
        
    }

    sort(v.begin(),v.end(),cmp);

    for(auto i : v)
    {
        cout << i <<"\n";
    }

    return 0;
}