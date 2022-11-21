#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define int long long


void solve() {
	map<int, long double> mp;
	for (int i = 0; i < 97; i++) {
		string s1, s2, s4;
		long double s3;
		cin >> s1 >> s2 >> s3;

		for (int i = 0; i < s2.size(); i++) {
			if (s2[i] == 'E') {
				s2 = "0";
				break;
			}
		}
		int x = stoi(s2);
		if (mp.find(x) != mp.end()) {
			if (mp[x] > s3) {
				mp[x] = s3;
			}
		} else {
			mp[x] = s3;
		}
	}

	map<long double, int> rmp;

	for (auto &x : mp) {
		rmp[x.second] = x.first;
	}


	// for (auto &x : rmp) {
	// 	cout << x.second << " " << x.first << ";\n";
	// }
	
	vector<pair<int, long double>> ans, fans;

	for (auto &x : rmp) {
		ans.push_back({x.second, x.first});
	}
	fans.push_back(ans[0]);
	for (int i = 1; i < ans.size(); i++) {
		if (ans[i].first > fans.back().first) {
			fans.push_back(ans[i]);
		}
	}

	for (auto &x : fans) {
		cout << x.first << " " << x.second << ";\n";
	}

}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
#endif
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t = 1;
	//cin >> t;

	while (t--) {
		solve();
	}

	// cerr << "Time elapsed: " << ((long double)clock() / CLOCKS_PER_SEC) << " s.\n";
}

