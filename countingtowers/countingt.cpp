#include<iostream>
#include<vector>
 
using namespace std;

//working with 6 possible structures 0: |___|, 1: |_|_|, 2: |_| |, 3: | |_|, 4: | | |, 5: |   |
//structures 2,3,4,5 can only inherit options from 2:1,2,3,4, 3:1,2,3,4, 4:1,2,3,4 and 5: 0,5
//first row initialized with options 0:1, 1:1, the rest is 0.
//from rows above that, the magic begins.
//the last "ceiling" on top of the tower is ignored.
 
int main(){
    int M = 1000000007;
    int n = 0;
    int temp = 0;
    int top = 0;
    cin >> n;
    vector<int> ts (n,0);
    for (int i = 0; i < n; i++){
        cin >> temp;
        top = max(top, temp);
        ts[i] = temp;
    }
    long options[top][6];
    options[0][0] = 1;
    options[0][1] = 1;
    for (int i = 2; i <= 5; i++)
        options[0][i] = 0;
    
    for (int i = 1; i < top; i++){
        options[i][0] = (options[i-1][0] + options[i-1][1] +options[i-1][2] +options[i-1][3] +options[i-1][4] +options[i-1][5]) % M;
        options[i][1] = (options[i-1][0] + options[i-1][1] +options[i-1][2] +options[i-1][3] +options[i-1][4] +options[i-1][5]) % M;
        for (int j = 2; j <=4; j++)
            options[i][j] = (options[i-1][1] + options[i-1][2] +options[i-1][3] +options[i-1][4]) % M;
        options[i][5] = (options[i-1][0] + options[i-1][5]) % M;
    }
    for (int i = 0; i < n; i++){
        cout << (options[ts[i]-1][0] + options[ts[i]-1][1] + options[ts[i]-1][2] + options[ts[i]-1][3] + options[ts[i]-1][4] + options[ts[i]-1][5]) % M;
        cout << "\n";
    }
}