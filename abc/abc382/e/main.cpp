#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, X;
    cin >> N >> X;
    vector<double> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i] /= 100;
    }
}
