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
const int N = 105;
const int X = 1e5 + 7;

int arr[N];
int dp[N][X];// dp[i][j] = T/F such that I can take i coins and have sum j
int n;
int sum = 0;

void solve() {
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}

	for (int i = 0; i <= n; i++)
		dp[i][0] = 1;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= sum; ++j) {
			if (j >= arr[i - 1])
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	set<int> st;// no of possible sums using all n items
	for (int j = 1; j <= sum; ++j) {
		if (dp[n][j])
			st.insert(j);
	}


	cout << st.size() << endl;
	for (auto x : st) {
		cout << x << " ";
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