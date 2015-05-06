#include <iostream>
using namespace std;

int main()
{
    unsigned int a = 0, b = 0, c = 0, N = 0;
    for (a = 1; a < 3000; ++a) {
        for (b = a + 1; b < 3000; ++b) {
            for (c =b+1; c < 3000; ++c) {
                if (a*a + b*b == c*c) {
                    N = a + b + c;
                    cout << a << " " << b << " " << c << " " << N << endl;
                }
            }
        }
    }
    return 0;
}
