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

int n, k;
int arr[N];

// CLASSIC PROBLEM - finding median in stream/windows
// here, multiset also works
void add(int val, int idx, set<pair<int, int>>& lowers, set<pair<int, int>>& highers) {
	if (lowers.size() == 0 || val < lowers.rbegin()->first)
		lowers.insert({val, idx});
	else
		highers.insert({val, idx});
}

void dlete(int val, int idx, set<pair<int, int>>& lowers, set<pair<int, int>>& highers) {
	if (lowers.find({val, idx}) != lowers.end())
		lowers.erase({val, idx});
	else
		highers.erase({val, idx});
}

void rebalance(set<pair<int, int>>& lowers, set<pair<int, int>>& highers) {
	int ll = lowers.size();
	int hl = highers.size();

	if (ll - hl >= 2) {
		highers.insert({lowers.rbegin()->first, lowers.rbegin()->second});
		lowers.erase(*lowers.rbegin());
	} else if (hl - ll >= 2) {
		lowers.insert({highers.begin()->first, highers.begin()->second});
		highers.erase(*highers.begin());
	}
}

int findMedian(set<pair<int, int>>& lowers, set<pair<int, int>>& highers) {
	if (lowers.size() == highers.size())
		return min(lowers.rbegin()->first, highers.begin()->first);
	else if (lowers.size() > highers.size())
		return lowers.rbegin()->first;
	else
		return highers.begin()->first;
}

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	set<pair<int, int>> lowers;
	set<pair<int, int>> highers;

	for (int i = 0; i < n; ++i) {
		int val = arr[i];
		add(val, i, lowers, highers);
		if (i > k - 1)
			dlete(arr[i - k], i - k, lowers, highers);
		rebalance(lowers, highers);

		if (i >= k - 1)
			cout << findMedian(lowers, highers) << " ";
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
