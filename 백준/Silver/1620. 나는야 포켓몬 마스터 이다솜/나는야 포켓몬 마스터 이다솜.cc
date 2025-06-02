#include <bits/stdc++.h>
using namespace std;
int n,m, cnt;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    vector<string> arr(n+1);
    unordered_map<string, int> name_to_index;
    for(int i = 1; i <= n ; i++)
    {
         cin >> arr[i];
         name_to_index[arr[i]] = i;      
    }

    for(int i = 1 ; i <= m ; i++)
    {
           //문자 구분 -> atoi(srting.c_str())
           string temp1;
           cin >> temp1;
           //숫자인 경우 1
           if(atoi(temp1.c_str()))
           {   
               int temp_int = atoi(temp1.c_str());
               cout << arr[temp_int] << '\n';
           }
           else
           {
               //문자인 경우
               // 숫자 출력
               cout << name_to_index[temp1] <<'\n';
               
           }
    }
    return 0;
}