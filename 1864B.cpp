#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), r.end();
#define srt(a) sort(a.begin(), a.end());
#define srtr(a) sort(a.rbegin(), a.rend());
 
constexpr int mXN = 2e5 + 5, inf = INT_MAX - 100, mod = 1e9 + 7;
constexpr double eps = 1e-8; 
 

void test_case() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(k % 2 == 0) {
        sort(all(s));
        cout << s << '\n';
    } else {
        string s1 = "", s2 = "";
        for(int i=0; i<n; ++i) {
            if(i % 2 == 0) {
                s1 += s[i];
            } else s2 += s[i];
        }
        sort(all(s1)), sort(all(s2));
        for(int i=0, ind1 = 0, ind2 = 0; i<n; ++i) {
            if(i % 2 ==0) {
                cout << s1[ind1];
                ind1++;
            } else {
                cout << s2[ind2];
                ind2++;
            }
        }
        cout << '\n';
    }
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test_cases = 1;
    cin >> test_cases;
    while(test_cases--) {
        test_case();    
    }
}