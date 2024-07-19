#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, Q;
    cin >> N;
    vector<int> P(N + 1);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        P[a] = i;
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int A, B;
        cin >> A >> B;
        if (P[A] < P[B]) cout << A << endl;
        else cout << B << endl;
    }
}
