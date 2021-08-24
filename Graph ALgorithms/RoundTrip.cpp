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
const int mod = 1e9 + 7;
vi adj[100005];
bool visited[100005];
int par[100005];
int n, m;
int s, e;

bool pr(int s, int e) {
	vi ans;
	// ans.push_back(e);
	for (int node = e; node != s; node = par[node]) {
		ans.push_back(node);
	}
	ans.push_back(s);
	ans.push_back(e);
	// reverse(ans.begin(), ans.end());
	if (ans.size() >= 4) {
		cout << ans.size() << endl;
		print1d(ans);
		return true;
	} else
		return false;
}

bool cycle(int x) {
	visited[x] = 1;

	for (auto u : adj[x]) {
		if (!visited[u]) {
			par[u] = x;
			if (cycle(u))
				return true;
		} else {
			s = u;
			e = x;
			// cout << s << "," << e << endl;
			if (pr(s, e))
				return true;
		}
	}

	return false;
}



void solve() {
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			if (cycle(i)) {
				return;
			}
		}
	}
	cout << "IMPOSSIBLE\n";
}

#define SABUJ_JANA_WFx 1
signed main() {
	crap;
#ifdef SABUJ_JANA_WF
	auto start = chrono::high_resolution_clock::now();
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); freopen("error.txt", "w", stderr);
#endif

	int t = 1;
	// cin >> t;
	while (t--) solve();

#ifdef SABUJ_JANA_WF
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
	cerr << "Time taken :\n" << duration.count() / 1000000.0 << "s" << "\n";
#endif
	return 0;
}

// https://cp-algorithms.com/graph/finding-cycle.html
// cycle in undirected graph - no need to use colors, simply visited array will suffice
// for directed graph, we need 3 colors