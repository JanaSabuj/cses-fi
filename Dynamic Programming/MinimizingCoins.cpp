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
const int N = 1e6 + 7;
int n, x;
// dp[x] = min no of ways to get money x = min(dp[x], SUMi [1 + dp[x - ci]])
//
int dp[N];
int coins[N];

void solve() {
	cin >> n >> x;

	for (int i = 0; i < n; ++i) {
		cin >> coins[i];
	}

	dp[0] = 0;
	for (int i = 1; i <= x; ++i) {
		dp[i] = INT_MAX;
		for (int j = 0; j < n; ++j) {
			if (i - coins[j] >= 0)
				dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
		}
	}

	if (dp[x] == INT_MAX)
		cout << -1 << endl;
	else
		cout << dp[x] << endl;

	// cout << LLONG_MAX << endl;
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