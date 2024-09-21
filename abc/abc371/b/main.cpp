#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    vector<char> B(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
    }
    vector<bool> used(N, false);
    vector<bool> taro(M, false);
    for (int i = 0; i < M; i++) {
        if (!used[A[i]] && B[i] == 'M') {
            used[A[i]] = true;
            taro[i] = true;
        }
    }
    for (int i = 0; i < M; i++) {
        if (taro[i]) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}
