#include <bits/stdc++.h>
using namespace std;
int N,K;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin >> K;
    vector<int> arr(N);
    for(int i = 0 ; i <N;i++)
    {
        cin >> arr[i];
        
    }
    int window_sum = 0;
    for(int i =0 ;  i< K;i++)
    {
        window_sum += arr[i];
    }
    int max_sum = window_sum;
    
    for(int i = K; i < N; i++)
    {
        window_sum += arr[i] - arr[i - K];
        max_sum = max(max_sum, window_sum);
    }
    cout <<max_sum;
    return 0;
}