#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string S ="wbwbwwbwbwbw";

    int W, B;
    cin >> W >> B;
    vector<pair<int, int>> A(W + B + 12);
    A[0].first = 1;
    A[0].second = 0;
    for (int i = 1; i < W + B + 12; i++) {
        if (S[i % 12] == 'w') {
            A[i].first = A[i - 1].first + 1;
            A[i].second = A[i - 1].second;
        }
        else {
            A[i].first = A[i - 1].first;
            A[i].second = A[i - 1].second + 1;
        }
        //cout << i << ' ' << A[i].first << ' ' << A[i].second << endl;
    }

    string ans = "No";
    for (int i = 0; i < 12; i++) {
        if (A[i + W + B].first - A[i].first == W && A[i + W + B].second - A[i].second == B) {
            ans = "Yes";
            break;
        }
    }
    cout << ans << endl;
}
