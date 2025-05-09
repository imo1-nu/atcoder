#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int Q, X;
    cin >> Q;
    queue<int> q;
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            q.push(x);
        }
        else {
            cout << q.front() << endl;
            q.pop();
        }
    }
}
