#include<bits/stdc++.h>
using namespace std;

map<int, int> compression(vector<int> &v) {
    map<int, int> mp;
    vector<int> tmp = v;
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for(int i = 0; i < tmp.size(); i++) mp[tmp[i]] = i;
    return mp;
}