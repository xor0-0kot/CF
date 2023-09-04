#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend();
#define srt(a) sort(a.begin(), a.end());
#define srtr(a) sort(a.rbegin(), a.rend());

constexpr int mXN = 2e5 + 5, inf = INT_MAX - 100, mod = 1e9 + 7, llmod = 1e18+7;
constexpr double eps = 1e-8;

void test_case() {
    int n;
    cin >> n;
    int m = 2 * n;
    vector<pair<int,int>> a(2 * n), a2;
    for(int i=0; i<m; ++i) {
        char c; int x;
        cin >> c;
        if(c == 'W') {
            a[i].first = 1;
        } else a[i].first = 2;
        cin >> a[i].second;
    }
    a2 = a;
    int res1 = 0, res2 = 0;
    for(int i=0; i<m; ++i) {
        int ind = -1, mn = inf;
        for(int j=i; j>=0; --j) {
            if(a2[i].first == a2[j].first) {
                if(a2[j].second > a2[i].second) {
                    if(mn > a2[j].second) {
                        ind = j;
                        mn = a2[j].second;
                    }
                }
            }
        }
        if(ind != -1) {
            res1 += i - ind;
            rotate(a2.rbegin() + (m - i - 1), a2.rbegin() + (m - i), a2.rbegin() + (m - ind));
        }
    }
    for(int i=0; i<m; ++i) {
        int ind = -1, mx = -inf;
        for(int j=i; j<m; ++j) {
            if(a[i].first == a[j].first) {
                if(a[j].second < a[i].second) {
                    if(mx < a[j].second) {
                        ind = j;
                        mx = a[j].second;
                    }
                }
            }
        }
        if(ind != -1) {
            res2 += ind - i;
            rotate(a.begin() + i, a.begin() + i + 1, a.begin() + ind + 1);
        }
    }
    cout << min(res1, res2) << '\n';
}


signed main() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test_cases = 1;
//    cin >> test_cases;
    while(test_cases--) {
        test_case();
    }
}