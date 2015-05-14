#include <iostream>
using namespace std;

const int MAX = 5000002;
typedef unsigned long long int ulli;

ulli collatz[MAX];
ulli col_stack[MAX];
int idx;

void set_collatz_cycle(int n) {
    ulli t = 0, cycle = 0;
    idx = 0;
    col_stack[idx++] = n;
    while (collatz[n] == 0) {
        t = col_stack[--idx];
        if (t < MAX && collatz[t] != 0) {
            cycle = collatz[t];
            while (idx > 0) {
                t = col_stack[--idx];
                cycle += 1;
                if (t < MAX)
                    collatz[t] = cycle;
            }
        }
        else {
            col_stack[idx++] = t;
            if (t & 1) { 
                t *= 3;
                t += 1;
            }
            else
                t >>= 1;

            col_stack[idx++] = t;
        }
    }
    //cout << "found collatz[" << n << "]= " << collatz[n] << endl;
}

void init_collatz_values(int MAX) {
    collatz[0] = 0;
    collatz[1] = 1;
    for (int i = 2; i < MAX; ++i) {
        set_collatz_cycle(i);
        //cout << i << "\t" << collatz[i] << endl;
    }
}

ulli get_max_collatz_cycle(int N) {
    ulli max = 0;
    int num = 0;
    for (int i = N; i > 0; --i) {
        if (collatz[i] > max) {
            max = collatz[i];
            num = i;
        }
    }
    return num;
}

int main()
{
    int T = 0, N = 0;
    cin >> T;

    init_collatz_values(MAX);

    while(T--) {
        cin >> N;
        cout << get_max_collatz_cycle(N) << endl;
    }
    
    return 0;
}
