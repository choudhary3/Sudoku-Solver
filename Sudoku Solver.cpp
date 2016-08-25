#include <iostream>
using namespace std;

// Prints the sudoku
void print(int a[9][9]){
    cout << endl;
    for(int i = 0; i < 9; i++){
        if(i == 3 || i == 6){
            cout << "---------------------" << endl;
        }
        for(int j = 0; j < 9; j++){
            if(j == 3 || j == 6){
                cout << "| ";
            }
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Checks if the number is occuring in row, column or box
bool check(int a[9][9], int row, int col, int val){
    for(int k = 0; k < 9; k++){
        if(a[row][k] == val){
            return false;
        }
    }
    for(int k = 0; k < 9; k++){
        if(a[k][col] == val){
            return false;
        }
    }
    for(int x = row - row%3; x < row - row%3 + 3; x++){
        for(int y = col - col%3; y < col - col%3 + 3; y++){
            if(a[x][y] == val){
                return false;
            }
        }
    }
    return true;
}

void solve(int a[9][9]){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(a[i][j] == 0){
                for(int k = 1; k < 10; k++){
                    if(check(a,i,j,k)){
                        a[i][j] = k;
                        solve(a);
                    }
                    if(k == 9){
                        a[i][j] = 0;
                        return;
                    }
                }
            }
        }
    }
    print(a);
}

int main()
{
//    int a[9][9] = { {0,0,6,0,5,4,9,0,0},
//                    {1,0,0,0,6,0,0,4,2},
//                    {7,0,0,0,8,9,0,0,0},
//                    {0,7,0,0,0,5,0,8,1},
//                    {0,5,0,3,4,0,6,0,0},
//                    {4,0,2,0,0,0,0,0,0},
//                    {0,3,4,0,0,0,1,0,0},
//                    {9,0,0,8,0,0,0,5,0},
//                    {0,0,0,4,0,0,3,0,7}};
    int a[9][9] = { {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0}};
//    solve(a);

    // Takes input from the user
    // For blank box takes input as 0
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> a[i][j];
        }
    }
    solve(a);
    return 0;
}
