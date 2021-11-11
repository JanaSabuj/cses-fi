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
const int N = 0;
vvi adj;
vi topo, color;
 
bool isCycle(int x) {
	color[x] = 1;
 
	for (auto v : adj[x]) {
		if (color[v] == -1) {
			if (isCycle(v))
				return true;
		} else if (color[v] == 1) {
			return true;
		}
	}
 
	color[x] = 2;
	topo.push_back(x);
	return false;
}
void solve() {
	int n, m;
	cin >> n >> m;
	adj.assign(n + 1, {});
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		// a ----> b
		adj[a].push_back(b);
	}
 
	color.assign(n + 1, -1);
	for (int i = 1; i <= n; i++) {
		if (color[i] == -1) {
			if (isCycle(i)) {
				cout << "IMPOSSIBLE" << endl;
				return;
			}
		}
	}
 
	reverse(topo.begin(), topo.end());
	for (auto x : topo)
		cout << x << " ";
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
