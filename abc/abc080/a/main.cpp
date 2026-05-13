#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, A, B;
    cin >> N >> A >> B;
    cout << min(A * N, B) << endl;
}
