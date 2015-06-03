#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100000 + 7;
long long arr[MAX];
int main()
{
    int T = 0, N = 0;
    cin >> T;
    long long mc = 0; // max contiguous
    long long nmc = 0; // max non contiguous
    long long cm = 0; // current max
    
    while (T--) {
        cin >> N;
        mc = LONG_LONG_MIN;
        cm = 0;
        nmc = LONG_LONG_MIN;
        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
            cm += arr[i];
            if (cm > mc) mc = cm;
            if (cm < 0) cm = 0;
            if (arr[i] > 0) {
                if (nmc < 0) nmc = 0;
                nmc += arr[i];
            }
        }
        if (nmc == LONG_LONG_MIN && mc < 0)
            nmc = mc;
        cout << mc << " " << nmc << endl;
    }
    return 0;
}

