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

vector<vector<set<pair<int,int>>>> replaces(4, vector<set<pair<int,int>>>(4)); // 1 - a, 2 - b, 3 - c;
vector<int> type;
vector<vector<int>> a;
int x, y, z, n;

void del(int i) {
    if(type[i] == 1) {
        replaces[type[i]][2].erase({a[i][2] - a[i][type[i]], i});
        replaces[type[i]][3].erase({a[i][3] - a[i][type[i]], i});
    } else if(type[i] == 2) {
        replaces[type[i]][1].erase({a[i][1] - a[i][type[i]], i});
        replaces[type[i]][3].erase({a[i][3] - a[i][type[i]], i});
    } else {
        replaces[type[i]][1].erase({a[i][1] - a[i][type[i]], i});
        replaces[type[i]][2].erase({a[i][2] - a[i][type[i]], i});
    }
}

void add(int i, int type1) {
    type[i] = type1;
    if(type1 == 1) {
        replaces[type1][2].insert({a[i][2] - a[i][type1], i});
        replaces[type1][3].insert({a[i][3] - a[i][type1], i});
    } else if(type1 == 2) {
        replaces[type1][1].insert({a[i][1] - a[i][type1], i});
        replaces[type1][3].insert({a[i][3] - a[i][type1], i});
    } else {
        replaces[type1][1].insert({a[i][1] - a[i][type1], i});
        replaces[type1][2].insert({a[i][2] - a[i][type1], i});
    }
}

void swapp(int i, int type1) {
    del(i);
    add(i, type1);
}

void test_case() {
    cin >> x >> y >> z;
    n = x + y + z;
    type.resize(n);
    a.resize(n, vector<int>(4));
    for(auto& i : a) {
        cin >> i[1] >> i[2] >> i[3];
        i[0] = 0;
    }
    y += z, x += y;
    int res = 0;
    for(int i=0; i<n; ++i) {
        if(i < z) {
            res += a[i][3];
            type[i] = 3;
            replaces[3][1].insert({a[i][1] - a[i][3], i});
            replaces[3][2].insert({a[i][2] - a[i][3], i});
        } else if(i < y) {
            res += a[i][2];
            type[i] = 2;
            replaces[2][1].insert({a[i][1] - a[i][2], i});
            replaces[2][3].insert({a[i][3] - a[i][2], i});
        } else {
            res += a[i][1];
            type[i] = 1;
            replaces[1][2].insert({a[i][2] - a[i][1], i});
            replaces[1][3].insert({a[i][3] - a[i][1], i});
        }
    }
    for(int i=0; i<6; ++i) {
        for(int i=0; i<n; ++i) {
            int win = -inf, sw = -1, sw2 = -1;
            int pos1 = -1, pos2 = -1;
            for(int j=1; j<4; ++j) {
                if(type[i] != j && win < a[i][j] - a[i][type[i]] + replaces[j][type[i]].rbegin()->first) {
                    win = a[i][j] - a[i][type[i]] + replaces[j][type[i]].rbegin()->first;
                    sw = j;
                    pos1 = replaces[j][type[i]].rbegin()->second;
                }
                int except = -1;
                if(3 != type[i] && j != 3) except = 3;
                if(2 != type[i] && j != 2) except = 2;
                if(1 != type[i] && j != 1) except = 1;
                if(type[i] != j && win < a[i][j] - a[i][type[i]] + replaces[j][except].rbegin()->first + replaces[except][type[i]].rbegin()->first) {
                    win = a[i][j] - a[i][type[i]] + replaces[j][except].rbegin()->first + replaces[except][type[i]].rbegin()->first;
                    pos1 = replaces[j][except].rbegin()->second, pos2 = replaces[except][type[i]].rbegin()->second;
                    sw = j, sw2 = except;
                }
            }
            if(win > 0) {
                res += win;
                int cur_type = type[i];
                if(sw2 == -1) {
                    swapp(i, sw); swapp(pos1, cur_type);
                } else {
                    swapp(i, sw), swapp(pos1, sw2), swapp(pos2, cur_type);
                }
            }
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
    while (test_cases--) {
        test_case();
    }
}