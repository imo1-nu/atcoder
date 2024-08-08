#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, Q;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> Q;
    vector<int> B(Q);
    for (int i = 0; i < Q; i++) {
        cin >> B[i];
    }
    sort(A.begin(), A.end());

    for (int i = 0; i < Q; i++) {
        auto itr = lower_bound(A.begin(), A.end(), B[i]);
        if (itr == A.begin()) {
            cout << abs(*itr - B[i]) << endl;
        }
        else if (itr == A.end()) {
            cout << abs(*(itr - 1) - B[i]) << endl;
        }
        else {
            cout << min(abs(*itr - B[i]), abs(*(itr - 1) - B[i])) << endl;
        }
    }
}
