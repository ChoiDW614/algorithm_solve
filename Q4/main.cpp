#include <iostream>
using namespace std;

#define MAX_LEN 101

int N;
int maxNum;
int Arr[MAX_LEN];

void inputNum()
{
    cin >> N;
    cin >> maxNum;
    for(int i = 0; i< N; i++)
    {
        cin >> Arr[MAX_LEN];
    }
}

void solve()
{
    int sum=0;
    
    for(int i = 0; i <N-2; i++)
    {
        for(int j=i+1; j<N-1; j++)
        {
            for(int k=j+1; k<N; k++)
            {
                if(Arr[i]+Arr[j]+Arr[k] >= sum && Arr[i]+Arr[j]+Arr[k] <= maxNum)
                    sum = (Arr[i]+Arr[j]+Arr[k]);
            }
        }
    }
    cout << sum;
}

void solution()
{
    inputNum();
    solve();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();
    return 0;
}