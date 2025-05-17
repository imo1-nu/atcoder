#include <bits/stdc++.h>
using namespace std;
using ll = long long;


using Graph = vector<vector<pair<int,int>>>;
using T = tuple<int, int, int>;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m + 1), b(m + 1), s(m + 1), t(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> s[i] >> b[i] >> t[i];
        t[i] += k;
    }
    
    vector<T> List;
    for (int i = 1; i <= m; i++) {
        List.push_back(T{s[i], 2, i});
        List.push_back(T{t[i], 1, i});
    }
    for (int i = 1; i <= n; i++) {
        List.push_back(T{-1, 0, i});
        List.push_back(T{2100000000, 0, i});
    }
    sort(List.begin(), List.end());
    
    vector<int> VertS(m + 1), VertT(m + 1);
    for (int i = 0; i < List.size(); i++) {
        if (get<1>(List[i]) == 2) VertS[get<2>(List[i])] = i + 1;
        if (get<1>(List[i]) == 1) VertT[get<2>(List[i])] = i + 1;
    }

    vector<vector<int>> AP(n + 1);
    for (int i = 0; i < List.size(); i++) {
        if (get<1>(List[i]) == 0) AP[get<2>(List[i])].push_back(i + 1);
        if (get<1>(List[i]) == 1) AP[b[get<2>(List[i])]].push_back(i + 1);
        if (get<1>(List[i]) == 2) AP[a[get<2>(List[i])]].push_back(i + 1);
    }

    Graph G(List.size() + 2);
    for (int i = 1; i <= m; i++) {
        G[VertT[i]].push_back(make_pair(VertS[i], 1));
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (int)AP[i].size() - 1; j++) {
            int idx1 = AP[i][j];
            int idx2 = AP[i][j + 1];
            G[idx2].push_back(make_pair(idx1, 0));
        }
    }
    
    for (int i = 1; i <= n; i++) {
        G[AP[i][0]].push_back(make_pair(0, 0));
        G[List.size() + 1].push_back(make_pair(AP[i][AP[i].size() - 1], 0));
    }

    vector<int> dp(List.size() + 2, 0);
    for (int i = 1; i < List.size() + 2; i++) {
        for (int j = 0; j < G[i].size(); j++) {
            dp[i] = max(dp[i], dp[G[i][j].first] + G[i][j].second);
        }
        
    }
    
    cout << dp[List.size() + 1] << endl;
}
