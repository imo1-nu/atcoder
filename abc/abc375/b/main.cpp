#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}   

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<double> X(N + 2), Y(N + 2);
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i];
    }

    double ans = 0;
    for (int i = 0; i <= N; i++) {
        ans += dist(X[i], Y[i], X[i + 1], Y[i + 1]);
    }
    cout << fixed << setprecision(10) << ans << endl;
}
