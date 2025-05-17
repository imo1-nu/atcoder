#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    bitset<10> b = n - 1;
    int ans = 0;
    for (int i = 9; i > -1; i--) {
        if (b.test(i)) cout << 7;
        else cout << 4;
    }
    cout << endl;
}
