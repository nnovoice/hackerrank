#include <iostream>
using namespace std;

int main()
{
    int T = 0, n = 0, k = 0;
    unsigned long long best_prod = 0, cur_prod = 0;
    cin >> T;
    char digits[1001];
    char c;
    while (T--) {
        cin >> n >> k;
        //cin >> c;
        cin >> digits;
        //cout << "n= " << n << " k= " << k <<  " digits= " << digits << endl;
        best_prod = 0;
        for (int i = 0; i <= n - k; ++i) {
            cur_prod = 1;
            for (int j = i; j < i + k; ++j) {
                cur_prod *= (digits[j] - '0');
            }
            if (cur_prod > best_prod) 
                best_prod = cur_prod;
            //cout << "i= " << i << " best = " << best_prod << endl;
        }
        cout << best_prod << endl;
    }
    return 0;
}
