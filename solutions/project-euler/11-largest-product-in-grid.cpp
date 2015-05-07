#include <iostream>
#include <algorithm>
//#include <climits>
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
    //cout << INT_MAX << endl;
    //cout << 100000000 - INT_MAX << endl;
    int grid[MAX][MAX];
    int prod = 0, best = 0, l, r, u, d;
    int diag_right_up, diag_right_bot, diag_left_up, diag_left_bot;
    // memset does not work to set the cells to 1 because it sets that to every byte!
    //memset(grid, 0, sizeof(grid[0][0]) * MAX * MAX);
    init_grid(grid);
    for (int i = 3; i < 23; ++i) {
        for (int j = 3; j < 23; ++j) {
            cin >> grid[i][j];
            //cout << grid[i][j] << " ";
        }
        //cout << endl;
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
            diag_right_bot = grid[i][j] * grid[i+1][j+1] * grid[i+2][j+2] * grid[i+3][j+3];
            //cout << " diag= " << diag << endl;
            best = max(best, diag_right_bot);


            diag_right_up = grid[i][j] * grid[i-1][j+1] * grid[i-2][j+2] * grid[i-3][j+3];
            best = max(best, diag_right_up);


            diag_left_bot = grid[i][j] * grid[i+1][j-1] * grid[i+2][j-2] * grid[i+3][j-3];
            best = max(best, diag_left_bot);


            diag_left_up = grid[i][j] * grid[i-1][j-1] * grid[i-2][j-2] * grid[i-3][j-3];
            best = max(best, diag_left_up);

        }
    }
    cout << best << endl;

    return 0;
}
