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
    //for (int i = 0; i < idx; ++i)
    //    cout << primes[i] << endl;
}

long long int get_largest_prime_div(long long int N) {
    long long int largest_prime_div = -1;
    for (int i = 0; primes[i] < N && i < nprimes; ++i) {
        //cout << "debug: " << "testing N = " << N << " against prime= " << primes[i] << endl;
        if (N % primes[i] == 0)
            largest_prime_div = primes[i];
    }
    if (largest_prime_div == -1)
        return N;
    return largest_prime_div;
}


int main()
{
    long long int T = 0, N = 0;
    cin >> T;
    //cout << "debug: " << "#tests= " << T << endl;
    gen_primes();
    while (T--) {
        cin >> N;
        //cout << "debug: " << "input= " << N << endl;
        cout << get_largest_prime_div(N) << endl;
    }
    return 0;
}
