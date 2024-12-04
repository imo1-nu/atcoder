#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;

    vector<int> right(N + 1, N);
    for (int i = N - 1; i >= 0; --i) {
        if (S[i] == '1') {
            right[i] = right[i + 1];
        }
        else {
            right[i] = i;
        } 
    }

    vector<int> ans;
    int cur = N;
    while (cur > 0) {
        int next = right[max(0, cur - M)];
        if (next == cur) {
            cout << -1 << endl;
            return 0;
        }
        ans.push_back(cur - next);
        cur = next;
    }
    reverse(ans.begin(), ans.end());
    for (int a : ans) {
        cout << a << " ";
    }
    cout << endl;
}
