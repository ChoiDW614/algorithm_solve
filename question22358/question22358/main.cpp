#include <bits/stdc++.h>
#define FASTIO	ios_base::sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
using namespace std;
typedef long long ll;

vector<pair<ll, ll>> graph[100001];
pair<bool, ll> visited[100001];
vector<ll> saveTime;

void bfs(int start, int end, int K)
{
	queue<int> q;
	q.push(start);
	visited[start] = make_pair(true, 0);

	ll time = 0, time_max = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == end) {
			time = visited[x].second;
			saveTime.push_back(time);
		}
		for (int i = 0; i < graph[x].size(); i++) {
			if (!visited[graph[x][i].first].first || (visited[graph[x][i].first].second < visited[x].second + graph[x][i].second)) {
				q.push(graph[x][i].first);
				visited[graph[x][i].first] = make_pair(true, max(visited[graph[x][i].first].second, visited[x].second + graph[x][i].second));
			}
		}
	}

	if (!saveTime.empty()) {
		sort(saveTime.begin(), saveTime.end());
		cout << saveTime.back();
		return;
	}

	cout << -1;
}

void Solve()
{
	int N, M, K, S, T;
	ll a, b, t;
	cin >> N >> M >> K >> S >> T;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> t;
		graph[a].push_back(make_pair(b, t));
	}
	bfs(S, T, K);
}

int main()
{
	FASTIO;
	Solve();
	return 0;
}