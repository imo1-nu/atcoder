#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    while (1) {
        int N;
        cin >> N;
        if (N == 0) break;
        ll sum = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                sum += i * j;
            }
        }
        cout << sum << endl;
    }
}