#include <iostream>

using namespace std;

int main() {
    int n;
    long m = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int j = 1; j < n; j++){
        while (a[j] < a[j-1]){
            a[j]++;
            m++;
        }
    }/*
    for (int k = 0; k < n; k++){
        cout << a[k] << " ";
    }*/
    cout << m;
}