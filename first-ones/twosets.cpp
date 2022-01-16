#include <iostream>

using namespace std;

int main() {
    int n;
    long s = 0;
    cin >> n;
    if (n < 3){
        cout << "NO";
        return 0;
    }
    int t[n];
    for (int i = 0; i < n; i++){
        t[i] = i + 1;
        s = s + t[i];
    }
    if (s % 2 != 0){
        cout << "NO\n";
        return 0;
    } else {
        cout << "YES\n";
    }
    long h = s / 2;//get the halfsum
    //cout << h << " is the halfsum\n";
    int si[n];//the subsets s-one
    int sii[n];//s-two
    s = 0;//new sum
    int sij = 0;//index for appending to subset-one
    int siij = 0;//index for appending to subset-two
    for (int j = n-1; j > -1; j--){
        //cout << "now in array " << t[j] << "\n";
        if (s + t[j] > h){//if adding element to subset would push it over half the sum
            sii[siij] = t[j];
            siij++;
        } else {//append to subset one and add to halfsum
            si[sij] = t[j];
            s = s + t[j];
            sij++;
        }
    }
    cout << siij << "\n";
    for (int k = 0; k < siij; k++){
        cout << sii[k] << " ";
    }
    cout << "\n";
    cout << sij << "\n";
    for (int k = 0; k < sij; k++){
        cout << si[k] << " ";
    }

}