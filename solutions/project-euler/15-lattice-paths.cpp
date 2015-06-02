#include <iostream>
using namespace std;

typedef unsigned long long int ulli;

const int MAX = 1007;
ulli tri[MAX][MAX];

void gen_pascal_triangle()
{
    tri[1][0] = 0;
    tri[1][1] = 1;
    for (int i = 2; i < MAX; ++i) {
        for (int j = 1; j < MAX; ++j) {
            tri[i][j] = tri[i-1][j] + tri[i-1][j-1];
            if (tri[i][j] == 0)
                break;
        }
    }
}

void move_triangle_to_square()
{
    int i = 1, j = 1, k = 1;
    
    for (; i < MAX; ++i) {
        k = 1;
        for (j = 1; j < MAX; ++j)
            if (tri[j][i] == 0)
                continue;
            else 
                break;

        for (; j < MAX; ++j, ++k) {
            tri[k][i] = tri[j][i];                
        }
    }
}

void print_tri() {
    for (int i = 1; i < MAX; ++i) {
        for (int j = 1; j < MAX; ++j) {
            cout << tri[i][j] << " ";
        }
        cout << endl;
    }

}

int main()
{
    gen_pascal_triangle();
    move_triangle_to_square();
    //print_tri();

    int T = 0, N = 0, M = 0;
    cin >> T;
    cout << "cases= " << T << endl;
    while (T--) {
        cin >> N >> M;
        if (N == 1 || M == 1)
            cout << tri[N][M] << endl;
        else
            cout << tri[N+1][M+1] << endl;
    }
    return 0;
}
