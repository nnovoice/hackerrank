#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int NUM = 100000+7;

int main() {
    int h[NUM];
    int N = 0;
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> h[i];
    }

    unsigned long long area = 0, best = 0;
    int min_ht = INT_MAX;
    int l = 0, r = 0;
    for (int i = 0; i < N; ++i) {
        l = i - 1;
        r = i + 1;
        
        for (; l >= 0 && h[l] > h[i]; --l)
            ;
        l += 1;
        
        for (; r < N && h[r] > h[i]; ++r) 
            ;
        r -= 1;

        //if (l < 0) l = 0;
        //if (r >= N) r = N - 1;

        area = h[i] * (r - l + 1);
        if (area > best)
            best = area;
    }
    cout << best << endl;
    return 0;
}
