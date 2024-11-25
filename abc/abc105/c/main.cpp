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
    stack<int> ans;
    while (N != 0) {
        if (N % 2 != 0) {
            N--;
            ans.push(1);
        } else {
            ans.push(0);
        }
        N /= -2;
    }
    if (ans.empty()) {
        cout << 0 << endl;
    }
    else {
        while (!ans.empty()) {
            cout << ans.top();
            ans.pop();
        }
        cout << endl;
    }
}
