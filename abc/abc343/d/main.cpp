#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, T;
    cin >> N >> T;
    vector<long long> score(N, 0);
    map<long long, int> mp;
    mp[0] = N;
    for (int i = 0; i < T; i++) {
        int A, B;
        cin >> A >> B;
        A--;
        if (--mp[score[A]] == 0) mp.erase(score[A]);
        score[A] += B;
        ++mp[score[A]];
        cout << mp.size() << endl;
    }
}
