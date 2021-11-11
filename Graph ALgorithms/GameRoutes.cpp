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
const int N = 0, mod = 1e9 + 7;
int n, m;
vvi adj, backEdge;
vi indegree, ways;
 
void kahn() {
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (indegree[i] == 0)
			q.push(i);
	}
 
	while (!q.empty()) {
		int x = q.front();
		q.pop();
 
		for (auto u : adj[x]) {
			indegree[u]--;
			if (indegree[u] == 0)
				q.push(u);
		}
 
		// do dp
		for (auto u : backEdge[x]) {
			ways[x] = (ways[x] + ways[u]) % mod;
		}
 
		if (x == 1) {
			ways[x] = 1;
		}
 
	}
}
 
void solve() {
	cin >> n >> m;
	adj.assign(n + 1, {});
	backEdge.assign(n + 1 , {});
	indegree.assign(n + 1, 0);
	ways.assign(n + 1, 0);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		backEdge[b].push_back(a);
		indegree[b]++;
	}
 
 
	kahn();
 
	cout << ways[n] << endl;
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
