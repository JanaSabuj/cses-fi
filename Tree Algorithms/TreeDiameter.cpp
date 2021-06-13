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
int diameter[N];
int ht[N];

void dfs(int src, int par) {
	// base

	int diam = 0;
	// excl
	vector<int> temp_ht;
	for (auto child : adj[src]) {
		if (child != par) {
			dfs(child, src);
			diam = max(diam, diameter[child]);
			temp_ht.push_back(ht[child]);
		}
	}

	// incl
	sort(temp_ht.begin(), temp_ht.end());
	int ch = temp_ht.size();

	if (ch == 0) {
		diam = max(diam, (int)0);
		ht[src] = 0;
	} else if (ch == 1) {
		diam = max(diam, 1 + temp_ht[ch - 1]);
		ht[src] = 1 + temp_ht[ch - 1];
	} else {
		diam = max(diam, 2 + temp_ht[ch - 1] + temp_ht[ch - 2]);
		ht[src] = 1 + temp_ht[ch - 1];
	}

	diameter[src] = diam;
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

	dfs(1, 0);

	int mx = 0;
	for (int i = 1; i <= n; ++i) {
		mx = max(mx, diameter[i]);
	}

	cout << mx << endl;
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

// https://youtu.be/qNObsKl0GGY (kartik arora)
// diameter[u] = max(diam(ci)) - excl
//			   = 2 + ht(ci) + ht(cj) - incl