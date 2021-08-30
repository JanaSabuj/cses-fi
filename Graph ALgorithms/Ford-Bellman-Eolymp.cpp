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
const int N = 105;
const int INF = LLONG_MAX;

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
void bellman_ford(int n, int m) {

	for (int i = 1; i <= n; ++i) {
		dist[i] = INF;
	}

	dist[1] = 0;
	for (int i = 0; i < n - 1; ++i) {
		// n - 1 relaxations
		for (int j = 0; j < m; j++) {
			auto e = veclist[j];
			// u -> v = w
			if (dist[e.u] < INF) {
				dist[e.v] = min(dist[e.v], dist[e.u] + e.wt);
			}
		}
	}
}


void solve() {
	int n, m;
	cin >> n >> m;

	int a, b, c;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		Edge e(a, b, c);
		veclist.push_back(e);
	}

	bellman_ford(n, m);
	for (int i = 1; i <= n; ++i) {
		if (dist[i] != INF) {
			cout << dist[i] << " ";
		} else
			cout << 30000 << " ";
	}
}

#define SABUJ_JANA_WF 1
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
