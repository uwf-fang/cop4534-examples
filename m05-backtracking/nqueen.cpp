#include <iostream>
#include <stack>
#include <vector>

class NQueens {
 private:
  int N;
  // One dimensional vector to represent the board
  // board[i] = j means there is a queen at (i, j)
  std::vector<int> board;
  std::vector<std::vector<int> > solutions;

  bool isSafe(const std::vector<int>& board, int row, int col) {
    for (int i = 0; i < col; i++) {
      if (board[i] == row || board[i] - i == row - col ||
          board[i] + i == row + col) {
        return false;
      }
    }
    return true;
  }

  // The main recursive function to generate solutions
  // No explicit backtracking operation here, simply proceed to the next option
  void solveNQueensRecursiveHelper(std::vector<int>& board, int col) {
    if (col == N) {
      solutions.push_back(board);
      return;
    }

    // iterate over all rows in the current column
    for (int i = 0; i < N; i++) {
      if (isSafe(board, i, col)) {
        board[col] = i;
        solveNQueensRecursiveHelper(board, col + 1);
      }
    }
  }

 public:
  NQueens(int n) : N(n), board(n, -1) {}

  void reset() {
    board.assign(N, -1);
    solutions.clear();
  }

  void solveRecursive() { solveNQueensRecursiveHelper(board, 0); }
  void solveIterative() {
    std::stack<int> stack;
    int col = 0;

    while (col >= 0) {
      bool found = false;

      for (int row = board[col] + 1; row < N; row++) {
        if (isSafe(board, row, col)) {
          board[col] = row;
          if (col == N - 1) {
            solutions.push_back(board);
            board[col] = -1;  // Reset the current column and backtrack
            col--;
          } else {
            col++;
          }
          found = true;
          break;
        }
      }

      if (!found) {
        board[col] = -1;  // Reset the current column
        col--;            // Backtrack to the previous column
      }
    }
  }

  void printSolutions() {
    for (const auto& solution : solutions) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          if (solution[j] == i) {
            std::cout << "Q ";
          } else {
            std::cout << ". ";
          }
        }
        std::cout << "\n";
      }
      std::cout << "\n";
    }
  }
};

int main() {
  int N = 4;  // Change this value for different sizes
  NQueens nq(N);
  std::cout << "Recursive solution:\n";
  nq.solveRecursive();
  nq.printSolutions();
  std::cout << "Iterative solution:\n";
  nq.reset();
  nq.solveIterative();
  nq.printSolutions();

  return 0;
}
