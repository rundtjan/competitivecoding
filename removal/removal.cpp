#include<iostream>
#include<vector>
 
using namespace std;
 
int main(){
    int n;
    cin >> n;
    vector<long> nbs (n);
    vector<vector<pair<long,long>>> values;
    for (int i = 0; i<n;i++){
        cin >> nbs[i];
        vector<pair<long,long>> vals(n+1, {0,0});
        values.push_back(vals);
    }
    int length = 1;//start with the basecase
    for (int i = 0; i < n; i++){
        values[i][length] = {nbs[i], 0}; //if array has 1 element, the first to pick gets that element, second gets none
    }
    for (length = 2; length <= n; length++){
        for (int i = 0; i <= n-length; i++){
            //compare choosing lefthandside + second value of the array that is left with choosing right hand side + second value of array that is left
            //enter best result and result of second choice into value[i][length]
            long leftchoice = nbs[i] + values[i+1][length-1].second;
            long rightchoice = nbs[i+length-1] + values[i][length-1].second;
            if (leftchoice > rightchoice){
                values[i][length] = {leftchoice, values[i+1][length-1].first};
            } else {
                values[i][length] = {rightchoice, values[i][length-1].first};
            }
        }
    }
    cout << values[0][n].first; //print the value starting at the beginning of the array and with full length of array
}

