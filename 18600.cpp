#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    string s;
    cin >> s;
    int bal = 0;
    int mx = 0;
    for(int i=0; i<s.size(); ++i) {
        if(s[i] == '(') {
            bal++;

        } else {
            bal--;
        }
         mx = max(mx, abs(bal));
    }
    if(s == "()") {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        string copy = "";
        for(int i=0; i<s.size(); ++i) {
                copy += "()";
        }
        if(copy.find(s) == string::npos) {
            cout << copy << '\n';
        } else {
            for(int i=0; i<s.size(); ++i) {
                cout << "(";
            } 
            for(int i=0; i<s.size(); ++i) {
                cout << ")";
            } 
            cout << '\n';
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
    cin >> test_cases;
    while(test_cases--) {
        test_case();    
    }
}