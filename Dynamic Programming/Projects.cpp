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
const int N = 2 * 1e5 + 7;

// weighted job scheduling - BS + DP
struct Job {
	int s, f, p;
};

Job arr[N];

bool cmp(Job& a, Job& b) {
	return a.f < b.f;
}

int dp[N];
int n;

int BS(Job arr[], int n) {
	int lo = 0, hi = n - 1;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (arr[mid].f < arr[n].s) {
			if (arr[mid + 1].f < arr[n].s)
				lo = mid + 1;
			else
				return mid;
		} else
			hi = mid - 1;
	}

	return -1;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].s >> arr[i].f >> arr[i].p;
	}

	sort(arr, arr + n, cmp);// sort by ending time
	dp[0] = arr[0].p;

	for (int i = 1; i < n; ++i) {
		int excl = dp[i - 1];

		int incl = arr[i].p;
		int idx = BS(arr, i);
		if (idx != -1)
			incl += dp[idx];

		dp[i] = max(incl, excl);
	}

	cout << dp[n - 1] << endl;
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