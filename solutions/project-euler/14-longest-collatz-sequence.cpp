#include <iostream>
#include <map>
#include <stack>
using namespace std;

const int MAX = 5000002;
typedef unsigned long long int ulli;

ulli collatz[5*MAX];
ulli col_stack[MAX];
int idx;

void set_collatz_cycle(int n) 
{
    ulli cycle = 0;
    col_stack[idx++] = n;
    int t = 0;
    while (idx != 0) {
        t = col_stack[--idx];
        cout << "debug: " << "set collatz cycle: " << "index= " << idx << " top of stack= " << t << " collatz[" << t << "]= " << collatz[t] << endl;
        cout << "debug: about to enter if\n";
        if (collatz[t] != 0) {
            cycle = collatz[t];
            while (idx != 0) {
                collatz[col_stack[--idx]] = ++cycle;
            }
            break;
        }
        else {
            cout << "debug: inside else " << idx << endl;
            col_stack[idx++] = t;
            cout << "col_stack val= " << col_stack[idx-1] << endl;
            if (t % 2 == 0) {
                t /= 2;
            }
            else {
                t *= 3;
                t += 1;
            }
            col_stack[idx++] = t;
            cout << "debug: col stack val after calc= " << col_stack[idx-1] << endl;
            cout << "debug: exiting else\n";
        }
    }
}

void init_collatz_values(int MAX) {
    collatz[0] = 0;
    collatz[1] = 1;
    for (int i = 2; i < 250000; ++i) {
        set_collatz_cycle(i);
        cout << i << "\t" << collatz[i] << endl;
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

    cout << collatz[27114424] << endl;
    init_collatz_values(MAX);

    while(T--) {
        cin >> N;
        cout << get_max_collatz_cycle(N) << endl;
    }
    
    return 0;
}
