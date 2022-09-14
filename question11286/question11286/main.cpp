#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);    cin.tie(NULL);  cout.tie(NULL);
using namespace std;

struct comp
{
    bool operator()(int &a, int &b) {
        if (abs(a) == abs(b)) {
            return a > b;
        }
        else
            return abs(a) > abs(b);
    }
};

void Solve()
{
    priority_queue<int, vector<int>, comp> que;
    int N, input;
    cin >> N;
    while (N--) {
        cin >> input;
        if (input != 0) {
            que.push(input);
        }
        else {
            if (que.empty())
                cout << 0 << '\n';
            else {
                cout << que.top() << '\n';
                que.pop();
            }
        }
    }
}

int main()
{
    FASTIO;
    Solve();
    return 0;
}