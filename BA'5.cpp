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
bool presence[51][51][2];

pair<int,int> build(int a, int b) {
    if(b >= a / 2) {
        return {-1, -1};
    } else {
        pair<int, int> res = {-1, -1};
        int mn = inf;
        for(int i=b * 2 + 1; i<a; ++i) {
            int cur1 = i - b, cur2 = a - i;
            if(a % cur2 != i) {
                continue;
            }
            int mn1 = -1, mn2 = -1;
            for(int j=1; j<=i; ++j) {
                if(i % j == b) {
                    mn1 = j;
                    break;
                }
            }
            for(int j=i; j<=a; ++j) {
                if(a % j == i) {
                    mn2 = j;
                    break;
                }
            }
            if(mn1 == -1 || mn2 == -1) continue;
            if(power_of_two[mn1] + power_of_two[mn2] < mn) {
                mn = power_of_two[mn1] + power_of_two[mn2];
                res = {cur1, cur2};
            }
        }
        if(res.first != -1 && res.second != -1) {
            return res;
        } else {
            return {-1, -1};
        }
    }
}

int get_min(int a, int b) {
    for (int i = b + 1; i <= a; ++i) {
        if (a % i == b) {
            return i;
        }
    }
}

bool check(int a, int b) {
    return b >= (a + 1) / 2 && a != b;
}

bool better(pair<int, int> f, int a, int b) {
    for (int i = b + 1; i <= a; ++i) {
        if (a % i == b) {
            return power_of_two[i] < power_of_two[f.first] + power_of_two[f.second];
        }
    }
    return false;
}

void build_presence(int a, int b, int pos, int floor) {
    for (int i = b + 1; i <= a; ++i) {
        if (a % i == b) {
            presence[i][pos][floor] = true;
        }
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
    vector<bool> ignore(n);
    for (int i = 0; i < n; ++i) {
        ignore[i] = a[i] == b[i];
        if (check(a[i], b[i])) {
            cout << -1 << '\n';
            return;
        }
    }
    vector<vector<int>> block(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        if(ignore[i]) continue;
        pair<int, int> res = build(a[i], b[i]);
        if (res.first != -1 && res.second != -1) {
            block[i][1] = get_min(res.first, b[i]);
            block[i][0] = get_min(res.second, b[i] + res.first);
        }
        if ((res.first == -1 && res.second == -1) || better(make_pair(block[i][0], block[i][1]), a[i], b[i])) {
            block[i][0] = get_min(a[i], b[i]);
            block[i][1] = 0;
            build_presence(a[i], b[i], i, 1);
        } else {
            build_presence(res.first, b[i], i, 2), build_presence(res.second, b[i] + res.first, i, 1);
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
    power_of_two[0] = 1;
    for(int i=1; i<100; ++i) {
        power_of_two[i] = (power_of_two[i-1] * 2);
    }
    while(test_cases--) {
        test_case();
    }
}