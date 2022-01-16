#include <set>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;


int main() {
    int n;
    int m;
    cin >> n;
    cin >> m;
    typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
    indexed_set prices;
    vector<int> c(m);//customers
    unordered_map<int, int> umap;
    int t;

    for (int i = 0; i < n; i++){
        cin >> t;
        prices.insert(t);
        if (umap.find(t) == umap.end()){
            umap[t] = 1;
        } else {
            umap.at(t) += 1;
        }
    }

    for (int i = 0; i < m; i++){
        cin >> c[i];
    }


    int order;
    for (int i = 0; i < m; i++){
        if (umap.find(c[i]) != umap.end() && umap.at(c[i]) != 0){//if it's in the map, just print and erase one instance
            cout << c[i] << "\n";
            umap.at(c[i]) -= 1;
        } else {//otherwise use helper indexed set to find closest
            order = prices.order_of_key(c[i]) -1;
            auto x = prices.find_by_order(order);
            t = *x;
            if (t == 0){
                t = -1;
            } else {
                while (umap.at(t) == 0){//if this price is already used up
                    prices.erase(t);
                    order--;
                    x = prices.find_by_order(order);
                    t = *x;
                    if (t == 0){
                        t = -1;
                        break;
                    }
                }
                if (t != -1){umap[t] = umap.at(t) -1;}
            }
            cout << t << "\n";
        }
    }
}