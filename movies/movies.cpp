#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long s;
    long e;
    long curr = 0;
    int m = 0;
    cin >> n;
    vector <pair<long,long>> v;
    for (int i = 0; i < n; i++){
        cin >> s;
        cin >> e;
        v.push_back({e, s});//movies pushed in with end as first element
    }
    sort(v.begin(), v.end());
    for (auto x : v){
        if (x.second >= curr){
            curr = x.first;
            m++;
        }
    }
    cout << m;
}