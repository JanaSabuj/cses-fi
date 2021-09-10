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

// KMP with LPS array
vi lps(string str) {
	int n = str.size();
	vi pi(n, 0);

	int j;
	for (int i = 1; i < n; i++) {
		j = pi[i - 1];
		while (j > 0 and str[j] != str[i])
			j = pi[j - 1];
		if (str[j] == str[i]) {
			pi[i] = j + 1;
		} else
			pi[i] = 0;
	}

	return pi;
}

void solve() {
	string a, b;
	cin >> a >> b;

	string str;
	str = b + "$" + a;

	vi lps_arr = lps(str);
	int cnt = 0;
	int p_l = b.size();
	for (auto x : lps_arr)
		if (x == p_l)
			cnt++;

	cout << cnt << endl;
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