#include <iostream>
#include <vector>

using namespace std;

bool checkForShips(bool gameFieldOne[10][10], bool gameFieldTwo[10][10]);

void shipPlace(bool gameFieldOne[10][10], bool gameFieldTwo[10][10], int x, int y, int a, int b, int playerNum) {
    if (playerNum == 1) {
        if (x == a) {
            if (y > b) {
                for (int j = y; j >= b; j--) {
                    gameFieldOne[x][j] = true;
                }
            }
            else if (y < b) {
                for (int j = y; j <= b; j++) {
                    gameFieldOne[x][j] = true;
                }
            }
        }
        if (y == b) {
            if (x > a) {
                for (int j = a; j <= x; j++) {
                    gameFieldOne[j][y] = true;
                }
            }
            else if (x < a) {
                for (int j = x; j <= a; j++) {
                    gameFieldOne[j][y] = true;
                }
            }
        }
    }  if (playerNum == 2) {
        if (x == a) {
            if (y > b) {
                for (int j = y; j >= b; j--) {
                    gameFieldTwo[x][j] = true;
                }
            }
            else if (y < b) {
                for (int j = y; j <= b; j++) {
                    gameFieldTwo[x][j] = true;
                }
            }
        }
        if (y == b) {
            if (x > a) {
                for (int j = a; j <= x; j++) {
                    gameFieldTwo[j][y] = true;
                }
            }
            else if (x < a) {
                for (int j = x; j <= a; j++) {
                    gameFieldTwo[j][y] = true;
                }
            }
        }
    }
}


//void wrapper(bool gameFieldOne[10][10], bool gameFieldTwo[10][10],int x,int y,int a,int b){
//}

void shipsPlacement(bool gameFieldOne[10][10], bool gameFieldTwo[10][10], int x, int y, int a, int b) {
    cout << "Player one, please input 2 coordinates for 4 little ships: " << endl;
    for (int i = 0; i < 2; i++) {
        bool correct = false;
        do {
            cin >> x >> y >> a >> b;
            if (x < 0 || y < 0 || a < 0 || b < 0 || x > 9 || y > 9 || a > 9 || b > 9) {
                cout << "Incorrect coordinates! Try again!" << endl;
            }
            else {
                if (!gameFieldOne[x][y] && !gameFieldOne[a][b])
                {
                    correct = true;
                    shipPlace(gameFieldOne, gameFieldTwo, x, y, a, b, 1);
                }
                else {
                    cout << "There is already a ship at the specified coordinates! Try again!" << endl;
                }
            }
        } while (!correct);
    }
    cout << "Player two, please input 2 coordinates for 4 little ships: " << endl;
    for (int i = 0; i < 2; i++) {
        bool correct = false;
        do {
            cin >> x >> y >> a >> b;
            if (x < 0 || y < 0 || a < 0 || b < 0 || x > 9 || y > 9 || a > 9 || b > 9) {
                cout << "Incorrect coordinates! Try again!" << endl;
            }
            else {
                if (!gameFieldTwo[x][y] && !gameFieldTwo[a][b])
                {
                    correct = true;
                    shipPlace(gameFieldOne, gameFieldTwo, x, y, a, b, 2);
                }
                else {
                    cout << "There is already a ship at the specified coordinates! Try again!" << endl;
                }
            }
        } while (!correct);
    }

    cout << "Player one, please input 2 coordinates for 3 middle ships: " << endl;
    for (int i = 0; i < 3; i++) {
        bool correct = false;
        do {
            cin >> x >> y >> a >> b;
            if (x < 0 || y < 0 || a < 0 || b < 0 || x > 9 || y > 9 || a > 9 || b > 9 ||
                ((abs(x - a) != 1 && abs(y - b) != 1) || (x != a && y != b)) ||
                ((x == a && abs(y - b) != 1) && (y != b)) ||
                ((y == b && abs(x - a) != 1) && (x != a))) {
                cout << "Incorrect coordinates! Try again!" << endl;
            }
            else {
                if (!gameFieldOne[x][y] && !gameFieldOne[a][b]) {
                    correct = true;
                    shipPlace(gameFieldOne, gameFieldTwo, x, y, a, b, 1);
                }
                else {
                    cout << "There is already a ship at that coordinate.Try again!";
                }
            }
        } while (!correct);

    }

    cout << "Player two, please input 2 coordinates for 3 middle ships: " << endl;
    for (int i = 0; i < 3; i++) {
        bool correct = false;
        do {
            cin >> x >> y >> a >> b;
            if (x < 0 || y < 0 || a < 0 || b < 0 || x > 9 || y > 9 || a > 9 || b > 9 ||
                ((abs(x - a) != 1 && abs(y - b) != 1) || (x != a && y != b)) ||
                ((x == a && abs(y - b) != 1) && (y != b)) ||
                ((y == b && abs(x - a) != 1) && (x != a))) {
                cout << "Incorrect coordinates! Try again!" << endl;
            }
            else {
                if (!gameFieldTwo[a][b] && !gameFieldTwo[x][y]) {
                    correct = true;
                    shipPlace(gameFieldOne, gameFieldTwo, x, y, a, b, 2);
                }
                else {
                    cout << "There is already a ship at that coordinate.Try again!";
                }
            }
        } while (!correct);
    }

    cout << "Player one, please input 2 coordinates for 2 big ships: " << endl;
    for (int i = 0; i < 2; i++) {
        bool correct = false;
        do {
            cin >> x >> y >> a >> b;
            if ((x < 0 || y < 0 || a < 0 || b < 0 || x > 9 || y > 9 || a > 9 || b > 9) ||
                ((x > a + 2) || (x < a - 2) || (y > b + 2) || (y < b - 2)) ||
                ((x == a && (y != b - 1 && y != b + 1 && y != b - 2 && y != b + 2)) && (y != b)) ||
                ((y == b && (x != a - 1 && x != a + 1 && x != a - 2 && x != a + 2)) && (x != a))) {
                cout << "Incorrect coordinates! Try again!" << endl;
            }
            else {
                if (!gameFieldOne[a][b] && !gameFieldOne[x][y]) {
                    correct = true;
                    shipPlace(gameFieldOne, gameFieldTwo, x, y, a, b, 1);
                }
                else {
                    cout << "There is already a ship at that coordinate.Try again!";
                }
            }
        } while (!correct);
    }

    cout << "Player two, please input 2 coordinates for 2 big ships: " << endl;
    for (int i = 0; i < 2; i++) {
        bool correct = false;
        do {
            cin >> x >> y >> a >> b;
            if ((x < 0 || y < 0 || a < 0 || b < 0 || x > 9 || y > 9 || a > 9 || b > 9) ||
                ((x > a + 2) || (x < a - 2) || (y > b + 2) || (y < b - 2)) ||
                ((x == a && (y != b - 1 && y != b + 1 && y != b - 2 && y != b + 2)) && (y != b)) ||
                ((y == b && (x != a - 1 && x != a + 1 && x != a - 2 && x != a + 2)) && (x != a))) {
                cout << "Incorrect coordinates! Try again!" << endl;
            }
            else {
                if (!gameFieldTwo[x][y] && !gameFieldTwo[a][b]) {
                    correct = true;
                    shipPlace(gameFieldOne, gameFieldTwo, x, y, a, b, 2);
                }
                else {
                    cout << "There is already a ship at that coordinate.Try again!";
                }
            }
        } while (!correct);

    }

    cout << "Player one, please input 2 coordinates for 1 lyncorne: " << endl;
    for (int i = 0; i < 1; i++) {
        bool correct = false;
        do {
            cin >> x >> y >> a >> b;
            if ((x < 0 || y < 0 || a < 0 || b < 0 || x > 9 || y > 9 || a > 9 || b > 9) ||
                ((abs(x - a) != 3 && abs(y - b) != 3) || (x != a && y != b)) ||
                ((x == a && abs(y - b) > 3) && (y != b)) ||
                ((y == b && abs(x - a) > 3) && (x != a))) {
                cout << "Incorrect coordinates! Try again!" << endl;
            }
            else {
                if (!gameFieldOne[x][y] && !gameFieldOne[a][b]) {
                    correct = true;
                    shipPlace(gameFieldOne, gameFieldTwo, x, y, a, b, 1);
                }
                else {
                    cout << "There is already a ship at that coordinate.Try again!";
                }
            }
        } while (!correct);

    }


    cout << "Player two, please input 2 coordinates for 1 lyncorne: " << endl;
    for (int i = 0; i < 1; i++) {
        bool correct = false;
        do {
            cin >> x >> y >> a >> b;
            if ((x < 0 || y < 0 || a < 0 || b < 0 || x > 9 || y > 9 || a > 9 || b > 9) ||
                ((abs(x - a) != 3 && abs(y - b) != 3) || (x != a && y != b)) ||
                ((x == a && abs(y - b) > 3) && (y != b)) ||
                ((y == b && abs(x - a) > 3) && (x != a))) {
                cout << "Incorrect coordinates! Try again!" << endl;
            }
            else {
                if (!gameFieldTwo[x][y] && !gameFieldTwo[a][b]) {
                    correct = true;
                    shipPlace(gameFieldOne, gameFieldTwo, x, y, a, b, 2);
                }
                else {
                    cout << "There is already a ship at that coordinate.Try again!";
                }
            }
        } while (!correct);

    }
}

void battleSystem(bool gameFieldOne[10][10], bool gameFieldTwo[10][10], int x, int y) {
    bool playerOneShot[10][10] = { false };
    bool playerTwoShot[10][10] = { false };
    do {
        cout << "Player one, input coord for shoot: " << endl;
        cin >> x >> y;
        if (x < 0 || x > 9 || y < 0 || y > 9) {
            cout << "Incorrect coord.Try again!" << endl;
        }
        if (gameFieldTwo[x][y] == true) {
            playerOneShot[x][y] = true;
            gameFieldTwo[x][y] = false;
            cout << "Bang, yoy got it!" << endl;
        }
        else {
            cout << "Miss" << endl;
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (playerOneShot[i][j] == true) {
                    cout << "X" << " ";
                }
                else {
                    cout << "O" << " ";
                }
            }
            cout << endl;
        }
        cout << "Player two, input coord for shoot: " << endl;
        cin >> x >> y;
        if (x < 0 || x > 9 || y < 0 || y > 9) {
            cout << "Incorrect coord.Try again!" << endl;
        }
        if (gameFieldOne[x][y] == true) {
            playerTwoShot[x][y] = true;
            gameFieldOne[x][y] = false;
            cout << "Bang, yoy got it!" << endl;
        }
        else {
            cout << "Miss" << endl;
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (playerTwoShot[i][j] == true) {
                    cout << "X" << " ";
                }
                else {
                    cout << "O" << " ";
                }
            }
            cout << endl;
        }

    } while (!checkForShips(gameFieldOne, gameFieldTwo));
}

bool checkForShips(bool gameFieldOne[10][10], bool gameFieldTwo[10][10]) {
    bool shipsLeftOne = false;
    bool shipsLeftTwo = false;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (gameFieldOne[i][j]) {
                shipsLeftOne = true;
                break;
            }
        }
        if (shipsLeftOne) break;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (gameFieldTwo[i][j]) {
                shipsLeftTwo = true;
                break;
            }
        }
        if (shipsLeftTwo) break;
    }
    if (!shipsLeftOne) {
        cout << "Player two WINS this battle!" << "\n";
    }
    else if (!shipsLeftTwo) {
        cout << "Player one WINS this battle!" << "\n";
    }
    return !(shipsLeftOne && shipsLeftTwo);
}

int main() {

    bool gameFieldOne[10][10] = { false };
    bool gameFieldTwo[10][10] = { false };

    int x = 0;
    int y = 0;
    int a = 0;
    int b = 0;

    cout << "Welcome, to the warship battle!" << endl;

    shipsPlacement(gameFieldOne, gameFieldTwo, x, y, a, b);
    battleSystem(gameFieldOne, gameFieldTwo, x, y);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (gameFieldOne[i][j] == true) {
                cout << "X" << " ";
            }
            else {
                cout << "O" << " ";
            }
        }
        cout << endl;
    }

    cout << "\n";

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (gameFieldTwo[i][j] == true) {
                cout << "X" << " ";
            }
            else {
                cout << "O" << " ";
            }
        }
        cout << endl;
    }
    cout << "Thx for the game!" << endl;
    return 0;
}
