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
    cout << N / 10 % 10 << N % 10 << N / 100 << " ";
    cout << N % 10 << N / 100 << N / 10 % 10 << endl;
}
