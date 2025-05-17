#include <bits/stdc++.h>
using namespace std;
using ll = long long;
double n;

double func(double x) {
    return pow(x, 3) + x - n;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    double err = 1e-3;
    double l = 0, r = 100;
    while (abs(func(l)) > err) {
        double mid = (l + r) / 2;
        if (func(mid) > 0) r = mid;
        else l = mid;
    }
    cout << l << endl;
}
