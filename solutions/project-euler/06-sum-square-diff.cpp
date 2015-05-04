#include <iostream>
using namespace std;

int main()
{
    long long int T = 0, N = 0, sum_sq = 0, sum_n_sq = 0, sum_n = 0, diff = 0;
    cin >> T;
    while (T--) {
        cin >> N;
        sum_n = (N * (N + 1)) / 2;
        sum_sq = (N * (N + 1) * (2*N + 1)) / 6;
        sum_n_sq = sum_n * sum_n;
        diff = sum_n_sq - sum_sq;
        if (diff < 0) diff = 0 - diff;
        cout << diff << endl;

    }
    return 0;
}
