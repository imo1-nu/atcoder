#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, R;
    cin >> N >> R;
    vector<int> D(N), A(N);
    for (int i = 0; i < N; ++i) {
        cin >> D[i] >> A[i];
    }

    for (int i = 0; i < N; ++i) {
        if (D[i] == 1 && 1600 <= R && R < 2800 || D[i] == 2 && 1200 <= R && R < 2400) {
            R += A[i];
        }
    }
    cout << R << endl;
}
