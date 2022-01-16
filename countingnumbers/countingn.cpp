#include<iostream>
#define ll long long
 
using namespace std;

ll base [19];

ll ans = 0;

void count(int num, int pow, bool be4){//before tells if the integer before restricts answer
    if (be4) num--;//one number away
    if (pow == 0) ans++; //add for the last zero
    ans += num * base[pow];
}

void process(ll a){
    ans = 0;
    if (a < 1){//this comes from a quirkiness in the code, this is a fix.
        ans = a+1;
        return;
    }
    if (a < 11){
        ans = a;
        return;
    }
    int len = (int)to_string(a).length();
    
    for (int i = 1; i < len; i++){//building up from 1 to 100, 1000, the "base"
        ans += base[i];
    }

    int nums [len];
    ll aCopy = a;
    for (int i = len-1; i >= 0; i--){//creating an array of the integer
        nums[i] = aCopy % 10;
        aCopy /= 10;
    }
    
    for (int i = 0; i < len; i++){
        bool be4 = false;
        if (i > 0 && nums[i] > nums[i-1]) be4 = true;//if for example *23*0
        else if (i > 0 && nums[i] > 0 && nums[i] == nums[i-1]){//if for example 555 --> 549 as last possible
            nums[i]--;
            for (int j = i+1; j < len; j++){
                nums[j] = 9;
            }
        }

        if (i == 0) nums[0]--; //reduce to compensate for the "build up" above
        count(nums[i], len-1-i, be4);
        if (i == 0) nums[0]++; //undo reduce to get correct comparisons
    }

}
 
int main(){
    base[0] = 1;
    for (int i = 1; i < 19; i++){
        base[i] = base[i-1] *9;
    }
    ll a,b;
    ll ansA, ansB;
    cin >> a;
    cin >> b;
    if (a==b && a==0) {
        cout << 1;
        return 0;
    }
    process(b);
    ansB = ans;
    process(a-1);
    ansA = ans;
    cout << ansB-ansA;
}
