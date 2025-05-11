#include <bits/stdc++.h>
using namespace std;
string str1, str2;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> str1;
    str2 = str1;
    reverse(str2.begin(),str2.end());
    if(str1 == str2) cout << 1;
    else cout << 0;
    return 0;
}