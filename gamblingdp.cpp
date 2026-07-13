
// #include <bits/stdc++.h>
// #define int long long
//
//
// // code from kailash
// using namespace std;
//
// signed main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
//
// 	int T, n, a;
// 	cin >> T;
// 	while (T--) {
// 		cin >> n;
// 		int best = -1;
// 		// result goes in here
// 		vector<int> ALR(3);
// 		map<int, vector<int>> saves;
//
// 		for (int i = 0; i < n; ++i) {
// 			cin >> a;
// 			saves[a].push_back(i+1);
// 		}
//
// 		for (auto& [v, p] : saves) {
//
// 			int cur = 1, s = 0;
//
// 			if (cur > best) {
// 				best = cur;
// 				ALR = {v, p[0], p[0]};
// 			}
//
// 			for (int i = 1; i < p.size(); ++i) {
// 				int g = p[i] - p[i-1] - 1, toadd = 1-g;
// 				if (cur + toadd < 1) {
// 					cur = 1;
// 					s = i;
// 				}
// 				else cur += toadd;
// 				if (cur > best) {
// 					best = cur;
// 					ALR = {v, p[s], p[i]};
// 				}
// 			}
//
//
// 		}
//
// 		cout << ALR[0] << " " << ALR[1] << " " << ALR[2] << "\n";
// 	}
//
// 	return 0;
// }