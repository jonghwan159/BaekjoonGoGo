#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(scanf("%d",&n) != EOF)
    {   
        ll ret = 1 ,cnt = 1;
        while(true){
            if(ret % n == 0)
            {
                cout << cnt <<"\n";
                break;
            } 
            else{
                ret = (ret *10) + 1;
                ret = ret % n;
                cnt++;
            }

        }
        
        
    }
    return 0;  
}