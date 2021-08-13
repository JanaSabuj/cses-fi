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
int ans[N];

int sub(int src, int par) {
	// base	
	
	// main
	int tot = 0;
	for (auto child : adj[src]) {
		if (child != par) {
			tot += (1 + sub(child, src));
		}
	}

	return ans[src] = tot;
}

void solve() {
	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		int p; cin >> p;
		adj[i].push_back(p);
		adj[p].push_back(i);
	}

	sub(1, 0);
	for (int i = 1; i <= n; ++i) {
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
	sub[i] = SUM[ci is child of i](1 + sub(ci))
		   = 0 [i is leaf]
*/

/*
1. for a undirected graph, any node which is not a root
	and has a degree(in + out) of 1 is a LEAF
2. for a directed graph, any node which is not a root
	and has outdegree 0 is a LEAF
*/