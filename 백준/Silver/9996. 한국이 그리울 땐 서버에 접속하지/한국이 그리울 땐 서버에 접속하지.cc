#include <bits/stdc++.h>
using namespace std;
int N, trigger;
vector<char> arr1, arr2;
vector<string> str_arr;
string pattern;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin >> pattern;
    for(int i = 0 ; i < pattern.size(); i++)
    {
        if(pattern[i] == '*')
        {
            trigger = 1;
            continue;
        }
        if(trigger)
        {
          arr2.push_back(pattern[i]);  
        }
        else
        {
          arr1.push_back(pattern[i]);    
        }
    }
    // for(int i = 0; i< arr1.size();i++)
    //     {
    //         cout << arr1[i];
    //     }
    // cout <<"\n";

    //  for(int i = 0; i< arr2.size();i++)
    //     {
    //         cout << arr2[i];
    //     }
    // cout <<"\n";

    int minSize = arr1.size()+arr2.size();
    for(int i =0 ;i < N; i++)
    {
        string tempStr;
        cin >> tempStr;
        str_arr.push_back(tempStr);
    }

    for(auto kStr : str_arr)
    {   
        
        int isOK =1;
        if(kStr.size() < minSize)
        {
            cout << "NE\n";
            continue;
        }
        //검사
        for(int i = 0 ; i<arr1.size();i++)
        {
            if(arr1[i] != kStr[i])
            {
                isOK = 0;
                break;
            }
        }
        if(isOK){
            int max_index = kStr.size()-1;
            
            for(int i = arr2.size()-1 ; i>= 0;i--)
            {   
                if(arr2[i] != kStr[max_index--])
                {
                    
                    isOK = 0;
                    break;
                }
            }
        }
       if(isOK == 0)
       {
           cout << "NE\n"; 
       }
       else
       {
            cout << "DA\n";      
       }
    }
    
}