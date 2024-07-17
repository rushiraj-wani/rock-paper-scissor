#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

char playerSelect() {
  char choice;
  cout << "Enter R/P/S (Rock/Paper/Scissor): ";
  cin >> choice;
  return toupper(choice);
}

char machineSelect() {
  srand(time(0));
  int randomNum = rand() % 3;

  switch (randomNum) {
  case 0:
    return 'R';
  case 1:
    return 'P';
  default:
    return 'S';
  }
}

int determineWinner(char playerChoice, char computerChoice) {
  if (playerChoice == computerChoice) {
    return 0;
  } else if ((playerChoice == 'R' && computerChoice == 'S') ||
             (playerChoice == 'P' && computerChoice == 'R') ||
             (playerChoice == 'S' && computerChoice == 'P')) {
    return 1;
  } else {
    return -1;
  }
}

int main() {
  char playerChoice, computerChoice;
  char playAgain = 'y';

  do {
    playerChoice = playerSelect();
    computerChoice = machineSelect();

    int result = determineWinner(playerChoice, computerChoice);

    if (result == 0) {
      cout << "It's a tie!" << endl;
    } else if (result == 1) {
      cout << "You win!" << endl;
    } else {
      cout << "You lose!" << endl;
    }

    cout << "User chose: " << playerChoice << endl;
    cout << "Computer chose: " << computerChoice << endl;

    cout << "Play again? (y/n): ";
    cin >> playAgain;
  } while (tolower(playAgain) == 'y');

  cout << "Thanks for playing!" << endl;

  return 0;
}