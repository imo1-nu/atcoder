#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int q;
    cin >> q;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a;
        if (a == 1) {
            cin >> b;
            pq.push(b);
        }
        else if (a == 2) cout << pq.top() << endl;
        else pq.pop();
    }
    
}
