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

int n, m, v, p;

int check(int mid, vector<int> a) {
    int remain = m * v - (mid + 1) * m;
    for (int i = n-1; i >= n-p+1; --i) {
        int add = m;
        a[i] += add;
        remain -= add;
    }
    for(int i=mid + 1; i<=n-p; ++i) {
        int add = max(a[mid] + m - a[i], 0LL);
        a[i] += add;
        remain -= add;
    } 
    int cnt = 0;
    if(remain > 0) {
        cnt += min(n - p - mid , remain);
    }
    for(int i=0; i<n; ++i) {
        if(a[i] > a[mid] + m) {
            cnt++;
        }
    }
    return cnt + 1;
}

void test_case() {
    cin >> n >> m >> v >> p;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    int low = -1, high = n-1;
    while(high - low > 1) {
        int mid = (high + low) >> 1;
        if(check(mid, a) <= p) {
            high = mid;
        } else low = mid;
    }
    cout << n - high << '\n';
}

 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test_cases = 1;
//    cin >> test_cases;
    while(test_cases--) {
        test_case();    
    }
}