#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N, S;
    ll L;
	cin >> N >> S >> L;
	S--;
	vector<ll> A(N - 1);
	for (auto& a : A) cin >> a;

	int ans = 1;
	vector<ll> sum(N);
	for (int i = 1; i < N; i++) sum[i] = sum[i - 1] + A[i - 1];
	for (int l = 0; l <= S; l++) {
		for (int r = S; r < N; r++) {
			ll x = sum[S] - sum[l], y = sum[r] - sum[S];
			if (min(2 * x + y, x + 2 * y) <= L) ans = max(ans, r - l + 1);
		}
	}
	cout << ans << endl;
}
