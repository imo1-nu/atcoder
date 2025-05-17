#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s;
    cin >> s;
    vector<pair<char, int>> st;
    queue<pair<int, int>> ans;
    int size = s.size();
    int tail;
    for (int i = 0; i < size; i++) {
        st.push_back({s[i], i + 1});
        tail++;
        while (tail >= 2 && st[tail - 1].first == ')') {
            if (st[tail - 2].first == '(') {
                ans.push({st[tail - 2].second, st[tail - 1].second});
                st.pop_back();
                st.pop_back();
                tail -= 2;
            }
        }
    } 
    while (!ans.empty()) {
        cout << ans.front().first << ' ' << ans.front().second << endl;
        ans.pop();
    }
}
