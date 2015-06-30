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

    for (int i = N - 1, j = 1; i >= 0; --i, ++j) {
        if (h[i] < min_ht)
            min_ht = h[i];

        area = min_ht * j;
        if (area > best)
            best = area;
    }
    cout << best << endl;
    return 0;
}
