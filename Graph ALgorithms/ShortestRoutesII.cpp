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
const int N = 507;
int adj[N][N];
int dis[N][N];
int n, m, q;

// floyd_warshall -> N <= 500
void floyd_warshall(int n, int m) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) dis[i][j] = 0;
			else if (adj[i][j]) dis[i][j] = adj[i][j];
			else dis[i][j] = LLONG_MAX;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (dis[i][k] < LLONG_MAX and dis[k][j] < LLONG_MAX)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

}

void solve() {
	cin >> n >> m >> q;
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		// multiple paths b/w same 2 nodes
		if (adj[a][b]) {
			adj[a][b] = min(adj[a][b], c);
			adj[b][a] = min(adj[b][a], c);
		} else {
			adj[a][b] = c;
			adj[b][a] = c;
		}
	}

	floyd_warshall(n, m);
	while (q--) {
		cin >> a >> b;
		if (dis[a][b] == LLONG_MAX)
			cout << -1 << endl;
		else
			cout << dis[a][b] << endl;
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