#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector <int> c(n);
    vector <int> o(n);//order
    if (n == 1){
        cout << 1;
        return 0;
    }
    for (int i = 0; i < n; i++){
        c[i] = i+1;
    }
    int count = 0;
    int take = 1;
    int newi = 0;
    int taken = 0;
    int size = n;
    while (true){
        if (taken == n){
            break;
        }
        for (int i = 0; i < size; i++){
            if (count == take){
                //cout << "taking " << c[i] << "\n";
                o[taken] = c[i];
                taken++;
                count = 0;
            } else {
                c[newi] = c[i];
                newi++;
                count++;
                //for (int j = 0; j < size; j++){
                //    cout << c[j] << " ";
                //}
            }
        }
        size = newi;
        newi = 0;
    }
    for (int i = 0; i < n; i++){
        cout << o[i] << " ";
    }
}