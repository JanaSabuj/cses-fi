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
const int N = 2507;
int n, m;
struct Edge {
	int u, v, wt;
	bool operator<(Edge const& e) {
		return wt < e.wt;
	}
	Edge(int a, int b, int c) {
		u = a;
		v = b;
		wt = c;
	}
};
vector<Edge> veclist;

int dist[N];
const int INF = 1e17;
const int NINF = INF * -1;
void bellman_ford(int src) {
	for (int i = 0; i < n + 2; ++i) {
		dist[i] = INF;
	}
	dist[src] = 0;

	// 1. Propagation phase
	int x = -1;
	for (int i = 0; i < n; ++i) {
		x = -1;
		for (auto e : veclist) {
			int u = e.u;
			int v = e.v;
			int wt = e.wt;

			if (dist[u] == INF) continue;
			if (dist[u] + wt < dist[v]) {
				dist[v] = dist[u] + wt;
				dist[v] = max(dist[v], NINF);// lower bound of minima - NINF
				x = v;
			}
		}
	}

	if (x == -1) {
		// no neg cycle
		cout << -dist[n] << endl;
		return;
	} else {
		//2. Neg cycle resolution phase
		for (int i = 0; i < n - 1; ++i) {
			for (auto e : veclist) {
				int u = e.u;
				int v = e.v;
				int wt = e.wt;

				if (dist[u] == INF) continue;
				// dist[v] = max(dist[v], NINF);
				if (dist[u] + wt < dist[v]) {
					dist[v] = NINF;// v is part of a neg cycle / reachable from neg cycle
				}
			}
		}

		if (dist[n] == NINF)
			cout << -1 << endl;
		else
			cout << -dist[n] << endl;
	}

	return;
}

void solve() {
	cin >> n >> m;
	int a, b, c;
	// SSLP = -1 * SSSP
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		Edge e(a, b, -c);
		veclist.push_back(e);
	}

	bellman_ford(1);
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