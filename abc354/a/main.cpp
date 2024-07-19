#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int H, sum = 1, p = 1, i;
    cin >> H;
    for (i = 1; 1; i++) {
        p *= 2;
        sum += p;
        if (sum > H) break;
    }

    cout << i + 1 << endl;
    
}
