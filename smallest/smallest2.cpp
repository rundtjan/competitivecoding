#include <iostream>
#include <unordered_map>


using namespace std;

int main() {//use unordered map to find good place to start
    unordered_map<int, int> umap;
    time_t time1;
    time_t time2;
    int n;
    cin >> n;
    int c; //int from read
    for (int i = 0; i < n; i++){
        cin >> c;
        umap[c] = i;
    }
    time1 = time(NULL);
    int t1;//temp
    int t2;//temp2
    t1 = umap.at(1);
    int r = 1;
    for (int i = 2; i < n+1; i++){
        t2 = umap.at(i);
        if (t2 < t1){
            r++;
        }
        t1 = t2;
    }
    time2 = time(NULL);
    //cout << time2 - time1 << endl;
    cout << r << endl;
}