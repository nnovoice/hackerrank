#include <iostream>
#include <climits>
using namespace std;

const int MAX = 101;
const int NUM_VALS = 3;

int main()
{
    
    // Set Min[i] equal to Infinity for all of i
    int Min[MAX];
    int ways[MAX];
    for (int i = 0; i < MAX; ++i) {
        Min[i] = INT_MAX;
        ways[i] = 0;
    }

    int v[NUM_VALS] = {1, 3, 5};

    Min[0]=0;

    for (int i = 1; i < MAX; ++i) {
        for (int j = 0; j < NUM_VALS; ++j) {
            if (v[j] <= i && ((Min[i - v[j]] + 1) < Min[i]))
                Min[i] = Min[i-v[j]] + 1;
                ways[i] += 1;
        }

        cout << "For " << i << "\t #coins= "<< Min[i] << "\t#ways= " << ways[i] << endl;
    }
    return 0;
}
