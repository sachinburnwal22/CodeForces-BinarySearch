#include<bits/stdc++.h>
using namespace std;

/**
 * BBBSSC
 * 3:2:1 -> ratio
 * 6 4 1 -> quantity
 * 1 2 3 -> prices
 * 4 rubles money he have
 */
int main(){
    string s;
    cin >> s;

    long long nb, ns, nc;
    cin >> nb >> ns >> nc;

    long long pb, ps, pc;
    cin >> pb >> ps >> pc;

    long long r;
    cin >> r;

    int rb = 0, rs = 0, rc = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'B'){
            rb += 1;
        }else if(s[i] == 'S'){
            rs += 1;
        }else{
            rc += 1;
        }
    }

    long long burgers = 0;
    long long low = 0;
    long long high = 1e13;

    while(low <= high){
        long long mid = (high + low)/2;

        long long needB = max(0LL, rb * mid - nb);
        long long needS = max(0LL, rs * mid - ns);
        long long needC = max(0LL, rc * mid - nc);

        long long cost = needB*pb + needS*ps + needC*pc;

        if(cost <= r){
            burgers = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    cout << burgers << endl;
    return 0;
}