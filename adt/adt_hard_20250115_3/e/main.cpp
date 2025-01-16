#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        sum += A[i];
    }

    double l = 0, r = sum;
    while (r - l > 1e-7) {
        double m = (l + r) / 2;
        double lt = 0, rt = 0;
        int L = 0, R = sum;
        for (int i = 0; L < m; i++) {
            if (L + A[i] < m) {
                L += A[i];
                lt += double(A[i]) / B[i];
            }
            else {
                lt += (m - L) / B[i];
                break;
            }
        }
        for (int i = N - 1; R > m; i--) {
            if (R - A[i] > m) {
                R -= A[i];
                rt += double(A[i]) / B[i];
            }
            else {
                rt += (R - m) / B[i];
                break;
            }
        }
        if (lt < rt) l = m;
        else r = m;
    }
    cout << fixed << setprecision(10) << l << endl;
}
