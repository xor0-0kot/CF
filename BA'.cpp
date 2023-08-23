#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define bin_check(a) __builtin_popcount(a)
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define srt(a) sort(a.begin(), a.end())
#define srtr(a) sort(a.rbegin(), a.rend())
 
constexpr int mXN = 2e5 + 5, inf = INT_MAX - 100, mod = 1e9 + 7, llmod = 1e18+7;
constexpr double eps = 1e-8; 
 
int ts[200001];
int answer[200001];

int find_answer(int x) {
    int cnt = 0;
    while(x != 0) {
        x = x % bin_check(x);
        cnt++;
    }
    return cnt;
}

void test_case() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for(int i=0; i<n; ++i) {
        cnt += (s[i] - '0');
    }
    if(cnt == 1) {
        cout << 0 << '\n';
        return;
    }
    vector<int> t1(n + 1), t2(n + 1);
    t1[0] = 1 % (cnt + 1), t2[0] = 1 % (cnt - 1);
    for(int i=1; i<=n; ++i) {
        t1[i] = (t1[i-1] * 2) % (cnt+1);
        t2[i] = (t2[i-1] * 2) % (cnt-1);
    }
    int c1 = 0, c2 = 0;
    for(int i=0; i<n; ++i) {
        c1 = (c1 + (s[i] == '1'? t1[n - i - 1] % (cnt + 1) : 0)) % (cnt + 1);
        c2 = (c2 + (s[i] == '1'? t2[n - i - 1] % (cnt - 1): 0)) % (cnt - 1);
    }
    for(int i=0; i<n; ++i) {
        if(s[i] == '0') {
            c1 = (c1 + t1[n-i-1]);
            cout << answer[c1 % (cnt + 1)] + 1 << '\n';
            c1 -= t1[n-i-1];
        }
        if(s[i] == '1') {
            c2 = c2 - t2[n-i-1];
            if(c2 < 0) c2 += (cnt - 1);
            cout << answer[c2 % (cnt - 1)] + 1 << '\n';
            c2 += t2[n - i - 1];
        }
    }
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
    for(int i=0; i<=200000; ++i) {
        answer[i] = find_answer(i);
    }
    while(test_cases--) {
        test_case();    
    }
}