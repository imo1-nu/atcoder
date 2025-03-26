#include <bits/stdc++.h>
#include <atcoder/all>
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
    map<int, vector<int>> cnt;
    for (int i = 0; i < N; i++) {
        cnt[A[i]].push_back(i);
    }
    for (auto itr = cnt.rbegin(); itr != cnt.rend(); itr++) {
        if (itr->second.size() == 1) {
            cout << itr->second[0] + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
