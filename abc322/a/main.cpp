#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, i, ans = -1;
    string S;
    cin >> N >> S;
    for (i = 0; i < N - 2; i++) {
        if (S.substr(i, 3) == "ABC") {
            ans = i + 1;
            break;
        }
    }
    cout << ans << endl;
}
