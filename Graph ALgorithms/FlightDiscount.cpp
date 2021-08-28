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

vector<pii> adj[N];
vector<pii> adj2[N];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int dis[N][2];

void dijkstra1(int src) {
	for (int i = 0; i < N; ++i) {
		dis[i][0] = LLONG_MAX;
	}

	pq.push({0, src});
	dis[src][0] = 0;

	while (!pq.empty()) {
		auto curr = pq.top();
		pq.pop();

		int v = curr.second;
		int d_v = curr.first;
		if (d_v != dis[v][0])
			continue;// stale pair

		for (auto u : adj[v]) {
			int to = u.first;
			int len = u.second;

			if (dis[v][0] + len < dis[to][0]) {
				dis[to][0] = dis[v][0] + len;
				pq.push({dis[to][0], to});
			}
		}
	}
}

void dijkstra2(int src) {
	for (int i = 0; i < N; ++i) {
		dis[i][1] = LLONG_MAX;
	}

	pq.push({0, src});
	dis[src][1] = 0;

	while (!pq.empty()) {
		auto curr = pq.top();
		pq.pop();

		int v = curr.second;
		int d_v = curr.first;
		if (d_v != dis[v][1])
			continue;// stale pair

		for (auto u : adj2[v]) {
			int to = u.first;
			int len = u.second;

			if (dis[v][1] + len < dis[to][1]) {
				dis[to][1] = dis[v][1] + len;
				pq.push({dis[to][1], to});
			}
		}
	}
}

int n, m;
void solve() {
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj2[b].push_back({a, c});
	}

	dijkstra1(1);
	while (!pq.empty())
		pq.pop();
	dijkstra2(n);

	// final ans
	// for (int i = 1; i <= n; i++) {
	// 	cout << dis[i][0] << "-" << dis[i][1] << endl;
	// }

	int ans = LLONG_MAX;
	// cout << ans << endl;
	for (int i = 1; i <= n; ++i) {
		for (auto e : adj[i]) {
			int j = e.first;
			int wt = e.second;

			ans = min(ans, dis[i][0] + (wt / 2) + dis[j][1]);
			// ans = min(ans, dis[i][1] + (wt / 2) + dis[j][0]);
		}
	}

	cout << ans << endl;
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