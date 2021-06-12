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
int subans[N];
int ans[N][2];

int dp(int src, int par, int flag) {
	// base
	if (ans[src][flag] != -1)
		return ans[src][flag];

	// main
	int tot = 0;
	if (flag == 0) {
		for (auto to : adj[src]) {
			if (to != par) {
				tot += max(dp(to, src, 0), dp(to, src, 1));
			}
		}
	} else if (flag == 1) {
		for (auto to : adj[src]) {
			if (to != par) {
				tot = max(tot, 1 + dp(src, par, 0) - max(dp(to, src, 0), dp(to, src, 1)) + dp(to, src, 0));
			}
		}
	}

	return ans[src][flag] = tot;
}

void solve() {
	int n;
	cin >> n;
	memset(ans, -1, sizeof(ans));

	for (int i = 1; i <= n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	// root tree at 1
	cout <<  max(dp(1, -1, 0), dp(1, -1, 1)) << endl;
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

// https://usaco.guide/gold/dp-trees?lang=cpp
// kartik arora - https://youtu.be/RuNAYVTn9qM