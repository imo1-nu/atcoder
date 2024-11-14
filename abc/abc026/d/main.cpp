#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int A, B, C;

double f(double t)
{
    return A * t + B * sin(C * t * M_PI);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> A >> B >> C;
    
    double l = 0, r = 300;
    while (100 - f(l) > 1e-7) {
        double m = (l + r) / 2;
        if (f(m) > 100) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << fixed << setprecision(10) << l << endl;
}
