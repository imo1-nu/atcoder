#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    set<int> s;
    for (int i = 0; i < 4; ++i) {
        int a;
        cin >> a;
        s.insert(a);
    }

    if (s.size() == 2) cout << "Yes" << endl;
    else cout << "No" << endl;
}
