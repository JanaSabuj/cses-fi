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
int arr[N];
int dp[102][N];// dp[i][j] = no of arrays till index j, ending with i

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	// base
	if (arr[0] != 0) dp[arr[0]][0] = 1;
	else {
		for (int i = 1; i <= m; ++i) {
			dp[i][0] = 1;
		}
	}


	for (int i = 1; i < n; ++i) {
		if (arr[i] != 0) {
			if (arr[i] - 1 >= 1) dp[arr[i]][i] = ( dp[arr[i]][i] % mod +  dp[arr[i] - 1][i - 1] % mod ) % mod;
			if (arr[i] + 1 <= m) dp[arr[i]][i] = ( dp[arr[i]][i] % mod +  dp[arr[i] + 1][i - 1] % mod ) % mod;
			dp[arr[i]][i] = ( dp[arr[i]][i] % mod +  dp[arr[i]][i - 1] % mod ) % mod;
		} else {

			for (int j = 1; j <= m; j++) {
				// i th index ends with j
				if (j - 1 >= 1)
					dp[j][i] = (dp[j][i] % mod +  dp[j - 1][i - 1] % mod) % mod;
				if (j + 1 <= m)
					dp[j][i] = (dp[j][i] % mod +  dp[j + 1][i - 1] % mod) % mod;
				dp[j][i] = ( dp[j][i] % mod +  dp[j][i - 1] % mod) % mod;
			}
		}

		// cout << i << " " << dp[22][i] << endl;
	}

	// ans
	int ans = 0;
	if (arr[n - 1] != 0) {
		ans = dp[arr[n - 1]][n - 1];;
	} else {
		int sum = 0;
		for (int j = 1; j <= m; j++) {
			sum = (sum % mod + dp[j][n - 1] % mod) % mod;
		}
		ans = sum;
	}

	cout << ans << endl;
}

#define SABUJ_JANA_xWF 1
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