#include <iostream>
#include <algorithm>
using namespace std;
const int NUM_BUCKETS = 51;
int buckets[NUM_BUCKETS];

bool find_num(int cap, int B)
{
    bool found = false;
    int l = 0, r = B - 1, mid = 0;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (buckets[mid] < cap)
            l = mid + 1;
        else if (buckets[mid] > cap)
            r = mid - 1;
        else if (buckets[mid] == cap) {
            found = true;
            break;
        }
    }
    return found;
}

bool PossibleToFill(int idx, int capacity, int B)
{
    bool pos = false;
    bool found_rest = false;
    int n = capacity;
    cout << "Debug: " << capacity  << " idx= " << idx << endl;
    for (int i = idx; i < B; ++i) {
        cout << "Debug: " << " bucket= " << buckets[i] << " i = " << i << " n = " << n << " capacity= " << capacity << endl;
        if (n == 0) {
            cout << "Debug: " << " n = " << n << " possible= " << true << endl;
            pos = true;
            break;
        }
        if (buckets[i] <= n) {
            cout << "Debug: " << " n= " << n << " buckets[" << i << "]=" << buckets[i] << endl;
            n %= buckets[i];
            cout << "Debug: " << " reduced n= " << n << endl;
            found_rest = find_num(n, B);
            if (found_rest) {
                pos = true;
                break;
            }
            else {
                pos = PossibleToFill(idx + 1, capacity, B);
                if (pos == true) {
                    break;
                }
            }
        }
        else {
            pos = false;
            break;
        }
    }
    return pos;
}


int main()
{
    int B = 0, Q = 0, capacity = 0;
    bool pos = false;
    cin >> B >> Q;
    for (int i = 0; i < B; ++i) {
        cin >> buckets[i];
    }
    
    sort (buckets, buckets + B);

    for (int i = 0; i < Q; ++i) {
        cin >> capacity;
        pos = PossibleToFill(0, capacity, B);
        if (pos == true)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    
    return 0;
}
