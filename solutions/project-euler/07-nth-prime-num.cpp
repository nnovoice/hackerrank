#include <iostream>
#include <string.h>
using namespace std;

const int MAX = 1000001;
bool prime_slots[MAX];
int primes[MAX];
int nprimes;

void gen_primes() {
    memset(prime_slots, true, sizeof(prime_slots[0]) * MAX);
    memset(primes, 0, sizeof(primes[0]) * MAX);
    primes[0] = primes[1] = false;
    int idx = 0;
    for (int i = 2; i < MAX; ++i) {
        if (prime_slots[i] == true) {
            primes[idx++] = i;
            for (int j = 2; j*i < MAX; ++j)
                prime_slots[i*j] = false;

        }
    }
    nprimes = idx;
}

int main()
{
    long long int T = 0, N = 0;
    cin >> T;
    gen_primes();
    //cout << "num primes = " << nprimes << endl;
    //for (int i = 0; i < nprimes; ++i) {
    //    cout << "i= " << i << " " << primes[i] << endl;
    //}
    while (T--) {
        cin >> N;
        //cout << "debug: " << "input= " << N << endl;
        cout << primes[N-1] << endl;
    }
    return 0;
}
