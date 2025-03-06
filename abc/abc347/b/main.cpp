#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S;
    cin >> S;
    unordered_set<string> st;
    for (int i = 0; i < (int)S.length(); i++) {
        for (int j = 1; i + j <= (int)S.length(); j++) {
            st.insert(S.substr(i, j));
        }
    }
    cout << st.size() << '\n';
}
