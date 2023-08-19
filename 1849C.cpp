#include <bits/stdc++.h>
using namespace std;
using ll = __int128_t;

#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), r.end();
#define srt(a) sort(a.begin(), a.end());
#define srtr(a) sort(a.rbegin(), a.rend());
 
constexpr int mXN = 2e5, inf = INT_MAX - 100, mod = 1e18 + 7;
constexpr double eps = 1e-8; 
 
int tpow[mXN];

void test_case() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> zeroes(n + 1);
    vector<int> preffix(n + 1);
    for(int i=0; i<n; ++i) {
        if(s[i] == '1') {
            preffix[i + 1] = preffix[i] + tpow[n-i-1];
            zeroes[i + 1] = zeroes[i];
        } else {
            zeroes[i + 1] = zeroes[i] + 1;
            preffix[i + 1] = preffix[i];
        }
    }
    vector<int> preffix_sum(n+1);
    for(int i=0; i<n; ++i) {
        preffix_sum[i + 1] = preffix_sum[i] + tpow[n-i-1];
    }
    int res = 0;
    int sum = preffix[n];
    unordered_map<int,int> cnt;
    while(m--) {
        int ask_l, ask_r;
        cin >> ask_l >> ask_r;
        int r = ask_r;
        int l = ask_l + (zeroes[r] - zeroes[ask_l-1]);
        sum = (sum - ((preffix[r] - preffix[ask_l-1]) - (preffix_sum[r] - preffix_sum[l-1]))) % mod;
        if(cnt[sum] == 0) {
            cnt[sum]++;
            res++;
        } else cnt[sum]++;
        sum = preffix[n];
    }
    cout << res << '\n';
}
 
signed main() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test_cases = 1;
    cin >> test_cases;
    tpow[0] = 1;
    for(int i=1; i<=mXN; ++i) {
        tpow[i] = (tpow[i-1] * 2) % mod;
    }
    while(test_cases--) {
        test_case();    
    }
}