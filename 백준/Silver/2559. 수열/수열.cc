#include <bits/stdc++.h>
using namespace std;

int N,K,temp,psum[100004], ret = - 10000004;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for(int i = 1 ; i <= N ; i++)
    {
        cin >> temp; psum[i] = psum[i-1] + temp;
    }

    for(int i = K ; i <= N ; i++)
    {
            ret = max(ret, psum[i] - psum[i - K]);   
    }
    cout << ret ;

    return 0;
}