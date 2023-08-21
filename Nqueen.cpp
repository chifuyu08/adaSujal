#include <iostream>
 #include <vector>
 using namespace std;
 
 bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
 for (int i = 0; i < row; ++i) {
 if (board[i][col] == 1) {
 return false;
 }
 }
 for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
 if (board[i][j] == 1) {
 return false;
 }
 }
 for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
 if (board[i][j] == 1) {
 return false;
 }
 }
 return true;
 }
 bool solve(vector<vector<int>>&board, int row, int N) {
 if (row == N) {
 for (int i = 0; i < N; ++i) {
 for (int j = 0; j < N; ++j) {
 cout << board[i][j] << " ";
 }
 cout << endl;
 }
 cout << endl;
 cout<< endl;
 return true;
 }
 bool res = false;
 for (int col = 0; col < N; ++col) {
 if (isSafe(board, row, col, N)) {
 board[row][col] = 1;
 res = solve( board, row + 1, N) || res;
 board[row][col] = 0; 
 }
 }
 return res;
 }
 int main() {
 int n;
 cout << "Enter the number of queens: "<<endl;
 cin >> n;
 vector<vector<int>> board(n, vector<int>(n, 0));
 solve(board,0,n);
 return 0;
}
