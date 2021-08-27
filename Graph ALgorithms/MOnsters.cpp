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
const int N = 1e3 + 7;
int n, m;
char arr[N][N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<pair<int, int>> mons;
int ax, ay;
int fx, fy;
pair<int, int> par[N][N];
int dis_mons[N][N], dis_prince[N][N];

bool bfs_prince(int n, int m) {
	queue<pair<int, int>> q;
	q.push({ax, ay});
	par[ax][ay] = { -1, -1};
	arr[ax][ay] = '#';
	dis_prince[ax][ay] = 0;

	while (!q.empty()) {
		auto curr = q.front();
		q.pop();

		int x = curr.first;
		int y = curr.second;

		if (x == 0 or x == n - 1 or y == 0 or y == m - 1) {
			fx = x;
			fy = y;
			return true;
		}

		for (int i = 0; i < 4; i++) {
			int r = x + dx[i];
			int c = y + dy[i];

			if (r >= 0 and r < n and c >= 0 and c < m and arr[r][c] != '#' and (arr[r][c] != 'V' or (arr[r][c] == 'V' and dis_prince[x][y] + 1 < dis_mons[r][c]))) {
				q.push({r, c});
				arr[r][c] = '#';
				dis_prince[r][c] = dis_prince[x][y] + 1;
				par[r][c] = {x, y};
			}
		}
	}

	return false;
}

void bfs_monster(int n, int m) {
	queue<pair<int, int>> q;
	for (auto p : mons) {
		q.push(p);
		arr[p.first][p.second] = 'V';
		dis_mons[p.first][p.second] = 0;
	}

	while (!q.empty()) {
		auto curr = q.front();
		q.pop();

		int x = curr.first;
		int y = curr.second;

		for (int i = 0; i < 4; i++) {
			int r = x + dx[i];
			int c = y + dy[i];

			if (r >= 0 and r < n and c >= 0 and c < m and arr[r][c] != '#' and arr[r][c] != 'V') {
				q.push({r, c});
				arr[r][c] = 'V';
				dis_mons[r][c] = dis_mons[x][y] + 1;
			}
		}
	}
}

void solve() {
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 'A') {
				ax = i;
				ay = j;
			}
			if (arr[i][j] == 'M') {
				mons.push_back({i, j});
			}
		}
	}

	bfs_monster(n, m); // monsters
	bool found = bfs_prince(n, m);
	if (!found) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	int cnt = 0;
	string ans = "";

	while (fx != -1 and fy != -1) {
		int px = par[fx][fy].first;
		int py = par[fx][fy].second;

		if (px == -1 and py == -1) {
			break;
		}

		if (px == fx) {
			if (fy > py)
				ans += "R";
			else
				ans += "L";
		} else if (py == fy) {
			if (fx > px)
				ans += "D";
			else
				ans += "U";
		}

		// updt
		fx = px;
		fy = py;
		cnt++;
	}

	cout << cnt << endl;
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return;
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

// if you reach a monster visited cell before the monster, then you can survive
// double dfs - because we have a relation b/w the times of visit