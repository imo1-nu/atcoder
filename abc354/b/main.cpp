#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, T = 0;
    cin >> N;
    vector<string> S(N);
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> C[i];
        T += C[i];
    }

    int ans = T % N;

    sort(S.begin(), S.end());
    cout << S[ans] << endl;


    
}
