#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S;
    cin >> S;
    stack<int> st;
    vector<int> mch(S.size(), -1);
    for (int i = 0; i < (int)S.length(); ++i) {
        if (S[i] == '(') {
            st.push(i);
        }
        else if (S[i] == ')') {
            mch[st.top()] = i;
            mch[i] = st.top();
            st.pop();
        }
        else if ((int)st.size() % 2 == 1) S[i] ^= 32;
    }

    int cur = 0;
    int dir = 1;
    while (cur < (int)S.length()) {
        if (S[cur] == '(' || S[cur] == ')') {
            cur = mch[cur];
            dir *= -1;
        }
        else {
            cout << S[cur];
        }
        cur += dir;
    }
    cout << endl;
}
