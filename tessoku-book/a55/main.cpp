#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int q;
    cin >> q;
    set<int> s;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1) s.insert(b);
        else if(a == 2) s.erase(b);
        else {
            auto c = s.lower_bound(b);
            if (c == s.end()) cout << -1 << endl;
            else cout << *s.lower_bound(b) << endl;
        }
    }
    
}
