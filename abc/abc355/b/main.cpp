#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    map<int, int> A, B;
    int N, M, a;
    cin >> N >> M;
    vector<int> C;
    for (int i = 0; i < N; i++) {
        cin >> a;
        A[a]++;
        C.push_back(a);
    }
    for (int i = 0; i < M; i++) {
        cin >> a;
        B[a]++;
        C.push_back(a);
    }
    sort(C.begin(), C.end());
    int ans = 0;
    for (int i = 0; i < N + M - 1; i++) {
        if (A[C[i]] * A[C[i + 1]] != 0) {
            ans = 1;
            break;
        }
        
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;

    //for (int i = 0; i < N + M; i++) cout << C[i] << endl;
}
