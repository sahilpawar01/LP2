def is_safe(board, row, col, n):
    # Check same column
    for i in range(row):
        if board[i][col] == 1:
            return False

    # Check upper-left diagonal
    for i, j in zip(range(row-1, -1, -1), range(col-1, -1, -1)):
        if board[i][j] == 1:
            return False

    # Check upper-right diagonal
    for i, j in zip(range(row-1, -1, -1), range(col+1, n)):
        if board[i][j] == 1:
            return False

    return True

def solve_n_queens(board, row, n):
    if row == n:
        print_board(board, n)
        return True

    for col in range(n):
        if is_safe(board, row, col, n):
            board[row][col] = 1  # Place Queen
            if solve_n_queens(board, row + 1, n):
                return True
            board[row][col] = 0  # Backtrack

    return False

def print_board(board, n):
    for i in range(n):
        for j in range(n):
            print('Q' if board[i][j] else '.', end=' ')
        print()
    print()

# Example usage
n = 8
board = [[0 for _ in range(n)] for _ in range(n)]
if not solve_n_queens(board, 0, n):
    print("No solution exists.")
