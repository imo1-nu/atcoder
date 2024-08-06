#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0) cout << 'x';
        else cout << 'o';
    }
    cout << endl;
}
