#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, score = 0;
    char c;
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        char a;
        cin >> a;
        if (a == 'R') score += 2;
        if (a == 'B') score++;
    }
    bool ans = false;
    if (c == 'R' && score % 3 == 2) ans = true;
    if (c == 'B' && score % 3 == 1) ans = true;
    if (c == 'W' && score % 3 == 0) ans = true;

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}
