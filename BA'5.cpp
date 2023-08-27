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
 
constexpr int mXN = 2e5 + 5, inf = INT_MAX - 100, mod = 1e9 + 7, llmod = INT64_MAX;
constexpr double eps = 1e-8; 
 
int power_of_two[1000];
vector<int> a, b;
vector<bool> blocks[2][51];
bool build(int a, int b) {
    int cur = b - a;
    if(a - b <= a / 2) {
        return false;
    }
    if(b * 2 + 1 >= a / 2) {
        int mn = inf;
        for(int i=1; i<=(a-b); ++i) {
            if(a % i == b) {
                if(mn = inf) mn = i;
                blocks[1][i].push_back(mn);
            }
        }
        return true;
    } else {
        int first = b + 1, second = inf;
        int diff = a - b;
        for(int i=1; i*(b+1)<a/2; ++i) {
            if(a - b + first > b) blocks[1][i*(b+1)].push_back(b + 1);
        }
        second = b + 1 + (a - b) % (b + 1);
        for(int i=1; i*second<a/2; ++i) {
            if(a - b + second > b) blocks[1][i*second].push_back(second);
        }
        return true;
    }
}

void test_case() {
    int n;
    cin >> n;
    a.resize(n), b.resize(n);
    for(int i = 0; i<n; ++i) {
        cin >> a[i];
    }
    for(int i=0; i<n; ++i) {
        cin >> b[i];
    }
    build(a[0], b[0]);
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
    power_of_two[0] = 1;
    for(int i=1; i<100; ++i) {
        power_of_two[i] = (power_of_two[i-1] * 2);
    }
    while(test_cases--) {
        test_case();    
    }
}