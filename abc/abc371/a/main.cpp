#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector<int> ani(3), oto(3);
    char c[3];
    cin >> c[0] >> c[1] >> c[2];
    if (c[0] == '>') {
        ani[0]++;
        oto[1]++;
    }
    else {
        ani[1]++;
        oto[0]++;
    }
    if (c[1] == '>') {
        ani[0]++;
        oto[2]++;
    }
    else {
        ani[2]++;
        oto[0]++;
    }
    if (c[2] == '>') {
        ani[1]++;
        oto[2]++;
    }
    else {
        ani[2]++;
        oto[1]++;
    }

    int ans;
    for (int i = 0; i < 3; i++) {
        if (ani[i] == oto[i]) {
            ans = i;
            break;
        }
    }
    cout << (char)('A' + ans) << endl;
}
