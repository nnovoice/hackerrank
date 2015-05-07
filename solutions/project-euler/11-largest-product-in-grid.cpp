#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX = 26;

void init_grid(int grid[][MAX])
{   
    for (int k = 0; k < MAX; ++k) {
        for (int l = 0; l < MAX; ++l) {
            grid[k][l] = 1;
        }
    }
}

int main() 
{
    int grid[MAX][MAX];
    int prod = 0, best = 0, l, r, u, d, diag;
    // memset does not work!
    //memset(grid, 0, sizeof(grid[0][0]) * MAX * MAX);
    init_grid(grid);
    for (int i = 3; i < 23; ++i) {
        for (int j = 3; j < 23; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 3; i < 23; ++i) {
        for (int j = 3; j < 23; ++j) {
            //print_products(grid, i, j);
            // left 
            l = grid[i][j] * grid[i][j-1] * grid[i][j-2] * grid[i][j-3];
            //cout << "left = " << l;
            best = max(best, l);

            // right
            r = grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3];
            //cout << " right= " << r;
            best = max(best, r);

            // up
            u = grid[i][j] * grid[i-1][j] * grid[i-2][j] * grid[i-3][j];
            //cout << " up= " << u;
            best = max(best, u);

            // down
            d = grid[i][j] * grid[i+1][j] * grid[i+2][j] * grid[i+3][j];
            //cout << " down= " << d;
            best = max(best, d);

            // diag
            diag = grid[i][j] * grid[i+1][j+1] * grid[i+2][j+2] * grid[i+3][j+3];
            //cout << " diag= " << diag << endl;
            best = max(best, diag);
            //cout << "debug: " << " best so far: " << best << " " << i << " " << j << " " << grid[i][j] << endl;
        }
    }
    cout << best << endl;

    return 0;
}
