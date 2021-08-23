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
char arr[1005][1005];
// map<pair<int, int>, pair<int, int>> par;
pair<int, int> par[1005][1005];
int n, m;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


void solve() {
	cin >> n >> m;
	int sx, sy;
	int fx, fy;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 'A') {
				sx = i;
				sy = j;
			}
			if (arr[i][j] == 'B') {
				fx = i;
				fy = j;
			}
		}
	}

	queue<pair<int, int>> q;
	q.push({sx, sy});
	par[sx][sy] = { -1, -1};
	arr[sx][sy] = '#';// visited


	bool flag = false;
	while (!q.empty()) {
		auto curr = q.front(); q.pop();
		int cx = curr.first;
		int cy = curr.second;

		if (cx == fx and cy == fy) {
			// cout << "hi" << endl;
			flag = true;
			break;
		}

		for (int i = 0; i < 4; ++i) {
			int r = cx + dx[i];
			int c = cy + dy[i];

			if (r >= 0 and r < n and c >= 0 and c < m and arr[r][c] != '#') {
				arr[r][c] = '#';// visited
				q.push({r, c});
				par[r][c] = {cx, cy};
				// cerr << par[r][c].first << endl;
			}
		}
	}

	// print path
	if (!flag) {
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
}

#define SABUJ_JANA_WF 1
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