#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, sum = 0, a;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> a;
        sum += a;
    }
    cout << -sum << endl;
}
