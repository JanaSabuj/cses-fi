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

void solve() {
	cin >> n >> m;
	int a, b;
	for (int j = 0; j < m; ++j) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}


	queue<int> q;
	q.push(1);
	visited[1] = 1;
	par[1] = -1;
	// int dis = 0;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if (curr == n) {
			break;
		}

		for (auto u : adj[curr]) {
			if (!visited[u]) {
				visited[u] = 1;
				par[u] = curr;
				q.push(u);
			}
		}

		// dis++;
	}

	if (!visited[n]) {
		cout << "IMPOSSIBLE\n";
	} else {

		vi path;
		for (int node = n; node != -1; node = par[node]) {
			path.push_back(node);
		}
		reverse(path.begin(), path.end());
		cout << (int)path.size() << endl;
		print1d(path);
	}
}

#define SABUJ_JANA_WxF 1
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

// bfs - check if path exists + shortest path