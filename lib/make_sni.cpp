#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MAXN 20000
#define BUF 128

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cout << "Please input the code snippet and end with 'end'." << endl;
    
    char buf[BUF];
    vector<string> A(MAXN);
    int size = 0;

    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        A[size] = buf;
        A[size] = A[size].substr(0, A[size].length() - 1);
        if (A[size++] == "end") break;
    }

    string name, prefix;
    cout << "name?" << endl;
    cin >> name;
    cout << "prefix?" << endl;
    cin >> prefix;
    cout << endl;
    
    cout << "    " << '"' << name << '"' << ":{" << endl;
    cout << "        " << '"' << "prefix" << '"' << ": " << '"' << prefix << '"' << ',' << endl;
    cout << "        " << '"' << "body" << '"' << ": [" << endl;
    
    
    for (int i = 0; i < size - 1; i++) {
        cout << "            " << '"' << A[i] << '"' << ',' << endl;
    }

    cout << "        " << "]" << endl;
    cout << "    " << "}," << endl;
}