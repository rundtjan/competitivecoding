#include <iostream>

using namespace std;

int main(){
    int a;
    int b;
    cin >> a >> b;
    int c[a+10][b+10];
    for (int i = 1; i < a+1; i++){
        for (int j = 1; j < b+1; j++){
            c[i][j] = 100000000;//initialize memory with infinity
        }
    }
    int t = min(a,b);
    for (int i = 1; i < t+1; i++){
        c[i][i] = 0; //squares don't require any more moves
    }
    for (int i = 1; i < a+1; i++){
        for (int j = 1; j < b+1; j++){
            for (int s = 1; s < i; s++){//try different slices of side a
                c[i][j] = min(c[i][j], c[s][j] + c[i-s][j] + 1);//either keep value or find a smaller by slicing, adding 1 for transition to sliced
            }
            for (int s = 1; s < j; s++){//try different slices of side b
                c[i][j] = min(c[i][j], c[i][s] + c[i][j-s] + 1);//either keep value or find a smaller by slicing, adding 1 for transition to sliced
            }
        }
    }
    cout << c[a][b]; //result is found smallest version
}