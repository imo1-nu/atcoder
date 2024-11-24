#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S;
    set<int> st;
    cin >> S;

    bool ans = true;
    for (int i = 0; i < S.size(); i += 2) {
        if (S[i] != S[i + 1] || st.count(S[i] - 'a')) {
            ans = false;
            break;
        }
        st.insert(S[i] - 'a');
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
