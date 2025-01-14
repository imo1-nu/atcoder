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
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    for (int i = N - 1; i >= 0; i--) {
        vector<int> A = P;
        sort(A.begin() + i, A.end());
        if (A != P) {
            int x = min_element(P.begin() + i, P.end()) - P.begin();
            for (int j = i + 1; j < N; j++) {
                if (P[x] < P[j] && P[j] < P[i]) x = j;
            }
            swap(P[i], P[x]);
            sort(P.begin() + i + 1, P.end(), greater<int>());
            break;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << P[i] << ' ';
    }
    cout << endl;
}
