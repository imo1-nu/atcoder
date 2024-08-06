#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long sum = 0;
    int y[n];
    vector<pair<int,int>> x(n);
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        x[i] = make_pair(l,r);
        y[i] = l;
    }
    sort(x.begin(),x.end());
    sort(y, y+n);
    for(long long i = 0; i < n; i++){
        int d = upper_bound(y, y+n, x[i].second) - y;
        sum += (d- i - 1);
        //cout << d << endl;
    }
    cout << sum << endl;
    return 0;
}