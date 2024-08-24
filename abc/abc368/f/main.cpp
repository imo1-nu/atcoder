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
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<int>> soinsu(100001);
    for (int i = 2; i <= 100000; i++) {
        if (soinsu[i].size() == 0) {
            for (int j = i; j <= 100000; j += i) {
                soinsu[j].push_back(i);
            }
        }
    }

    vector<int> Grundy(100001, 0);
    Grundy[1] = 0;
    for (int i = 2; i <= 100000; i++) {
        for (int p : soinsu[i]) {
            Grundy[i] = max(Grundy[i], Grundy[i / p] + 1);
        }
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans ^= Grundy[A[i]];
    }
    if (ans == 0) cout << "Bruno" << endl;
    else cout << "Anna" << endl;
}
