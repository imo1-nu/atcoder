#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S;
    cin >> S;
    atcoder::dsu dsu(S.length());
    for (int i = 0; i < S.length(); i++) {
        for (int j = i + 1; j < S.length(); j++) {
            if (S[i] == S[j]) dsu.merge(i, j);
        }
    }
    auto groups = dsu.groups();

    auto check = [&](string s, int n) {
        string t = to_string(n);
        if (s.length() != t.length()) return false;
        set<char> nums;
        for (auto c : t) nums.insert(c);
        if (nums.size() != groups.size()) return false;
        for (auto group : groups) {
            set<char> v;
            for (int i : group) {
                v.insert(t[i]);
            }
            if (v.size() > 1) return false;
        }
        return true;
    };

    vector<bool> is_prime(10000000, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < 10000000; i++) {
        if (!is_prime[i]) continue;
        if (check(S, i)) {
            cout << i << endl;
            return 0;
        }
        for (int j = i * 2; j < 10000000; j += i) {
            is_prime[j] = false;
        }
    }
    cout << -1 << endl;
}
