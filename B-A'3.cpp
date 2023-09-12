#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend();
#define srt(a) sort(a.begin(), a.end());
#define srtr(a) sort(a.rbegin(), a.rend());

constexpr int mXN = 4e3 + 5, inf = INT_MAX - 100;
constexpr double eps = 1e-8;

void test_case() {
    int n;
    cin >> n;
    vector<vector<int>> d(3000, vector<int>(3000, inf));
    vector<int> cnt_white(3000, inf), cnt_black(3000, inf);
    vector<vector<int>> bad_w(5000, vector<int>(5000)), bad_b(5000, vector<int>(5000));
    vector<int> w_in_a(5000), b_in_a(5000);
    vector<pair<char, int>> a(n * 2 + 2);
    for (int i = 0; i < 2 * n; ++i) {
        char type;
        int pos;
        cin >> type >> pos;
        a[i] = {type, pos-1};
        if (type == 'W') {
            w_in_a[pos-1] = i;
        } else {
            b_in_a[pos-1] = i;
        }
    }
    int cur_w = 0, cur_b = 0;
    for(int i=0; i<2*n; ++i) {
        int cnt = 0;
        for(int j=i-1; j>=0; --j) {
            if(a[j].second >= a[i].second && a[i].first == a[j].first) {
                cnt++;
            }
        }
        if (a[i].first == 'W')
            cnt_white[a[i].second] = cnt;
        else {
            cnt_black[a[i].second] = cnt;
        }
    }
    for (int i = 0; i < n; ++i) {
        bad_w[0][i] = i <= a[0].second && a[0].first == 'W';
        bad_b[0][i] = i <= a[0].second && a[0].first == 'B';
    }
    cur_b = 0, cur_w = 0;
    for(int i=1; i<2*n; ++i) {
        for(int j=0; j<=n+1; ++j) {
            if(a[i].first == 'W') {
                bad_b[i][j] = bad_b[i-1][j];
                bad_w[i][j] = bad_w[i-1][j] + (a[i].second >= j);
            } else {
                bad_w[i][j] = bad_w[i-1][j];
                bad_b[i][j] = bad_b[i-1][j] + (a[i].second >= j);
            }
        }
    }
    d[0][0] = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i != n) d[i + 1][j] = min(d[i + 1][j], d[i][j] + cnt_black[i] + bad_w[b_in_a[i]][j]);
            if (j != n) d[i][j + 1] = min(d[i][j + 1], d[i][j] + cnt_white[j] + bad_b[w_in_a[j]][i]);
        }
    }
    cout << d[n][n] << '\n';
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