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
vi adj[N];
int lvl[N];
int up[N][20];

void dfs1(int node, int par, int ht) {
	lvl[node] = ht;
	for (auto to : adj[node]) {
		if (to != par) {
			dfs1(to, node, ht + 1);
		}
	}
}

int dfs2(int node, int par) {
	if (par == -1) {
		for (int i = 0; i < 20; i++)
			up[node][i] = -1;
	} else {
		up[node][0] = par;
		for (int i = 1; i < 20; i++) {
			int prev = up[node][i - 1];
			if (prev != -1)
				up[node][i] = up[prev][i - 1];
			else
				up[node][i] = -1;
		}
	}

	for (auto to : adj[node]) {
		if (to != par) {
			dfs2(to, node);
		}
	}
}

int lift_node(int x, int jmp) {
	if (x == -1 || jmp == 0)
		return x;

	for (int i = 19; i >= 0; i--) {
		if (jmp >= (1 << i)) {
			return lift_node(up[x][i], jmp - (1 << i));
		}
	}
}

int lca(int a, int b) {
	// b

	// a
	if (lvl[a] < lvl[b])
		return lca(b, a);
	int diff = lvl[a] - lvl[b];
	int x = lift_node(a, diff);
	// x b

	if (x == b)
		return x;

	for (int i = 19; i >= 0; i--) {
		if (up[x][i] != up[b][i]) {
			// cout << "hi" << i << endl;
			x = up[x][i];
			b = up[b][i];
		}
	}

	return lift_node(x, 1);//go up 1 step
}

void solve() {
	int n, q;
	cin >> n >> q;

	for (int i = 2; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs1(1, -1, 0);
	dfs2(1, -1);

	while (q--) {
		int a, b;
		cin >> a >> b;
		int top = lca(a, b);

		cout << abs(lvl[a] - lvl[top]) + abs(lvl[b] - lvl[top]) << endl;
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