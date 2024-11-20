#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    stack<string> s;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            string t;
            cin >> t;
            s.push(t);
        }
        else if (a == 2) cout << s.top() << endl;
        else s.pop();
    }
    
}
