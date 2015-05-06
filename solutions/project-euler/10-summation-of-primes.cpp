#include <iostream>
#include <string.h>
using namespace std;

const int MAX = 1000001;
int primes[MAX];
int idx;
bool prime_slots[MAX];

void gen_primes() {
    memset(prime_slots, true, sizeof(prime_slots[0]) * MAX);
    prime_slots[0] = prime_slots[1] = false;
    for (int i = 2; i < MAX; ++i) {
        if (prime_slots[i] == true) {
            primes[idx++] = i;
            for (int j = i + i; j < MAX; j += i) {
                prime_slots[j] = false;
            }
        }
    }
    //for (int i = 0; i < idx; ++i) {
    //    cout << "i = " << i << " " << primes[i] << endl;
    //}
    //cout << "num primes= " << idx << " max prime= " << primes[idx-1] << endl;
}

int main()
{
    int t = 0, n = 0;
    unsigned long long int sum = 0;
    cin >> t;
    gen_primes();
    while (t--) {
        cin >> n;
        sum = 0;
        for (int i = 0; primes[i] <= n; ++i) {
            sum += primes[i];
        }
        cout << sum << endl;
    }
    return 0;
}
