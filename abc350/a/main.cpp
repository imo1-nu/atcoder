#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S, T;
    cin >> S;
    T = S.substr(3, 3);
    int a = stoi(T);
    if (a < 350 && a > 0 && a != 316) cout << "Yes" << endl;
    else cout << "No" << endl;
}
