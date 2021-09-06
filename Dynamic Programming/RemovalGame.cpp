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
const int N = 5 * 1e3 + 7;

int dp[N][N][2];// dp[i][j][p] = value of X for arr[i...j] when pth turn
int arr[N];
int n;

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	// l = 1
	for (int i = 0; i < n; i++) {
		dp[i][i][0] = arr[i];
		dp[i][i][1] = 0;
	}

	// l = 2..n
	for (int l = 2; l <= n; l++) {
		for (int i = 0; i + l - 1 < n; i++) {
			int j = i + l - 1;
			// [i..j]
			dp[i][j][0] = max(arr[i] + dp[i + 1][j][1], arr[j] + dp[i][j - 1][1]);
			dp[i][j][1] = min(0 + dp[i + 1][j][0], 0 + dp[i][j - 1][0]);
		}
	}

	cout << dp[0][n - 1][0] << endl;
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