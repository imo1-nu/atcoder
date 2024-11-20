#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
vector<int> P;
vector<double> X, Y;

double dist(int p, int q) {
    return sqrt((X[p]-X[q])*(X[p]-X[q]) + (Y[p]-Y[q])*(Y[p]-Y[q]));
}

int RandInt(int l, int r) {
    return rand() % (r-l+1) + l;
}

double Randouble(double l, double r) {
    return (double)rand() / RAND_MAX * (r-l) + l;
}

double GetScore() {
    double res = 0;
    for (int i = 0; i < P.size(); i++) {
        res += dist(P[i], P[i+1]);
    }
    return res;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;

    P.resize(N+2);
    for (int i = 1; i <= N; i++) {
        P[i] = i;
    }
    P[N + 1] = 1;

    X.resize(N+1);
    Y.resize(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i];
    }

    double CurrentScore = GetScore();
    for (int i = 0; i < 200000; i++) {
        int l = RandInt(2, N);
        int r = RandInt(2, N);
        if (l > r) {
            swap(l, r);
        }
        reverse(P.begin() + l, P.begin() + r + 1);
        double NewScore = GetScore();

        double T = 30.00 - 28 * i / 200000;
        double prob = exp((CurrentScore - NewScore) / T);
        if (NewScore < CurrentScore || Randouble(0, 1) < prob) {
            CurrentScore = NewScore;
        } else {
            reverse(P.begin() + l, P.begin() + r + 1);
        }
    }
    
    for (int i = 1; i <= N + 1; i++) {
        cout << P[i] << endl;
    }
}
