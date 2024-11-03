#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    map<int, int> chokuzen;
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        if (chokuzen.count(A[i])) {
            B[i] = chokuzen[A[i]];
        }
        else {
            B[i] = -1;
        }
        chokuzen[A[i]] = i + 1;
    }

    for (int i = 0; i < N; i++) {
        cout << B[i];
        if (i < N - 1) {
            cout << " ";
        }
        else {
            cout << endl;
        }
    }
}
