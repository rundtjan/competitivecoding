#include<iostream>
#include<vector>
 
using namespace std;
 
int main(){
    int n;
    int M = 1000000007;
    cin >> n;
    int tsum = n*(n+1)/2;
    if (tsum % 2 != 0){cout << 0; return 0;}//if odd number no way to solve it
    int half = tsum/2;
    vector<vector<int>> count;
    for (int i = 0; i < n+1; i++){
        vector<int> sums(half+1, 0);
        count.push_back(sums);
    }
    count[0][0] = 1; //basecase: only one way to make a zerosum with zero elements
    for (int elem = 1; elem < n+1; elem++){
        for (int sum = 0; sum < half+1; sum++){
            count[elem][sum] = count[elem-1][sum]; //atleast you can always create the sum in all the ways you could do it without element
            if (sum-elem > -1){
                count[elem][sum] += count[elem-1][sum-elem]; //if you use i you can ride on all the ways you could reach sum-i without i
                count[elem][sum] = count[elem][sum] % M; //modulo it
            }
        }
    }
    cout << count[n-1][half];//choosing n-1 to only get half of the sets, because then we have two sets (not one)


    }

