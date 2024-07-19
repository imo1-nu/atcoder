#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int q;
    cin >> q;
    map<string, int> m;
    for (int i = 0; i < q; i++) {
        string a;
        int b, c;
        cin >> b;
        if (b == 1) {
            cin >> a >> c;
            m[a] = c;
        }
        else {
            cin >> a;
            cout << m[a] << endl;
        }
    }
    
}
