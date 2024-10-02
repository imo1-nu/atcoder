#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> H(N + 1);
    H[0] = 1e9;
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }

    vector<int> A(N + 2);
    stack<int> st;
    st.push(0);
    for (int i = 1; i <= N; i++) {
        while (H[st.top()] <= H[i]) {
            st.pop();
        }
        A[st.top()]++;
        //cout << st.top() << " ";
        A[i]--;
        st.push(i);
    }
    vector<int> S(N + 2);
    for (int i = 1; i <= N + 2; i++) {
        S[i] = S[i - 1] + A[i - 1];
    }
    for (int i = 2; i <= N + 1; i++) {
        cout << S[i] << " ";
    }
    cout << endl;
}
