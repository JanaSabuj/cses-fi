/*
Sabuj Jana / @greenindia
https://www.janasabuj.github.io
*/
#include <bits/stdc++.h>
using namespace std;
#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long int
#define double long double
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
#define endl "\n"
void print1d(const vector<int>& vec) {for (auto val : vec) {cout << val << " ";} cout << endl;}
void print2d(const vector<vector<int>>& vec) {for (auto row : vec) {for (auto val : row) {cout << val << " ";} cout << endl;}}
const int mod = 1e9 + 7;
const int N = 1e5 + 7;
int n, m, k;
vector<pii> adj[N];
priority_queue<pii, vector<pii>, greater<pii>> pq;
vi dis[N];// vector of dist[i]
void dijkstra(int src) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < k; ++j) {
			dis[i].push_back(LLONG_MAX);
		}
	}

	pq.push({0, src});
	dis[src][0] = 0;

	while (!pq.empty()) {
		auto curr = pq.top();
		pq.pop();

		int v = curr.second;
		int d_v = curr.first;
		if (d_v > dis[v][k - 1])
			continue;// stale pair

		for (auto u : adj[v]) {
			int to = u.first;
			int len = u.second;

			if (d_v + len < dis[to][k - 1]) {
				dis[to][k - 1] = d_v + len;
				pq.push({dis[to][k - 1], to});
				sort(dis[to].begin(), dis[to].end());
			}
		}
	}
}
void solve() {
	cin >> n >> m >> k;
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}

	dijkstra(1);
	for (int i = 1; i <= k; i++) {
		cout << dis[n][i - 1] << " ";
	}
}

#define SABUJ_JANA_WxF 1
signed main() {
	crap;
#ifdef SABUJ_JANA_WF
	auto start = chrono::high_resolution_clock::now();
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); freopen("error.txt", "w", stderr);
#endif

	int t = 1;
	// cin >> t;
	while (t--) solve();

#ifdef SABUJ_JANA_WF
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	cerr << "Time taken :\n" << duration.count() / 1000000.0 << "s" << "\n";
#endif
	return 0;
}