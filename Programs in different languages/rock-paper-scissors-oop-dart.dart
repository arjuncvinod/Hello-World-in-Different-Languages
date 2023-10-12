import 'dart:math';
import 'dart:io';

// Make rock paper scissors with applying OOP in Dart

abstract class ParentClass {
  late int _yourPoint;
  late int _enemyPoint;
  int _numberOfRound = 1;

  final random = new Random();

  void setYourPoint();
  void setEnemyPoint();
  void setNumberOfRound();
  void resetGameStat();

  int getYourPoint();
  int getEnemyPoint();
  int getNumberOfRound();
  int countRoundofPlay();
  
  int theWinner(String yourChoice, enemyChoice);
  String yourAnswer(int hideOrShowInput);
  String enemyAnswer();

  int validateChoice();
  int playAgain();
  
}

class SubClass extends ParentClass {
  int _yourPoint = 0;
  int _enemyPoint = 0;
  int _numberOfRound = 1;

  @override
  int theWinner(String yourChoice, enemyChoice) {
    // if user/player one win then it would return 0, if bot/player two win then it would return 1, if draw then it would return 2
    int Winner;

    if (yourChoice.toLowerCase() == "scissors" && enemyChoice == "paper") {
      Winner = 0;
    } else if (enemyChoice == "scissors" && yourChoice.toLowerCase() == "paper") {
      Winner = 1;
    } else if (yourChoice.toLowerCase() == "scissors" && enemyChoice == "rock") {
      Winner = 1;
    } else if (enemyChoice == "scissors" && yourChoice.toLowerCase() == "rock") {
      Winner = 0;
    } else if (yourChoice.toLowerCase() == "paper" && enemyChoice == "rock") {
      Winner = 0;   
    } else if (enemyChoice == "paper" && yourChoice.toLowerCase() == "rock") {
      Winner = 1;
    } else {
      Winner = 2;
    }
    return Winner;
  }

  @override
  String yourAnswer(int hideOrShowInput) {
    // if one then hide the input from user in command line
    if (hideOrShowInput == 1) {
      stdin.echoMode = false;
    }

    print('Enter your choice (Scissors/Paper/Rock) : ');
    while (true) {
      String yourChoice = stdin.readLineSync()!;
      if (yourChoice.toLowerCase() == "scissors" || yourChoice.toLowerCase() == "paper" || yourChoice.toLowerCase() == "rock") {
        stdin.echoMode = true;        
        return yourChoice;
      } else {
        print('The choice you entered is incorrect, please try again!');
      }
    }
    
  }

  @override
  String enemyAnswer() {
    var enemyAnswer = <String>["scissors", "paper", "rock"];
    int enemyRandom = random.nextInt(enemyAnswer.length);
    String enemyChoice = enemyAnswer[enemyRandom];
    return enemyChoice;
  }

  @override
  void setYourPoint() {
    _yourPoint++;
  }

  @override
  void setEnemyPoint() {
    _enemyPoint++;
  }

  @override
  void setNumberOfRound() {
    _numberOfRound++;
  }

  @override
  void resetGameStat() {
    _yourPoint = 0;
    _enemyPoint = 0;
    _numberOfRound = 1;
  }

  @override
  int getYourPoint() {
    return _yourPoint;
  }

  @override
  int getEnemyPoint() {
    return _enemyPoint;
  }

  @override
  int getNumberOfRound() {
    return _numberOfRound;
  }

  @override
  int countRoundofPlay() {
    print("\nHow many rounds do you want to play? (only odd numbers like 1/3/5/etc) : ");
    while(true) {
      String totalRound = stdin.readLineSync()!;
      
      try {
        if (totalRound != null && int.parse(totalRound) >= 0 && int.parse(totalRound) % 2 != 0) {
          return int.parse(totalRound);
        } else {
          print('The choice you entered is incorrect, please try again!');
        }
      } catch (e) {
        print('The choice you entered is incorrect, please try again!');
      }
    }
  }

  @override
  int validateChoice() {
    print("Enter your choice : ");
    while(true) {
      String selectTheMenu = stdin.readLineSync()!;

      if (int.tryParse(selectTheMenu) == 1) {
        return int.parse(selectTheMenu);
      } else if (int.tryParse(selectTheMenu) == 2) {
        return int.parse(selectTheMenu);
      } else if (int.tryParse(selectTheMenu) == 3) {
        return int.parse(selectTheMenu);
      } else {
        print('The choice you entered is incorrect, please try again!');
      }
    }
  }

  @override
  int playAgain() {
    print("Do you want to play again? Yes/No : ");
    while(true) {
      String playAnymore = stdin.readLineSync()!;
      
      // return 1 if the player want to play again, return 0 if the player won't play again
      if (playAnymore.toLowerCase() == "yes") {
        return 1;
      } else if (playAnymore.toLowerCase() == "no") {
        return 0;
      } else {
        print('The choice you entered is incorrect, please try again!');
      }
    }
  }

}

class PlayingTheGame extends SubClass {
  var accessSubClass = new SubClass();

  PlayingTheGame (int playingWith) {
    if (playingWith == 1) {
      int roundOfPlay = accessSubClass.countRoundofPlay();
      print("\nThe winner will be determined from the winners in ${roundOfPlay} rounds (can be less and doesn't count if it's a draw)\nGame Started.......");
      
      while (true) {
        print("\nRound ${accessSubClass.getNumberOfRound()}");
        String yourChoice = accessSubClass.yourAnswer(0);
        String enemyChoice = accessSubClass.enemyAnswer();
        int theResult = accessSubClass.theWinner(yourChoice, enemyChoice);

        if (theResult == 0) {
          accessSubClass.setYourPoint();
          print('Congratulations you won round of ${accessSubClass.getNumberOfRound()} because the enemy chose ${enemyChoice}!');
        } else if (theResult == 1) {
          accessSubClass.setEnemyPoint();
          print('Well, you have to lose in round of ${accessSubClass.getNumberOfRound()} because the enemy chose ${enemyChoice}!');
        } else if (theResult == 2) {
          print("You're tied in round of ${accessSubClass._numberOfRound} because you chose ${yourChoice} and the enemy chose ${enemyChoice}!");
        }

        print("Points Acquisition\nYour Point : ${accessSubClass.getYourPoint()}\nEnemy Point : ${accessSubClass.getEnemyPoint()}");
        accessSubClass.setNumberOfRound();

        if (accessSubClass.getYourPoint() >= (roundOfPlay / 2)) {
          print('\nCongratulations you won the match with a score ${accessSubClass.getYourPoint()} - ${accessSubClass.getEnemyPoint()}!\n');
          int playAgain = accessSubClass.playAgain();
          if (playAgain == 0) {
            break;
          } else {
            roundOfPlay = accessSubClass.countRoundofPlay();
            accessSubClass.resetGameStat();
          }
        } else if (accessSubClass.getEnemyPoint() >= (roundOfPlay / 2)) {
          print('\nWell you have to lose with a score ${accessSubClass.getYourPoint()} - ${accessSubClass.getEnemyPoint()}!\n');
          int playAgain = accessSubClass.playAgain();
          if (playAgain == 0) {
            break;
          } else {
            roundOfPlay = accessSubClass.countRoundofPlay();
            accessSubClass.resetGameStat();
          }
        }
      }

    } else if (playingWith == 2 ) {
      int roundOfPlay = accessSubClass.countRoundofPlay();
      print("\nThe winner will be determined from the winners in ${roundOfPlay} rounds (can be less and doesn't count if it's a draw)\nGame Started.......");
      while (true) {
        print("\nRound ${accessSubClass.getNumberOfRound()}");
        print('\nPlayer One Start');
        String playerOneChoice = accessSubClass.yourAnswer(1);
        print('\nPlayer Two Start');
        String playerTwoChoice = accessSubClass.yourAnswer(1);
        int theResult = accessSubClass.theWinner(playerOneChoice, playerTwoChoice);
        
        // Your Point = Player One | Enemy Point = Player Two
        if (theResult == 0) {
          accessSubClass.setYourPoint();
          print('\nCongratulations player one won round of ${accessSubClass.getNumberOfRound()} because player one answer is ${playerOneChoice} and player two answer is ${playerTwoChoice}!');
        } else if (theResult == 1) {
          accessSubClass.setEnemyPoint();
          print('\nCongratulations player two won round of ${accessSubClass.getNumberOfRound()} because player one answer is ${playerOneChoice} and player two answer is ${playerTwoChoice}!');
        } else if (theResult == 2) {
          print("\nYou're tied in round of ${accessSubClass._numberOfRound} because player one chose ${playerOneChoice} and player two chose ${playerTwoChoice}!");
        }

        print("Points Acquisition\nPlayer One Point : ${accessSubClass.getYourPoint()}\nPlayer Two Point : ${accessSubClass.getEnemyPoint()}");
        accessSubClass.setNumberOfRound();

        if (accessSubClass.getYourPoint() >= (roundOfPlay / 2)) {
          print('\nCongratulations player one won the match with a score ${accessSubClass.getYourPoint()} - ${accessSubClass.getEnemyPoint()}!\n');
          int playAgain = accessSubClass.playAgain();
          if (playAgain == 0) {
            break;
          } else {
            roundOfPlay = accessSubClass.countRoundofPlay();
            accessSubClass.resetGameStat();
          }
        } else if (accessSubClass.getEnemyPoint() >= (roundOfPlay / 2)) {
          print('\nCongratulations player two won the match with a score ${accessSubClass.getYourPoint()} - ${accessSubClass.getEnemyPoint()}!\n');
          int playAgain = accessSubClass.playAgain();
          if (playAgain == 0) {
            break;
          } else {
            roundOfPlay = accessSubClass.countRoundofPlay();
            accessSubClass.resetGameStat();
          }
        }
      }
    }
  }
}

void main() {
  var accessSubClass = new SubClass();

  while (true) {

    print('\nWelcome to the rock paper scissors game');
    print('1. Playing with Bot/Computer\n2. Playing With Friend\n3. Exit From The Game');
    int yourChoice = accessSubClass.validateChoice();
    if (yourChoice == 3) {
      break;
    }

    var playWith = new PlayingTheGame(yourChoice);
    
  }
}
