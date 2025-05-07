#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(25);
    for(int i =0 ; i<  n; i++)
    {
        int index;
        index = s[i] - 'a';
        a[index]++;
    }    

    for(int i = 0 ; i < 26 ; i++)
    {
        cout << a[i] << " ";
    }

}