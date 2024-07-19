#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N + 1), m(N + 1);
    //map<int, int> m;
    for (int i = 1; i <= N; i++) cin >> A[i];

    for (int i = 1; i <= N; i++) {
        m[A[i]] = i;
    }

    //for (int i = 1; i <= N; i++) cout << m[i] << endl;

    vector<int> B, C;
    int cnt = 0;
    for (int i = 1; i < N; i++) {
        int a;
        if (m[i] == i) continue;
        B.push_back(i);
        C.push_back(m[i]);
        a = A[i];
        A[i] = i;
        A[m[i]] = a;
        m[a] = m[i];
        m[i] = i;
        cnt++;
    }

    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) cout << B[i] << ' ' << C[i] << endl;
    
}
