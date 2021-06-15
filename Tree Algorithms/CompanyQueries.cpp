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
int up[N][20];

void dfs1(int node, int par) {
	if (par == -1) {
		for (int i = 0; i < 20; i++)
			up[node][i] = -1;
	} else {
		up[node][0] = par;
		for (int i = 1; i < 20; ++i) {
			if (up[node][i - 1] != -1)
				up[node][i] = up[up[node][i - 1]][i - 1];
			else
				up[node][i] = -1;
		}
	}

	for (auto to : adj[node]) {
		if (to != par) {
			dfs1(to, node);
		}
	}
}

int query(int x, int jmp) {
	if (x == -1 || jmp == 0)
		return x;

	for (int i = 19; i >= 0; i--) {
		if (jmp >= (1 << i)) {
			return query(up[x][i], jmp - (1 << i));
		}
	}
}

void solve() {
	int n, q;
	cin >> n >> q;

	for (int i = 2; i <= n; i++) {
		int v;
		cin >> v;
		adj[i].push_back(v);
		adj[v].push_back(i);
	}

	// dfs
	dfs1(1, -1);
	while (q--) {
		int x, jmp;
		cin >> x >> jmp;
		cout << query(x, jmp) << endl;
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