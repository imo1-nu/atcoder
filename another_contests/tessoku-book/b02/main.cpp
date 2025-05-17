#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    bool ans = false;
    vector<int> c = {1, 2, 4, 5, 10, 20, 25, 50, 100};
    for (int i = 0; i < 9; i++) {
        if (a <= c[i] && b >= c[i]) ans = true;
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}
