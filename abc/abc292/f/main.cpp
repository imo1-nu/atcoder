#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    double A, B;
    cin >> A >> B;
    if (A > B) swap(A, B);

    double theta = atan(2 * B / A - sqrt(3));
    double ans = A / cos(theta);
    ans = min(ans, A / sin(M_PI / 3));
    cout << fixed << setprecision(12) << ans << endl;
}
