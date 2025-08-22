#include <bits/stdc++.h>
using namespace std;
const int INF = -987654321;
int n, ret = INF;
char a[24];
vector<int> v;
vector<char> oper;
int calcul_oper(int num1 ,char oper, int num2)
{
    if(oper == '+') return num1 + num2; 
    if(oper == '-') return num1 - num2; 
    if(oper == '*') return num1 * num2; 

    return 0;
}

void go (int idx, int num)
{
    if(idx == v.size() - 1)
    {
        ret = max(ret, num);
        return;
    }
    go(idx+1,calcul_oper(num,oper[idx],v[idx+1]));
    if(idx+2 <= v.size() - 1 )
    {
    int temp = calcul_oper(v[idx+1],oper[idx+1],v[idx+2]);
    go(idx+2,calcul_oper(num,oper[idx],temp));
    }

    return;
}   


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        if(i % 2 ==0 )
        {
            //숫자만
            v.push_back(a[i] -'0');
        }
        else
        {
            //연산자
            oper.push_back(a[i]);
        }
    }
    go(0,v[0]);
    cout << ret;
   
    return 0;
}