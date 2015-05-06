#include <iostream>
using namespace std;

int main()
{
    int T = 0, N = 0;
    int best_a = 0, a, best_b = 0, b, best_c = 0, c;
    int prod = 0, best_prod = 0;
    cin >> T;
    while (T--) {
        cin >> N;
        best_prod = -1;
        for (int c = 1; c < N/2; ++c) {
            for (int b = 1; b < c; ++b) {
                a = N - b - c;
                if (a < 0) continue;
                if (a*a + b*b == c*c) {
                    prod = a*b*c;
                    if (prod > best_prod)
                        best_prod = prod;
                }
            }
        }
        cout << best_prod << endl;
    }
    return 0;
}
