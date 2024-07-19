#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int b = a[i] * a[i + 1];
        cout << b << (i + 1 < n ? ' ' : '\n');
    }
}
