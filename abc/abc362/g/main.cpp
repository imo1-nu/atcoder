#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string S;
    int Q;
    cin >> S >> Q;
    auto SA = atcoder::suffix_array(S);

    while (Q--) {
        string T;
        cin >> T;

        auto compare = [&](int i) {
            return S.compare(i, T.size(), T);
        };

        auto l = lower_bound(SA.begin(), SA.end(), T, [&](int i, const string &T) {
            return compare(i) < 0;
        });

        auto r = lower_bound(SA.begin(), SA.end(), T, [&](int i, const string &T) {
            return compare(i) <= 0;
        });

        cout << r - l << endl;
    }
}
