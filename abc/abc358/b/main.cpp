#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, a;
    cin >> n >> a;
    vector<int> t(n);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        q.push(t[i]);
    }
    
    int now = 0;
    while (!q.empty()) {
        int b = q.front();
        q.pop();
        if (now <= b) {
            now = b + a;
        }
        else {
            now += a;
        }
        cout << now << endl;
    }
}
