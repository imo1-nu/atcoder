#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S, T;
    cin >> S >> T;
    int a, b;
    if ((S[1] - S[0] + 5) % 5 == 1 || (S[1] - S[0] + 5) % 5 == 4) a = 1;
    else a = 0;
    if ((T[1] - T[0] + 5) % 5 == 1 || (T[1] - T[0] + 5) % 5 == 4) b = 1;
    else b = 0;
    if (a == b) cout << "Yes" << endl;
    else cout << "No" << endl;
}
