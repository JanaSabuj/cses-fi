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
int ans1[N], ans[N], nodes[N];

void dfs1(int node, int par) {
	for (auto to : adj[node]) {
		if (to != par) {
			dfs1(to, node);
			ans1[node] += (nodes[to] + ans1[to]);
			nodes[node] += nodes[to];
		}
	}
	nodes[node]++;
}

void dfs2(int node, int par, int to_p) {
	ans[node] = ans1[node] + to_p + (nodes[1] - nodes[node]);
	for (auto to : adj[node]) {
		if (to != par) {
			dfs2(to, node, ans[node] - (nodes[to] + ans1[to]));
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