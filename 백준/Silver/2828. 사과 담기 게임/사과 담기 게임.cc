#include <bits/stdc++.h>
using namespace std;
int n,m,J;
int screen[11], l =1 ,r,ret;
int main()
{
    cin >> n >> m;
    cin >> J;
    r = m;
    for(int i =0; i < J; i++)
    {
        int applePos;
        cin >> applePos;

       
        if(applePos > r)
        {
            ret += (applePos - r);
            l += (applePos - r);
            r = applePos;
        }
        else if(applePos < l)
        {
            ret += (l - applePos);
            r -= (l - applePos);
            l = applePos;
            
        }
        //cout <<"i = " << i <<", ret = " << ret<<",l = "<<l<<",r = "<<r <<"\n";
    }
    cout << ret;
    return 0;
}