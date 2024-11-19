#include <iostream>

using namespace std;

void drawBoard(char *arrayOfSoc);
void playerMove(int *ptrCell);
int computureMove();
int winner(char *wCell, char *ppWon, char player);
void confirmationWinner(int isSelected, char plWon);

int main(void)
{
    int cellToPlay;
    char pWon;
    char playerSym = 'x';
    char computureSym = 'o';
    char arrayOfSoc[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int isWinnerSelected;

    while (isWinnerSelected)
    {
        drawBoard(arrayOfSoc);
        playerMove(&cellToPlay);
        int indCmp = computureMove();

        if (arrayOfSoc[cellToPlay - 1] == ' ')
        {
            arrayOfSoc[cellToPlay - 1] = playerSym;
        }
        else
        {
            cout << "You cant choose this cell. Try again ..." << endl;
            continue;
        };
        if (arrayOfSoc[indCmp] == ' ')
            arrayOfSoc[indCmp] = computureSym;
        else
        {
            for (int i = 0; i <= 9; i++)
            {
                if (arrayOfSoc[i] == ' ')
                {
                    arrayOfSoc[i] = computureSym;
                    break;
                }
            }
        }
        isWinnerSelected = winner(arrayOfSoc, &pWon, playerSym);
        if (!isWinnerSelected)
        {
            drawBoard(arrayOfSoc);
            confirmationWinner(isWinnerSelected, pWon);
        }
    }
    cout << "Thanks for playing this game !" << endl;
}
void confirmationWinner(int isSelected, char plWon)
{
    if (!isSelected)
    {
        (plWon == 'x') ? cout << "You win !\n" : cout << "Computure win !\n";
    }
}
int winner(char *wCell, char *ppWon, char player)
{
    if (wCell[0] != ' ' && wCell[0] == wCell[4] && wCell[4] == wCell[8])
    {
        (wCell[0] == player) ? *ppWon = 'x' : *ppWon = 'o';
        return 0;
    }
    else if (wCell[0] != ' ' && wCell[0] == wCell[1] && wCell[1] == wCell[2])
    {
        (wCell[0] == player) ? *ppWon = 'x' : *ppWon = 'o';
        return 0;
    }
    else if (wCell[0] != ' ' && wCell[0] == wCell[3] && wCell[3] == wCell[6])
    {
        (wCell[0] == player) ? *ppWon = 'x' : *ppWon = 'o';
        return 0;
    }
    else if (wCell[1] != ' ' && wCell[1] == wCell[4] && wCell[4] == wCell[7])
    {
        (wCell[1] == player) ? *ppWon = 'x' : *ppWon = 'o';
        return 0;
    }
    else if (wCell[2] != ' ' && wCell[2] == wCell[5] && wCell[5] == wCell[8])
    {
        (wCell[2] == player) ? *ppWon = 'x' : *ppWon = 'o';
        return 0;
    }
    else if (wCell[2] != ' ' && wCell[2] == wCell[4] && wCell[4] == wCell[6])
    {
        (wCell[2] == player) ? *ppWon = 'x' : *ppWon = 'o';
        return 0;
    }
    else if (wCell[3] != ' ' && wCell[3] == wCell[4] && wCell[4] == wCell[5])
    {
        (wCell[3] == player) ? *ppWon = 'x' : *ppWon = 'o';
        return 0;
    }
    else if (wCell[6] != ' ' && wCell[6] == wCell[7] && wCell[7] == wCell[8])
    {
        (wCell[6] == player) ? *ppWon = 'x' : *ppWon = 'o';
        return 0;
    }
    else
    {
        return 1;
    }
}
void drawBoard(char *arrayOfSoc)
{
    cout << "     |     |     " << endl;
    cout << "  " << arrayOfSoc[0] << "  |  " << arrayOfSoc[1] << "  |  " << arrayOfSoc[2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << arrayOfSoc[3] << "  |  " << arrayOfSoc[4] << "  |  " << arrayOfSoc[5] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << arrayOfSoc[6] << "  |  " << arrayOfSoc[7] << "  |  " << arrayOfSoc[8] << endl;
    cout << "     |     |     " << endl;
}
void playerMove(int *ptrCell)
{
    cout << "Choose a cell (1-9): ";
    cin >> *ptrCell;
}
int computureMove()
{
    int cellNo = rand() % 9;
    return cellNo;
}
