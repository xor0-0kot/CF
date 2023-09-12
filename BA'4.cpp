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
constexpr double eps = 1e-7;

struct Point {
    double x, y;
    Point() {}
    Point(int x, int y): x(x), y(y) {}
};

Point operator +(Point& a, Point& b) {
    return Point(a.x + b.x, a.y + b.y);
}

Point operator -(Point& a, Point& b) {
    return Point(a.x - b.x, a.y - b.y);
}

double operator *(Point& a, Point& b) {
    return a.x * b.x + a.y * b.y;
}

double operator ^(Point& a, Point& b) {
    return a.x*b.y-b.x*a.y;
}

istream& operator>>(istream& in, Point& a) {
    in >> a.x >> a.y;
    return in;
}

bool eq(double a, double b) {
    return abs(a - b) <= eps;
}

void test_case() {
    int n, m, k;
    cin >> n >> m >> k;
    Point a, b;
    cin >> a >> b;
    vector<Point> v(4);
    v[0] = Point(0, 0), v[1] = Point(n, 0), v[2] = Point(n, m), v[3] = Point(0, m);
    for(int i=0; i<4; ++i) {
        Point vc = v[i] - a;
        if(eq(vc ^ b, 0)) {
            cout << 0 << '\n';
            return;
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
    while(test_cases--) {
        test_case();
    }
}