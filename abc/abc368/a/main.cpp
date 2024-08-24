#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = N - K; i < N; i++) {
        cout << A[i] << ' ';
    }
    for (int i = 0; i < N - K; i++) {
        cout << A[i];
        if (i < N - K - 1) {
            cout << ' ';
        }
    }
    cout << endl;
    
    
}
