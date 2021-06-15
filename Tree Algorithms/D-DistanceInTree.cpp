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
const int N = 5e4 + 7;
const int K = 500 + 7;
vector<int> adj[N];
int dp1[N][K], ans[N][K];
int k;
void dfs1(int node, int par) {
	dp1[node][0] = 1;

	// dp1[node][i] = 0;
	for (auto to : adj[node]) {
		if (to != par) {
			dfs1(to, node);
			for (int i = 1; i <= k; i++) {
				dp1[node][i] += dp1[to][i - 1];
			}
		}
	}

}

void dfs2(int node, int par) {
	ans[node][0] = 1;
	if (par == 0) {
		for (int i = 1; i <= K; i++) {
			ans[node][i] = dp1[node][i];
		}
	} else {
		ans[node][1] = adj[node].size();
		for (int i = 2; i <= K; i++) {
			ans[node][i] = dp1[node][i] + (ans[par][i - 1] - dp1[node][i - 2]);
		}
	}

	for (auto to : adj[node]) {
		if (to != par) {
			dfs2(to, node);
		}
	}
}

void solve() {
	int n;
	cin >> n >> k;
	// memset(dp1, 0, sizeof(dp1));
	// cout << n << k;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs1(1, 0);
	dfs2(1, 0);

	int tot = 0;
	for (int i = 1; i <= n; i++) {
		tot += ans[i][k];
	}

	cout << tot / 2 << endl;
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

// https://codeforces.com/contest/161/problem/D