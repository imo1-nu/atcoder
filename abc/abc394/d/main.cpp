#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S;
    cin >> S;
    stack<char> st;
    bool ans = true;
    for (auto c : S) {
        if (c == '(' || c == '[' || c == '<') {
            st.push(c);
        }
        else {
            if (st.empty()) {
                ans = false;
                break;
            }
            char t = st.top();
            st.pop();
            if (c == ')' && t != '(') {
                ans = false;
                break;
            }
            if (c == ']' && t != '[') {
                ans = false;
                break;
            }
            if (c == '>' && t != '<') {
                ans = false;
                break;
            }
        }
    }
    if (!st.empty()) ans = false;
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
