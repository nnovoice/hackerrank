#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int sum_to_n(int n) {
        //cout << "debug: " << n << " " << (n * (n + 1))/2 << endl;
        return (n * (n + 1)) / 2;
}

int main() {
        int T = 0, N = 0;
        int sum = 0;
        cin >> T;
        while (T--) {
            cin >> N;
            --N;
            sum = sum_to_n(N/3)*3 + sum_to_n(N/5)*5 - sum_to_n(N/15)*15;
            cout << sum << endl;
        }
        return 0;
}

