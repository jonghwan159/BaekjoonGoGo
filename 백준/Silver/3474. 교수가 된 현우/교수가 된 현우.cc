#include <bits/stdc++.h>
using namespace std;
int ret_2,ret_5;
int n,t;


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;

    while(t--)
    {
        ret_2 =0, ret_5=0;
        cin >> n;
        for(int i = 2; i<= n ; i *= 2)
        {
            ret_2 += n/i;
        }

        for(int i = 5; i<= n ; i *= 5)
        {
            ret_5 += n/i;
        }
        cout << min(ret_2,ret_5)<<"\n";
    }    
    



    return 0;
}