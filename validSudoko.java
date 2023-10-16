public class ValidSudoku {
    public boolean isValidSudoku(char[][] board) {
        // Create sets to keep track of digits in rows, columns, and 3x3 sub-grids.
        Set<Character>[] rowSet = new HashSet[9];
        Set<Character>[] colSet = new HashSet[9];
        Set<Character>[] subgridSet = new HashSet[9];

        for (int i = 0; i < 9; i++) {
            rowSet[i] = new HashSet<>();
            colSet[i] = new HashSet<>();
            subgridSet[i] = new HashSet<>();
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char digit = board[i][j];
                if (digit == '.')
                    continue;

                if (rowSet[i].contains(digit) || colSet[j].contains(digit) || subgridSet[3 * (i / 3) + (j / 3)].contains(digit)) {
                    return false;
                }

                rowSet[i].add(digit);
                colSet[j].add(digit);
                subgridSet[3 * (i / 3) + (j / 3)].add(digit);
            }
        }

        return true;
    }

    public static void main(String[] args) {
        ValidSudoku validSudoku = new ValidSudoku();
        char[][] board = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.1','9','5','.','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
        };
        boolean result = validSudoku.isValidSudoku(board);
        System.out.println("Is the Sudoku board valid? " + result);
    }
}
