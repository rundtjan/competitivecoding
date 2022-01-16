#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

unordered_set <string> ps;//permutations

void haku(string p, int s, int e){//s=start, e=end of string
    if (s == e) {
        ps.insert(p);
    } else {
        for (int i = s; i <= e; i++)
        {
            swap(p[s], p[i]);
            haku(p, s+1, e);
        }
    }
}

int main() {
    vector<string> v;
    string input;
    cin >> input;
    int n = input.size();
    haku(input, 0, n-1);
    cout << ps.size() << "\n";
    for (auto itr = ps.begin(); itr != ps.end(); itr++){
        v.push_back(*itr);
    }
    sort(v.begin(), v.end());
    auto it = v.begin();
    while (it != v.end()){
        cout << *it << "\n";
        it++;
    }
}