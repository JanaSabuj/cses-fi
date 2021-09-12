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

struct dsu {
	vector<int> parent;
	vector<int> _size;

	// merge two sets having a&b as entities
	void union_sets(int a, int b) {
		a = find_set(a);
		b = find_set(b);
		if (a != b) {
			if (_size[a] < _size[b])
				swap(a, b);
			parent[b] = a;
			_size[a] += _size[b];
		}
	}

	// find the set leader
	int find_set(int v) {
		if (v == parent[v])
			return v;
		return parent[v] = find_set(parent[v]);
	}

	// check if same set/leader
	bool same_comp(int a, int b) {
		return find_set(a) == find_set(b);
	}

	void make_set(int v) {
		parent[v] = v;
		_size[v] = 1;
	}

	void _init(int n) {
		parent.assign(n, 0);
		_size.assign(n, 0);

		for (int i = 0; i < n; i++)
			make_set(i);
	}
	
	// TC
	// O(logN) - normally
	// if both optimisations, O(alpha(N)) = O(4) for n < 10^600
};

struct Edge {
	int u, v, wt;
	bool operator<(Edge const& e) {
		return wt < e.wt;
	}
	Edge(int a, int b, int c) {
		u = a;
		v = b;
		wt = c;
	}
};

void solve() {
	cin >> n >> m;

	int a, b, c;
	dsu G;
	G._init(n + 2);

	vector<Edge> egde_list;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		Edge e(a, b, c);
		egde_list.push_back(e);
	}

	sort(egde_list.begin(), egde_list.end());

	int cost = 0;
	int comp = n;
	for (auto edge : egde_list) {
		int u = edge.u;
		int v = edge.v;
		int wt = edge.wt;

		if (!G.same_comp(u, v)) {
			cost += wt;
			G.union_sets(u, v);
			comp--;
		}
	}

	if (comp == 1) {
		cout << cost << endl;
	} else {
		cout << "IMPOSSIBLE" << endl;
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

