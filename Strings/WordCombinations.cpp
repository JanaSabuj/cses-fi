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
const int N = 5005;

// Dictionary Trie with prefix search from the end
struct trieNode {
	trieNode* child[26];
	bool isEnd;
	trieNode() {
		for (int i = 0; i < 26; ++i) {
			child[i] = NULL;
		}
		isEnd = false;
	}
};

int dp[N];

class Trie {
	trieNode* root;
public:
	Trie() {
		root = new trieNode();
	}

	void insert(string str) {
		trieNode* curr = root;
		for (auto c : str) {
			int x = c - 'a';
			if (curr->child[x] == NULL)
				curr->child[x] = new trieNode();
			curr = curr->child[x];
		}
		curr->isEnd = true;
	}

	int search(int idx, int n, string str) {
		trieNode* curr = root;
		int ans = 0;
		// keep on searching for prefixes
		for (int i = idx; i < n; i++) {
			int x = str[i] - 'a';
			if (curr->child[x] == NULL) break;
			curr = curr->child[x];
			if (curr->isEnd)
				(ans += dp[i + 1] % mod) %= mod;
		}

		return ans;
	}
};


void solve() {
	string str;
	cin >> str;

	Trie root;// trie

	int k;
	cin >> k;

	string s;
	// insert dictionary into trie
	while (k--) {
		cin >> s;
		root.insert(s);
	}

	int n = str.size();
	dp[n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		dp[i] = root.search(i, n, str);
	}

	cout << dp[0] << endl;
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
