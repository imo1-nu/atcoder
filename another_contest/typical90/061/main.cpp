#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int Q;
    cin >> Q;

    deque<int> deq;
    for (int i = 0; i < Q; i++) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            deq.push_front(x);
        } else if (t == 2) {
            deq.push_back(x);
        } else {
            cout << deq[x - 1] << endl;
        }
    }
}
