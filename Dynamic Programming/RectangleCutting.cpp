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
const int N = 505;

int dp[N][N];// dp[i][j] = no of moves to break down a (i,j) rect into any square
int n, m;

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i == 1 and j == 1) dp[i][j] = 0;
			else if (i == 1) {
				dp[i][j] = j - 1;
			} else if (j == 1) {
				dp[i][j] = i - 1;
			} else if (i == j) dp[i][j] = 0;
			else {
				// i, j
				// vert cut
				dp[i][j] = INT_MAX;
				for (int c = 1; c <= m - 1; c++)
					if (j - c >= 1)
						dp[i][j] = min(dp[i][j], 1 + dp[i][c] + dp[i][j - c]);
				for (int c = 1; c <= n - 1; c++)
					if (i - c >= 1)
						dp[i][j] = min(dp[i][j], 1 + dp[c][j] + dp[i - c][j]);
			}
		}
	}

	cout << dp[n][m] << endl;
}

// O(NM(N+M)) === O(N^3)

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