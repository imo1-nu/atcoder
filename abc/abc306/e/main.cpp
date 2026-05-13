#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(N);
    map<int, int> S1, S2;
    S1[0] = K;
    S2[0] = N - K;
    while (Q--) {
        int x, y;
        cin >> x >> y;
        int a = A[x - 1];
        if (S1.count(a)) {
            
        }
    }
}
