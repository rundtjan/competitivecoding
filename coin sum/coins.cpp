#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector <long> c(n);
    for (int i = 0; i < n; i++){
        cin >> c[i];
    }
    long min = 1;
    sort(c.begin(), c.end());
    for (int i = 0; i < n; i++){
        if (c[i] <= min) {
            min = min + c[i];
        } else {
            break;
        }
    }
    cout << min;
}