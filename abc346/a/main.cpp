#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    int a1, a2, b;
    cin >> a2;
    for (int i = 0; i < N - 2; i++) {
        a1 = a2;
        cin >> a2;
        cout << a1 * a2 << ' ';
    }
    a1 = a2;
    cin >> a2;
    cout << a1 * a2 << endl;
}
