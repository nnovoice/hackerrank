#include <iostream>
using namespace std;

typedef unsigned long long int ulli;

const int MAX = 507;
ulli tri[MAX][MAX];

void gen_pascal_triangle()
{
    tri[1][0] = 0;
    tri[1][1] = 1;
    cout << "1: " << tri[1][1] << endl;
    for (int i = 2; i < MAX; ++i) {
        cout << i << ": ";
        for (int j = 1; j < MAX; ++j) {
            tri[i][j] = tri[i-1][j] + tri[i-1][j-1];
            if (tri[i][j] == 0)
                break;
            cout << tri[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    gen_pascal_triangle();

    int T = 0, N = 0, M = 0;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        cout << tri[N*M+1][M+1] << endl;
    }
}
