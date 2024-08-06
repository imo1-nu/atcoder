#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, i, ans = 3;
    string S, T;
    cin >> N >> M >> S >> T;
    if (T.substr(0, N) == S) ans -= 2;
    if (T.substr(M - N, N) == S) ans--;
    cout << ans << endl;
}
