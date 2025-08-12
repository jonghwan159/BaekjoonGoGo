#include <bits/stdc++.h>
using namespace std;

int N, visited[101][101], arr[101][101],arrTest[101][101], minVal = 101, maxVal = -1,safeRet;

int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};


void DFS(int y , int x)
{
    if(visited[y][x]) return;
    visited[y][x] = 1;

    for(int i = 0 ; i < 4 ; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny <0 || ny >= N || nx <0 || nx >=N || visited[ny][nx] || arrTest[ny][nx]) continue;
        DFS(ny,nx);
    }

    return;
}


int main()
{   
    cin >> N;
    for(int i = 0 ; i < N; i++)
    {
        for(int j =0 ; j < N; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j]< minVal)
            {
                minVal = arr[i][j];
            }
            if(arr[i][j]> maxVal)
            {
                maxVal = arr[i][j];
            }
        }
    }

    // cout << "minVal = "<< minVal<< ", maxVal = "<<maxVal<<"\n";

    //내리는 비의 양에 따른 모든 경우를 다 조사
    //최소 값과 최대값을 뽑고 그 사이의 모든 값을 해봐야
    if(minVal == maxVal)
    {
        //모든 영역의 값이 동일한 경우
        cout << "1";
        return 0;

    }
    for(int drownHeight = minVal; drownHeight <= maxVal; drownHeight++)
    {
        // 초기화
        fill(&arrTest[0][0], &arrTest[0][0] + 101 * 101, 0);
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
        int ret =0;
        
        for(int i = 0 ; i < N; i++)
        {
            for(int j =0 ; j < N; j++)
            {
               if(arr[i][j] <= drownHeight)
               {
                    //잠겨있다 = 1
                    arrTest[i][j] = 1;
               }
            }
        }
        // cout << "drownHeight = " << drownHeight <<"\n";
        // for(int i = 0 ; i < N; i++)
        // {
        //     for(int j =0 ; j < N; j++)
        //     {
        //         cout<< arrTest[i][j] << " ";  
        //     }
        //     cout << "\n";
        // }

        //안전한 영역 계산 0으로 되어있는 곳 DFS
        for(int i = 0 ; i < N; i++)
        {
            for(int j =0 ; j < N; j++)
            {
               if(!visited[i][j] && arrTest[i][j] == 0)
               {
                    DFS(i,j);
                    ret++;
               }
            }
        }
        // cout << "ret = "<<ret<<"\n";
        if(ret > safeRet)
        {
            safeRet = ret;
        }



    }

    cout << safeRet;


    return 0;

}