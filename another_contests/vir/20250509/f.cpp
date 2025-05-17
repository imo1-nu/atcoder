#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int maxA = 100000;
    vector<int> min_soinsu(maxA + 1);
    for (int i = 2; i <= maxA; i++) {
        if (min_soinsu[i] != 0) continue;
        for (int j = i; j <= maxA; j += i) {
            min_soinsu[j] = i;
        }
    }

    vector<int> Grundy(maxA + 1);
    for (int i = 2; i <= maxA; i++) {
        Grundy[i] = Grundy[i / min_soinsu[i]] + 1;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans ^= Grundy[A[i]];
    }
    if (ans == 0) cout << "Bruno" << endl;
    else cout << "Anna" << endl;
}
