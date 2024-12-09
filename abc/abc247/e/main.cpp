#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;

int N, X, Y;

ll calc(vector<int> B) {
    int l = 0, r = 0;
    int cntX = 0, cntY = 0;
    int len = B.size();
    ll res = 0;
    while (l < len) {
        while (r < len && (cntX == 0 || cntY == 0)) {
            if (B[r] == X) cntX++;
            if (B[r] == Y) cntY++;
            r++;
        }
        if (cntX > 0 && cntY > 0) res += len - r + 1;
        if (B[l] == X) cntX--;
        if (B[l] == Y) cntY--;
        l++;
    }
    return res;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> X >> Y;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> ngs;
    ngs.push_back(-1);
    for (int i = 0; i < N; i++) {
        if (A[i] > X || A[i] < Y) {
            ngs.push_back(i);
        }
    }
    ngs.push_back(N);

    ll ans = 0;
    for (int i = 0; i < (int)ngs.size() - 1; i++) {
        if (ngs[i + 1] - ngs[i] == 1) continue;
        vector<int> b;
        for (int j = ngs[i] + 1; j < ngs[i + 1]; j++) {
            b.push_back(A[j]);
        }
        ans += calc(b);
    }
    cout << ans << endl;
}
