#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int k = K;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] > k) {
            k = K - A[i];
            cnt++;
        }
        else k -= A[i];
    }
    cout << cnt + 1 << endl;
}
