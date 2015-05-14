#include <stdio.h>
using namespace std;

const int MAX = 5000002;
typedef unsigned long long int ulli;

ulli collatz[MAX];
ulli col_stack[MAX];
ulli col_max[MAX];
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
}

void init_collatz_values(int MAX) {
    collatz[0] = 0;
    collatz[1] = 1;
    for (int i = 2; i < MAX; ++i) {
        set_collatz_cycle(i);
    }
}

void set_max_collatz_cycles() {
    col_max[0] = 0;
    col_max[1] = 1;

    ulli max = 0;
    int num = 0;
    for (int n = 1; n < MAX; ++n) {
        if (collatz[n] >= max) {
            max = collatz[n];
            num = n;
        }
        col_max[n] = num;
        //printf("%d\t %llu\n", n, col_max[n]);
    }
}

int main()
{
    int T = 0, N = 0;
    scanf("%d", &T);

    init_collatz_values(MAX);

    set_max_collatz_cycles();

    while(T--) {
        scanf("%d", &N);

        printf("%llu\n", col_max[N]);
    }
    
    return 0;
}
