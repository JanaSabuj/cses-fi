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
#define endl "\n"
void print1d(const vector<int>& vec) {for (auto val : vec) {cout << val << " ";} cout << endl;}
void print2d(const vector<vector<int>>& vec) {for (auto row : vec) {for (auto val : row) {cout << val << " ";} cout << endl;}}
const int mod = 1e9 + 7;
vi adj[100005];
int color[100005];
int n, m;

// 2 colors the cc & returns T/F if possible
bool bip(int x, int c) {
	color[x] = c;

	for (auto u : adj[x]) {
		if (!color[u]) {
			if (!bip(u, (c == 1 ? 2 : 1)))
				return false;
		} else if (color[u] == c) {
			return false;
		}
	}

	return true;
}

void solve() {
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	// 2 color each of the ccs
	for (int i = 1; i <= n; ++i) {
		if (!color[i]) {
			if (!bip(i, 1)) {
				cout << "IMPOSSIBLE\n";
				return;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << color[i] << " ";
	}
}

#define SABUJ_JANA_WxxF 1
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

// 2 color the graph / bipartite check