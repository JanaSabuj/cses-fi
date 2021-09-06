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

int dp[N][N];// edit[i][j] = E.D of s1[0..i], s2[0..j]
string s, t;
void solve() {
	cin >> s >> t;

	int n = s.size();
	int m = t.size();

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (i == 0 and j == 0) dp[i][j] = 0;
			else if (i == 0) dp[i][j] = j;
			else if (j == 0) dp[i][j] = i;
			else {
				// int val = ;
				dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], (s[i - 1] == t[j - 1] ? -1 : 0) + dp[i - 1][j - 1]});
			}
		}
	}

	cout << dp[n][m] << endl;
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