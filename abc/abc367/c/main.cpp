#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N, K;
    cin >> N >> K;
    vector<int> R(N);
    for (int i = 0; i < N; i++) cin >> R[i];
    int max = 1;
    for (int i = 0; i < N; i++) {
        max *= 10;
    }
    int min = (max - 1) / 9;
    //cout << min << " " << max << endl;
    
    
    for (int i = min; i < max; i++) {
        string S = to_string(i);
        //cout << S << endl;
        int sum = 0;
        int j;
        for (j = 0; j < N; j++) {
            if (S[j] - '0' > R[j] || S[j] == '0') break;
            sum += S[j] - '0';
        }
        if (j == N && sum % K == 0) {
            for (int i = 0; i < N; i++) {
                cout << S[i];
                if (i != N-1) cout << " ";
            }
            cout << endl;;
        }
    }
    
}
