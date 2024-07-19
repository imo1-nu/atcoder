#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    int size = s.size();

    bool ans = false;
    for (int w = 1; w < size; w++) {
        for (int c = 0; c < w; c++) {
            string u = s.substr(c, 1);
            for (int i = c + w; i < size; i += w) {
                u = u + s.substr(i, 1);
            }
            if (u == t) ans = true;
        }
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}
