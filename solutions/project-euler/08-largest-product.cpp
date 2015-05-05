#include <iostream>
using namespace std;

int main()
{
    int T = 0,N = 0, K = 0;
    unsigned long long best_prod = 0, cur_prod = 0;
    cin >> T;
    char digits[1001];
    char c;
    while (T--) {
        cin >> N >> K;
        cin >> c;
        cin >> digits;
        cout << N << " " << K <<  " " << digits << endl;
        cur_prod = digits[0] - '0';
        best_prod = 0;
        for (int i = 1; i < N; ++i) {
            if ((i+1) % K == 0) {
                cout << "debug: " << "i = " << i << " K = " << K << " i/K= " << i/K << endl;
                if (cur_prod > best_prod) best_prod = cur_prod;
                cur_prod /= digits[i/K * K - 1];
            }
            cur_prod *= digits[i] - '0';
        }
        cout << best_prod << endl;

    }
    return 0;
}
