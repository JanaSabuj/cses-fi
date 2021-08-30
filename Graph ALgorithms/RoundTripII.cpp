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
typedef pair<int, int> pii;
#define endl "\n"
void print1d(const vector<int>& vec) {for (auto val : vec) {cout << val << " ";} cout << endl;}
void print2d(const vector<vector<int>>& vec) {for (auto row : vec) {for (auto val : row) {cout << val << " ";} cout << endl;}}
const int mod = 1e9 + 7;
const int N = 1e5 + 7;
int n, m;
vi adj[N];
int visited[N], par[N];
int sx, sy;

bool cycle(int x) {
	visited[x] = 1;
	for (auto v : adj[x]) {
		if (!visited[v]) {
			par[v] = x;
			if (cycle(v))
				return true;
		} else if (visited[v] == 1) {
			sx = v;
			sy = x;
			return true;
		}
	}

	visited[x] = 2;
	return false;
}

void pr(int sx, int sy) {
	vi ans;
	ans.push_back(sx);
	for (int v = sy; v != sx; v = par[v]) {
		ans.push_back(v);
	}
	ans.push_back(sx);
	cout << ans.size() << endl;
	reverse(ans.begin(), ans.end());
	print1d(ans);
}

void solve() {
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		adj[a].push_back(b);
	}

	sx = -1, sy = -1;
	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			if (cycle(i)) {
				pr(sx, sy);
				return;
			}
		}
	}

	cout << "IMPOSSIBLE\n" << endl;
}

#define SABUJ_JANA_WcF 1
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