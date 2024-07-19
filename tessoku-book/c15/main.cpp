#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    int Tmax = 86401 + k;
    vector<pair<int, int>> T1(n), T2(n); //first : R
    vector<int> L(n), R(n);
    for (int i = 0; i < n; i++) {
        cin >> L[i] >> R[i];
        R[i] += k;
        T1[i] = {R[i], L[i]};
        T2[i] = {L[i], R[i]};
    }

    sort(T1.begin(), T1.end());
    sort(T2.rbegin(), T2.rend());

    vector<int> cntL(Tmax);
    int num1 = 0;
    int cur1 = 0;
    for (int i = 0; i < n; i++) {
        if (cur1 <= T1[i].second) {
            cur1 = T1[i].first;
            num1++;
            cntL[cur1] = num1;
        }
    }
    
    vector<int> cntR(Tmax);
    int num2 = 0;
    int cur2 = Tmax;
    for (int i = 0; i < n; i++) {
        if (cur2 >= T2[i].second) {
            cur2 = T2[i].first;
            num2++;
            cntR[cur2] = num2;
        }
    }
    
    for (int i = 1; i < Tmax; i++) {
        cntL[i] = max(cntL[i], cntL[i - 1]);        
    }
    for (int i = Tmax - 2; i >= 0; i--) {
        cntR[i] = max(cntR[i], cntR[i + 1]);        
    }
    
    for (int i = 0; i < n; i++) {
        cout << cntL[L[i]] + 1 + cntR[R[i]] << endl;
    }
}
