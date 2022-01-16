#include<iostream>
#include<set>
#include<queue>
#include<map>
#include<vector>
#include<unordered_map>
 
using namespace std;

priority_queue<int> v;//vacant

void free(int r){
    r *= -1;
    v.push(r);
}

int getroom(){
    int r = v.top();
    v.pop();
    return r * -1;
}
 
 
int main(){
    int n;
    cin >> n;
    int s;
    int e;
    int r; // room
    int roomcount = 0;
    vector<int> vacant;
    map<int, vector<int>> booked;
    unordered_map<string,vector<int>> umap;
    multiset<pair<int,int>> c;
    vector<int> answer(n);
    for (int i = 0; i < n; i++){
        cin >> s >> e;
        c.insert({s,e});
        auto start = to_string(s);
        auto end = to_string(e);
        if (umap.count(start+","+end) != 0){
            umap[start+","+end].push_back(i);
        } else {
            vector<int> se = {i};
            umap[start+","+end] = se;
        }
    }
    int index = 0;
    auto it = c.begin();
    while (it != c.end()){
        s = it->first;
        e = it->second;
        auto start = to_string(s);
        auto end = to_string(e);
        //cout << start+","+end << "\n";
        index = umap[start+","+end].back();
        umap[start+","+end].pop_back();
        //cout << umap[s+","+e].back();
        if (booked.size()>0){
        if (booked.begin()->first < s){//rooms have become vacant
            while(booked.begin()->first < s){//place vacant rooms back in vacantqueue
                auto begin = booked.begin();
                free(begin->second.back());
                begin->second.pop_back();
                if (begin->second.empty()){booked.erase(begin);}//if no more rooms booked to that day erase list
               break;
            }
        }
        }
        if (v.empty()){
            roomcount++;//create more rooms
            r = roomcount;
        } else {
            r = getroom();
        }

        if (booked.find(e) != booked.end()){//exists entry for rooms booked to end-date
            booked[e].push_back(r);
        } else {
            vector<int> rs = {r};
            booked[e] = rs;
        }
        answer[index] = r;
        it++;
    }
    cout << roomcount << "\n";
    for (int i = 0; i < n; i++){
        cout << answer[i] << " ";
    }
}