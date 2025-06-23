#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase;
    cin >> testcase;
    for(int i = 0 ; i < testcase; i++)
    {
        int clothes;
        cin >> clothes;
        map<string,int> dress;
        string dump1,dump2;
        for(int j =0; j <clothes; j++){
            cin >> dump1 >> dump2;
            dress[dump2]++;
        }
        int ret = 1;
        for(auto val : dress)
        {
            ret *= (val.second + 1);
        }

        ret--;
        cout << ret<<'\n';
        
    }
    return 0;
}