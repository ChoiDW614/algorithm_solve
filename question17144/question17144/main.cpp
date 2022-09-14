#include <bits/stdc++.h>
#define FASTIO  ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
using namespace std;

int R, C, T;

void clear(vector<vector<int>>& v) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            v[i][j] = 0;
        }
    }
}

void graphPrint(vector<vector<int>>& v) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C - 1; j++) {
            cout << v[i][j] << ' ';
        }
        cout << v[i][C - 1];
        cout << '\n';
    }
}

void diffusion(vector<vector<int>>& v)
{
    vector<vector<int>> v2;
    clear(v2);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int cnt = 0;
            if (j != 0 && v[i][j - 1] != -1) {
                v2[i][j] += v[i][j - 1] / 5;
                cnt++;
            }
            if (j != C - 1 && v[i][j + 1] != -1) {
                v2[i][j] += v[i][j + 1] / 5;
                cnt++;
            }
            if (i != 0 && v[i - 1][j] != -1) {
                v2[i][j] += v[i - 1][j] / 5;
                cnt++;
            }
            if (i != R - 1 && v[i + 1][j] != -1) {
                v2[i][j] += v[i + 1][j] / 5;
                cnt++;
            }
        }
    }
}


void Solve()
{
    cin >> R >> C >> T;
    int input;
    vector<vector<int>> graph, graph2;

    for (int i = 0; i < R; i++) {
        vector<int> v;
        for (int j = 0; j < C; j++) {
            cin >> input;
            v.push_back(input);
        }
        graph.push_back(v);
    }
    diffusion(graph);
    graphPrint(graph);


    cout << 'd';


}

int main()
{
    FASTIO;
    Solve();
    return 0;
}