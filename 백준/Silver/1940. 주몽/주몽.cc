#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    vector<int> material(N);
    for(int i = 0 ; i < N; i++) {
        cin >> material[i];
    }

    sort(material.begin(), material.end());

    int left = 0, right = N - 1;
    int ret = 0;

    while (left < right) {
        int sum = material[left] + material[right];
        if (sum == M) {
            ret++;
            left++;
            right--;
        } else if (sum < M) {
            left++;
        } else {
            right--;
        }
    }

    cout << ret;
    return 0;
}
