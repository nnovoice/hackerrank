#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX = 70001;
int trinums[MAX];
int nfactors[MAX];

void gen_trinums()
{
    int num = 0;
    for (int i = 1; i <= MAX; ++i) {
        trinums[i] = trinums[i-1] + i;
        //cout << i << " " << trinums[i] << endl;
    }
}

void gen_nfactors()
{
    int i = 0, j = 0, n = 0, max_divisor = 0, last_divisor = 0;
    nfactors[1] = 1;
    for (i = 2; i < MAX; ++i) {
        //cout << "trinum= " << trinums[i] << " divisors= ";
        n = 0;
        max_divisor = trinums[i] / 2;
        last_divisor = max_divisor;
        for (j = 2; j <= max_divisor && j < last_divisor; ++j) {
            if (trinums[i] % j == 0) {
                last_divisor = trinums[i] / j; 
                n += 2;
                //cout << j << " " << last_divisor << " ";
            }
        }
        n += 2;
        nfactors[i] = n;
        //cout << endl;
    }

    for (int i = 1; i < MAX; ++i) {
        //cout << "num= " << trinums[i] << " nfactors= " << nfactors[i] << endl;
        printf("trinums[%d]=%d nfactors=%d\n", i, trinums[i], nfactors[i]);
    }

}

int main()
{
    gen_trinums();
    gen_nfactors();
    return 0;
}
