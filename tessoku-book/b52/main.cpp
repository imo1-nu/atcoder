#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, x;
    string a;
    cin >> n >> x >> a;
    queue<int> q;
    a[--x] = '@';
    q.push(x);
    while (!q.empty()) {
        int pos = q.front();
        q.pop();
        if (pos > 0 && a[pos - 1] == '.') {
            a[pos - 1] = '@';
            q.push(pos - 1);
        }
        if (pos < n - 1 && a[pos + 1] == '.') {
            a[pos + 1] = '@';
            q.push(pos + 1);
        }
    }
    cout << a << endl;
}
