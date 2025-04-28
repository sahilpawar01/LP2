#include <iostream>
#include <vector>

// Forward declaration of print_board function
void print_board(const std::vector<std::vector<int>>& board, int n);

bool is_safe(const std::vector<std::vector<int>>& board, int row, int col, int n) {
    // Check same column
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 1) {
            return false;
        }
    }
    
    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    
    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    
    return true;
}

bool solve_n_queens(std::vector<std::vector<int>>& board, int row, int n) {
    if (row == n) {
        print_board(board, n);
        return true;
    }
    
    for (int col = 0; col < n; ++col) {
        if (is_safe(board, row, col, n)) {
            board[row][col] = 1; // Place Queen
            if (solve_n_queens(board, row + 1, n)) {
                return true;
            }
            board[row][col] = 0; // Backtrack
        }
    }
    
    return false;
}

void print_board(const std::vector<std::vector<int>>& board, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << (board[i][j] ? 'Q' : '.') << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    int n = 8;
    std::vector<std::vector<int>> board(n, std::vector<int>(n, 0));
    
    if (!solve_n_queens(board, 0, n)) {
        std::cout << "No solution exists." << std::endl;
    }
    
    return 0;
}