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
    for (auto& a : A) cin >> a;
    
    vector<int> cnt(3);
    for (auto a : A) {
        int out = ((a - 1) / 1000 + 1) * 1000;
        int otsuri = out - a;
        cnt[0] += otsuri % 10;
        cnt[1] += otsuri / 10 % 10;
        cnt[2] += otsuri / 100 % 10;
    }
    for (auto c : cnt) cout << c << " ";
    cout << endl;
}
