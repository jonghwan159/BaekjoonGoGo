#include <bits/stdc++.h>
using namespace std;

int n = 9, k = 7;
int key = 0;
vector<int> v;
void print(vector<int>b)
{
    for(int i : b) cout << i << " ";
    cout << "\n";
}

void combi (int start, vector<int> &b)
{
    if(key == 1)
    {
        return;
    }
    if(b.size() == k)
    {
        //logic
        int sum = 0;
        
        for(int i = 0 ; i < k ; i++)
        {
            sum += v[b[i]];
        }

        if(sum == 100)
        {
            key = 1;
            vector<int> answer;
            for(int i = 0 ; i < k ; i++)
            {
                answer.push_back(v[b[i]]);
            }
            sort(answer.begin(),answer.end());
            for(int i = 0 ; i < k ; i++)
            {
                cout<< answer[i]<<"\n";
            }
        }
        return;
    }

    for(int i = start+1 ; i < n ; i++)
    {
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
    return;
}

int main ()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i = 0 ; i < 9 ; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    vector<int> b;
    combi(-1,b);
    return 0 ;
}