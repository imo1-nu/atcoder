#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll inversion_number(vector<int> &v) {
    int N = v.size();
    if (N == 1) return 0;
    vector<int> v1(v.begin(), v.begin() + N / 2);
    vector<int> v2(v.begin() + N / 2, v.end());
    ll res = inversion_number(v1) + inversion_number(v2);
    int p = 0, q = 0;
    for (int i = 0; i < N; i++) {
        if (q == v2.size() || (p < v1.size() && v1[p] <= v2[q])) {
            v[i] = v1[p++];
        }
        else {
            v[i] = v2[q++];
            res += v1.size() - p;
        }
    }
    return res;
}