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
const int N = 2e5 + 7;
vector<int> adj[N];
int h1[N], h2[N], ans[N];

void dfs1(int node, int par) {
	for (auto to : adj[node]) {
		if (to != par) {
			dfs1(to, node);
			int htc = h1[to];
			if (1 + htc > h1[node]) {
				h2[node] = h1[node];
				h1[node] = 1 + htc;
			} else if (1 + htc > h2[node]) {
				h2[node] = 1 + htc;
			}
		}
	}
}

void dfs2(int node, int par, int to_p) {
	ans[node] = max(h1[node], to_p);
	for (auto to : adj[node]) {
		if (to != par) {
			int htc = h1[to];
			if (1 + htc == h1[node]) {
				dfs2(to, node, max(1 + h2[node], 1 + to_p));
			} else {
				dfs2(to, node, max(1 + h1[node], 1 + to_p));
			}
		}
	}
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs1(1, 0);
	dfs2(1, 0, 0);
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
}

signed main() {
	crap;

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}

/*
	Re - rooting DP (cur node / par node)
	https://usaco.guide/gold/all-roots?lang=cpp
	https://youtu.be/N7e4CTfimkU
*/