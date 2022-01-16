#include<iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include<set>
#include<queue>
#include<vector>
#include<map>
#include<unordered_map>
 
using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
int main(){
    int n;
    cin >> n;
    vector<int> result;
    int k;
    cin >> k;
    indexed_set circle;
    for (int i = 1; i < n+1; i++){
        circle.insert(i);
    }
    /*for (int i = 0; i < (int)circle.size(); i++){
        cout << *circle.find_by_order(i) << " in circle" << "\n";
    }*/
    int i = 0;
    int t;
    while((int)circle.size() >0){
        i+=k;
        if (i > (int)circle.size()-1){
            i = i % circle.size();
        }
        //cout << "this is i " << i << "\n";
        t = *circle.find_by_order(i);
        //cout << "found t " << t << "\n";
        circle.erase(t);
        result.push_back(t);
        //cout << "working: " << i << " size " << (int)circle.size() << "\n";
    }
    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }
}