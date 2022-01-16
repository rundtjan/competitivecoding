#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<map>
#include<unordered_map>
 
using namespace std;
 
int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    vector<int> subs;
    map<int,int> umap;
    map<int,bool> insub;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        insub[a[i]] = false;
    }
    long sum = 0;
    int back = 0;
    for (int i = 0; i < n; i++){
        if (!insub[a[i]]){//a new element in the map
            insub[a[i]] = true;
            umap[a[i]] = 0;
            while ((int)umap.size() > k){//gets called if back of window needs to move forward
                umap[a[back]] -= 1;
                if (umap[a[back]] == 0){
                    umap.erase(a[back]);
                    insub[a[back]] = false;
                }
                back++;
            }
        }
        umap[a[i]]++;
        subs.push_back(1+i-back);
    }
 
    for (int i = 0; i < (int)subs.size(); i++){
        sum+=subs[i];
    }
    cout << sum;
}