#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() : board(3, vector<char>(3, ' ')), currentPlayer('X') {}

    void displayBoard() const {
        cout << "  1 2 3" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << i + 1 << " ";
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) cout << "|";
            }
            cout << endl;
            if (i < 2) cout << "  -----" << endl;
        }
    }

    bool updateBoard(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ')
            return false;

        board[row][col] = currentPlayer;
        return true;
    }

    bool checkForWin() const {
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer))
                return true;
        }
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer))
            return true;

        return false;
    }

    bool checkForDraw() const {
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell == ' ')
                    return false;
            }
        }
        return true;
    }

    char switchPlayer() {
        return (currentPlayer == 'X') ? 'O' : 'X';
    }

    void play() {
        bool gameOn = true;
        while (gameOn) {
            displayBoard();
            cout << "Player " << currentPlayer << ", Enter your move (row and column): ";
            int row, col;
            cin >> row >> col;

            if (row < 1 || row > 3 || col < 1 || col > 3 || !updateBoard(row - 1, col - 1)) {
                cout << "Invalid move. Try again." << endl;
                continue;
            }

            if (checkForWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOn = playAgain();
            } else if (checkForDraw()) {
                displayBoard();
                cout << "It's a draw!" << endl;
                gameOn = playAgain();
            } else {
                currentPlayer = switchPlayer();
            }
        }

        cout << "Thanks for playing!" << endl;
    }

    bool playAgain() const {
        char choice;
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        return (choice == 'y' || choice == 'Y');
    }
};

int main() {
    TicTacToe game;
    game.play();

    return 0;
}
