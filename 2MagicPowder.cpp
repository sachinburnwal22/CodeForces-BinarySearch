#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> vec1(n), vec2(n);

    for(int i = 0; i < n; i++){
        cin >> vec1[i];
    }

    for(int i = 0; i < n; i++){
        cin >> vec2[i];
    }

    long long cookies = 0;
    long long low = 0, high = 1e9;

    while(low <= high){
        long long mid = (low + high) / 2;

        long long needed = 0;
        for(int i = 0; i < n; i++){
            long long req = mid * vec1[i];
            if(req > vec2[i]){
                needed += (req - vec2[i]);
                if(needed > k) break;
            }
        }

        if(needed <= k){
            cookies = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << cookies;
    return 0;
}
