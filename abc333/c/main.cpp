#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> ans(400, 200000000000);
    long long re[12] = {1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1111111111, 11111111111, 111111111111};
    int cnt = 0;
    for (int i = 0; i < 12; i++) {
        for (int j = i; j < 12; j++) {
            for (int k = j; k < 12; k++) {
                ans[cnt] = re[i] + re[j] + re[k];
                cnt++;
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[N - 1] << endl;
    //for (int i = 0; i < 10; i++) cout << ans[i] << endl;
}
