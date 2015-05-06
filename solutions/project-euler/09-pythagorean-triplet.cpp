#include <iostream>
using namespace std;

int main()
{
    unsigned int T = 0, N = 0;
    unsigned int best_a = 0, a, best_b = 0, b, best_c = 0, c;
    unsigned int prod = 0, best_prod = 0;
    cin >> T;
    while (T--) {
        cin >> N;
        //cout << "debug: " << " N= " << N << endl;
        best_prod = 0;
        for (a = 2; a < N; ++a) {
            for (b = a + 1; b < N; ++b) {
                c = N - a - b;
                if (a*a + b*b == c*c) {
                    prod = a*b*c;
                    if (prod > best_prod) {
                        best_prod = prod;
                        best_a = a;
                        best_b = b;
                        best_c = c;
                    }
                }
            }
        }
        //a = best_a;
        //b = best_b;
        //c = best_c;
        //cout << "a = " << a << " b= " << b << " c= " << c << " a+b+c=" << (a+b+c)<< " N= " << N << " a*b*c= " << a*b*c << endl; 
        if (best_prod > 0)
            cout << best_prod << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
