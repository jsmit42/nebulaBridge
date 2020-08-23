#include <iostream>
#include <cstdlib>
//#include <time>

#define NUM_ROWS 30
#define NUM_COLS 80
#define NUM_CITY 15

using namespace std;



void display();
void setCities(int qty);

char board[NUM_ROWS][NUM_COLS];

int main()
{

    srand (time(NULL));
    for (int i = 0; i < (NUM_ROWS * NUM_COLS); i++)
        board[0][i] = '~';

    setCities(NUM_CITY);
    display();

    return 0;
}

/*******
* display - displays the board with:
*           green cities
*           red paths
*           blue ocean
******/
void display()
{
    for (int i = 0; i < NUM_ROWS; i++)
        for (int j = 0; j < NUM_COLS; j++)
        {
            switch(board[i][j])
            {
                case '~':
                    cout << "\e[34m" << '~';
                    break;
                case 'O':
                    cout << "\e[32m" << 'O';
                    break;
                default:
                    cout << "\e[0m" << board[i][j];
            }
            if (j == (NUM_COLS - 1))
                cout << endl;
        }

}

/*******
* setCities - sets a designated number of citieis in
*             random locaions on the board
******/
void setCities(int qty)
{
    for (int i = 0; i < qty; i++)
        board[rand() % NUM_ROWS][rand() % NUM_COLS] = 'O';
}
