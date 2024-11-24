#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

vector<pair<int, int>> encode(vector<int> A) {
    int N = (int)A.size();
    vector<pair<int, int>> ret;
    for (int l = 0; l < N;) {
        int r = l + 1;
        for (; r < N && A[l] == A[r]; r++) {};
        if (r - l > 2) {
            ret.push_back({A[l], 2});
            ret.push_back({A[l], 2});
        }
        else ret.push_back({A[l], r - l});
        l = r;
    }
    return ret;
}

string decode(const vector<pair<char, int>>& code) {
    string ret;
    for (auto [c, cnt] : code) {
        ret += string(cnt, c);
    }
    return ret;
}

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

    vector<pair<int, int>> code = encode(A);

    set<int> st;
    int l = 0, r = 0;
    int ans = 0;
    while (r < (int)code.size()) {
        if (st.count(code[r].first) || code[r].second < 2) {
            st.erase(code[l].first);
            l++;
            if (l > r) r++;
        }
        else {
            st.insert(code[r].first);
            r++;
        }
        ans = max(ans, 2 * (r - l));
    }
    cout << ans << endl;
}
