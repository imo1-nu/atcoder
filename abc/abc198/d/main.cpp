#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    vector<string> S(3);
    int max_len = 0;
    for (int i = 0; i < 3; i++) {
        cin >> S[i];
    }

    vector<char> chars;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < S[i].size(); j++) {
            chars.push_back(S[i][j]);
        }
    }
    sort(chars.begin(), chars.end());
    chars.erase(unique(chars.begin(), chars.end()), chars.end());

    if (chars.size() > 10) {
        cout << "UNSOLVABLE" << endl;
        return 0;
    }

    vector<int> A(10);
    for (int i = 0; i < 10; i++) {
        A[i] = i;
    }

    do {
        map<char, int> mp;
        for (int i = 0; i < chars.size(); i++) {
            mp[chars[i]] = A[i];
        }
        if (mp[S[0][0]] == 0 || mp[S[1][0]] == 0 || mp[S[2][0]] == 0) {
            continue;
        }

        vector<ll> N(3);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < (ll)S[i].size(); j++) {
                N[i] = N[i] * 10 + mp[S[i][j]];
            }
        }

        if (N[0] + N[1] == N[2]) {
            for (int i = 0; i < 3; i++) {
                cout << N[i] << endl;
            }
            return 0;
        }
    } while (next_permutation(A.begin(), A.end()));

    cout << "UNSOLVABLE" << endl;
}
