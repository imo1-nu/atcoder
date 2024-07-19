#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int q;
    cin >> q;
    queue<string> Q;
    for (int i = 0; i < q; i++) {
        int a;
        string s;
        cin >> a;
        if (a == 1) {
            cin >> s;
            Q.push(s);
        }
        else if (a == 2) cout << Q.front() << endl;
        else Q.pop();
    }
    
}
