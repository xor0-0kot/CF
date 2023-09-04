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

int power_of_two[65];
vector<vector<vector<int>>> pair_solves;

void find_solution(vector<int>& cur, int a, int b, int pos, int left) {
    if(a == b) {
        pair_solves[pos].push_back(cur);
        return;
    }
    if(left == 2) {
        for(int i=1; i<=50; ++i) {
            if(a % i == b) {
                cur.push_back(i);
                find_solution(cur, a % i, b, pos, left+1);
                cur.pop_back();
            }
        }
    }
    for(int i=1; i<=50; ++i) {
        if((a % i >= b * 2 + 1 || a % i == b) && i <= a) {
            cur.push_back(i);
            find_solution(cur, a % i, b, pos, left+1);
            cur.pop_back();
        }
    }
}

void test_case() {
    int n;
    cin >> n;
    pair_solves.resize(n);
    vector<int> a(n), b(n);
    for(int i=0; i<n; ++i) {
        cin >> a[i];
    }
    for(int i=0; i<n; ++i) {
        cin >> b[i];
    }
    for(int i=0; i<n; ++i) {
        if(b[i] *  2 + 1 > a[i] && a[i] != b[i]) {
            cout << -1 << '\n';
            return;
        }
        vector<int> cur;
        find_solution(cur, a[i], b[i], i, 0);
    }
    vector<int> picked(51);
    int res = power_of_two[51];
    for(int k=50; k>=1; --k) {
        bool possible = true;
        for(int i=0; i<n; ++i) {
            int cnt = 0;
            for(int j=0; j<pair_solves[i].size(); ++j) {
                bool fnd = false;
                for(int l = 0; l<pair_solves[i][j].size(); ++l) {
                    if(k == pair_solves[i][j][l] || picked[pair_solves[i][j][l]]) {
                        fnd=true;
                    }
                }
                if(fnd) cnt++;
            }
            if(cnt == pair_solves[i].size()) {
                possible = false;
                break;
            }
        }
        if(possible) {
            res -= power_of_two[k];
            picked[k] = true;
        }
    }
    cout << res - 2 << '\n';
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
    for(int i=1; i<65; ++i) {
        power_of_two[i] = (power_of_two[i-1] * 2);
    }
    while(test_cases--) {
        test_case();    
    }
}
