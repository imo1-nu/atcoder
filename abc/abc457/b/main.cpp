#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<vector<int>> A(N);
    for (auto& a : A) {
        int l;
        cin >> l;
        for (int i = 0; i < l; i++) {
            int t;
            cin >> t;
            a.push_back(t);
        }
    }
    int X, Y;
    cin >> X >> Y;
    cout << A[X - 1][Y - 1] << endl;
}
