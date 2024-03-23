#include <iostream>
using namespace std;

void printBoard(char arr[3][3]) {
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      cout << " " << arr[i][j];
      if (j<2) {
        cout << " |";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
}

void chance(bool xturn, char arr[3][3], int pos) {
  int i;
  int j;

  i = pos/10;
  j = pos%10;
  if (arr[i-1][j-1] == ' ') {
    if (xturn) {
      arr[i-1][j-1] = 'x';
    } else {
      arr[i-1][j-1] = 'o';
    }
  }
}

char checkWinner(char arr[3][3]) {
  // no one -> n
  // x -> x
  // o -> o

  // line check
  for (int i=0; i<3; i++) {
    // row
    if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] == arr[i][2] && arr[i][0] != ' ' && arr[i][1] != ' ' && arr[i][2] != ' ') {
      return arr[i][0];
    }
    // coll
    if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] == arr[2][i] && arr[0][i] != ' ' && arr[1][i] != ' ' && arr[2][i] != ' ') {
      return arr[0][i];
    }
  }

  // cross check
  if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] == arr[2][2] && arr[0][0] != ' ' && arr[1][1] != ' ' && arr[2][2] != ' ') {
    return arr[0][0];
  }
  if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] == arr[2][0]  && arr[0][2] != ' ' && arr[1][1] != ' ' && arr[2][0] != ' ') {
    return arr[0][2];
  }

  return 'n';
}

char board[3][3] = {
  {' ', ' ', ' '},
  {' ', ' ', ' '},
  {' ', ' ', ' '}
};

int main() {
  cout << "################################" << endl;
  cout << "Welcome to C++ tic-tac-toe game!" << endl;
  cout << "################################" << endl;
  cout << endl;

  bool game = true; //game loop
  bool xturn = true;
  while (game) {
    int pos;
    if (xturn) {
      cout << " >>> Enter position for x ";
    } else {
      cout << " >>> Enter position for o ";
    }
    cin >> pos;
    chance(xturn, board, pos);
    cout << endl;
    printBoard(board);
    cout << endl;
    xturn = !xturn;
    if (checkWinner(board) != 'n') {
      game = false;
      cout << "!!! Winner is " << checkWinner(board) << " !!!" << endl;
    }
  }

  return 0;
}
