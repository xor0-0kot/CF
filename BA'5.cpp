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

int ans(int a, int b) {
    int minn = inf;
    for(int i=1; i<=a; ++i) {
        if(a % i == b) {
            minn = power_of_two[i];
            break;
        }
    }
    int anss = -1;
    for(int i=b * 2 + 1; i < a/2; ++i) {
        int first = inf, second = inf;
        for(int j=1; j<=(a - i); ++j) {
            if((a-i) % j == 0 && j > b) {
                first = j;
                break;
            }
        }
        for(int j=1; j<=(i - b); ++j) {
            if((i - b) % j == 0 && j > b) {
                second = j;
                break;
            }
        }
        if(minn > power_of_two[first] + power_of_two[second]) {
            minn = power_of_two[first] + power_of_two[second];
            anss = i;
        }
    }
    return anss;
}

void test_case() {
        int n;
    cin >> n;
    vector<int> aa(n), bb(n);
    for(int i = 0; i<n; ++i) {
        cin >> aa[i];
    }
    for(int i=0; i<n; ++i) {
        cin >> bb[i];
    }
    vector<pair<int,int>> done;
    bool zeroes = true;
    vector<int> a, b;
    for(int i=0; i<n; ++i) {
        if(aa[i] != bb[i]) {zeroes = false; a.push_back(aa[i]), b.push_back(bb[i]);}
    }  
    n = a.size();
    done.resize(n, {-1,-1});
    vector<vector<pair<bool,bool>>> answer(51, vector<pair<bool,bool>>(n));
    for(int i=0; i<n; ++i) {
        if(b[i] >= (a[i] + 1) / 2) {
            cout << -1 << '\n';
            return;
        } 
    }
    int cnt = n;
    if(zeroes) {
        cout << 0 << '\n';
        return;
    }
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        int cur = ans(a[i], b[i]);
        if (cur != -1) {
            int first = a[i] - cur, second = cur - b[i];
            for (int j = 1; j <= first; ++j) {
                if (first % j == 0 && j > b[i]) {
                    answer[j][i].first = true;
                }
            }
            for (int j = 1; j <= first; ++j) {
                if (second % j == 0 && j > b[i]) {
                    answer[j][i].second = true;
                }
            }
            cnt+=1;
        } else {
            int cur = a[i] - b[i];
            for (int j = 1; j <= cur; ++j) {
                if (cur % j == 0 && j > b[i]) {
                    answer[j][i].first = true;
                }
            }
        }
    }
    int res = 0;
    for(int i=1; i<=1000; ++i) {
        bool fnd = false;
        for (int j = 0; j < answer[i].size(); ++j) {
            if (answer[i][j].first && done[j].first == -1) {
                fnd = true;
                cnt--;
                done[j].first = i;
            } else if (answer[i][j].first && done[j].first != -1 && fnd) {
                res -= power_of_two[done[j].first];
            }
            if (answer[i][j].second && done[j].second == -1) {
                fnd = true;
                cnt--;
                done[j].second = i;
            } else if (answer[i][j].second && done[j].second != -1 && fnd) {
                res -= power_of_two[done[j].second];
            } 
        }
        if (fnd) {
            res += power_of_two[i];
        }
        if(cnt == 0) {
            break;
        }
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
//    cin >> test_cases;
    power_of_two[0] = 1;
    for(int i=1; i<100; ++i) {
        power_of_two[i] = (power_of_two[i-1] * 2);
    }
    while(test_cases--) {
        test_case();    
    }
}