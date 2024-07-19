#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string S;
    cin >> S;
    int i = 0;
    for (; S[i] != '|'; i++) cout << S[i];
    i++;
    for (; S[i] != '|'; i++);
    i++;
    for (; i < S.length(); i++) cout << S[i];
    cout << endl;
}
