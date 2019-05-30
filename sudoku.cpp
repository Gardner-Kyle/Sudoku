/***********************************************************************
* Program:
*    Project 13, Sudoku
*    Brother Manley, cs124
* Author:
*    Kyle Gardner
* Summary:
*    This program will ask user for a sudoku file and then, depending on the
*    user's choice, either show instructions, display the board again, edit
*    one square, show possible values for a square, or save to a specified
*    file and quit.
*
*    Estimated:  20.0 hrs
*    Actual:     12.0 hrs
*      The hardest part was creating the loops and if statements to assure
*      validity in the editSquare and showValues functions.
************************************************************************/
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

/**********************************************************************
 * Prompt user for file name.
 ***********************************************************************/
void getFilename(char filename[])
{
   cout << "Where is your board located? ";
   cin >> filename;
}

/**********************************************************************
 * Read file into a two-dimensional array.
 ***********************************************************************/
void readFile(char filename[], int board[][256])
{
   ifstream fin(filename);
   if (fin.fail())
   {
      cout << "File reading error.";
   }
   for (int row = 0; row < 9; row++)
      for (int col = 0; col < 9; col++)
         fin >> board[row][col];
   fin.close();
}

/**********************************************************************
 * Display the options menu.
 ***********************************************************************/
void displayMenu()
{
   cout << "Options:"
        << endl
        << "   ?  Show these instructions"
        << endl
        << "   D  Display the board"
        << endl
        << "   E  Edit one square"
        << endl
        << "   S  Show the possible values for a square"
        << endl
        << "   Q  Save and Quit";
}

/**********************************************************************
 * Display the sudoku board.
 ***********************************************************************/
void displayBoard(int board[][256])
{
   cout << "   A B C D E F G H I"
        << endl;

   for (int row = 0; row < 9; row++)
   {
      cout << row + 1
           << "  ";
      for (int col = 0; col < 9; col++)
      {
         if (board[row][col] == 0)
         {
            if (col == 8)
               cout << " ";
            else if (col == 2 || col == 5)
               cout << " |";
            else
               cout << "  ";
         }
         else
         {
            cout << board[row][col];
            if (col == 2 || col == 5)
               cout << "|";
            else if (col != 8)
               cout << " ";
         }
      }
      if (row == 2 || row == 5)
         cout << endl
              << "   -----+-----+-----";
      cout << endl;
   }

}

/**********************************************************************
 * Prompt user for the name of the file he wishes to keep his sudoku board.
 ***********************************************************************/
void getFilename2(char filename2[])
{
   cout << "What file would you like to write your board to: ";
   cin >> filename2;
}

/**********************************************************************
 * Write the sudoku board to the file chosen by the user.
 ***********************************************************************/
void writeFile(char filename2[], int board[][256])
{
   ofstream fout(filename2);
   for (int row = 0; row < 9; row++)
   {
      for (int col = 0; col < 9; col++)
      {
         fout << board[row][col];
         fout << " ";
      }
      fout << endl;
   }
   fout.close();
   cout << "Board written successfully\n";
}

/**********************************************************************
 * Save sudoku board to a file and stop playing.
 ***********************************************************************/
void saveQuit(char filename2[], int board[][256])
{
   getFilename2(filename2);
   writeFile(filename2, board);
}

/**********************************************************************
 * Edit one specific square of the sudoku board.
 ***********************************************************************/
void editSquare(int board[][256])
{
   bool validity = false;
   int numRow;
   int numCol;
   int value[1];
   char square[1][2];

   cout << "What are the coordinates of the square: ";
   for (int i = 0; i < 2; i++)
   {
      cin >> square[0][i];
   }

   numRow = int(square[0][1]) - 49;
   numCol = toupper(square[0][0]) - 65;

   if (board[numRow][numCol] != 0)
   {
      cout << "ERROR: Square '"
           << (char)toupper(square[0][0])
           << square[0][1]
           << "' is filled"
           << endl;
      return;
   }

   cout << "What is the value at '"
        << (char)toupper(square[0][0])
        << square[0][1]
        << "': ";
   cin >> value[0];

   if (board[numRow][0] != value[0]
       && board[numRow][1] != value[0]
       && board[numRow][2] != value[0]
       && board[numRow][3] != value[0]
       && board[numRow][4] != value[0]
       && board[numRow][5] != value[0]
       && board[numRow][6] != value[0]
       && board[numRow][7] != value[0]
       && board[numRow][8] != value[0]
       && board[0][numCol] != value[0]
       && board[1][numCol] != value[0]
       && board[2][numCol] != value[0]
       && board[3][numCol] != value[0]
       && board[4][numCol] != value[0]
       && board[5][numCol] != value[0]
       && board[6][numCol] != value[0]
       && board[7][numCol] != value[0]
       && board[8][numCol] != value[0])
   {
      if ((numRow == 0 || numRow == 1 || numRow == 2) &&
          (numCol == 0 || numCol == 1 || numCol == 2))
      {
         for (int row = 0; row < 3; row++)
            for (int col = 0; col < 3; col++)
               if (board[row][col] == value[0])
               {
                  cout << "ERROR: Value '"
                       << value[0]
                       << "' in square '"
                       << (char)toupper(square[0][0])
                       << square[0][1]
                       << "' is invalid"
                       << endl;
                  return;
               }
               else
                  validity = true;
      }
      else if ((numRow == 0 || numRow == 1 || numRow == 2) &&
               (numCol == 3 || numCol == 4 || numCol == 5))
      {
         for (int row = 0; row < 3; row++)
            for (int col = 3; col < 6; col++)
               if (board[row][col] == value[0])
               {
                  cout << "ERROR: Value '"
                       << value[0]
                       << "' in square '"
                       << (char)toupper(square[0][0])
                       << square[0][1]
                       << "' is invalid"
                       << endl;
                  return;
               }
               else
                  validity = true;
      }
      else if ((numRow == 0 || numRow == 1 || numRow == 2) &&
               (numCol == 6 || numCol == 7 || numCol == 8))
      {
         for (int row = 0; row < 3; row++)
            for (int col = 6; col < 9; col++)
               if (board[row][col] == value[0])
               {
                  cout << "ERROR: Value '"
                       << value[0]
                       << "' in square '"
                       << (char)toupper(square[0][0])
                       << square[0][1]
                       << "' is invalid"
                       << endl;
                  return;
               }
               else
                  validity = true;
      }

      else if ((numRow == 3 || numRow == 4 || numRow == 5) &&
               (numCol == 0 || numCol == 1 || numCol == 2))
      {
         for (int row = 3; row < 6; row++)
            for (int col = 0; col < 0; col++)
               if (board[row][col] == value[0])
               {
                  cout << "ERROR: Value '"
                       << value[0]
                       << "' in square '"
                       << (char)toupper(square[0][0])
                       << square[0][1]
                       << "' is invalid"
                       << endl;
                  return;
               }
               else
                  validity = true;
      }
      else if ((numRow == 3 || numRow == 4 || numRow == 5) &&
               (numCol == 3 || numCol == 4 || numCol == 5))
      {
         for (int row = 3; row < 6; row++)
            for (int col = 3; col < 6; col++)
               if (board[row][col] == value[0])
               {
                  cout << "ERROR: Value '"
                       << value[0]
                       << "' in square '"
                       << (char)toupper(square[0][0])
                       << square[0][1]
                       << "' is invalid"
                       << endl;
                  return;
               }
               else
                  validity = true;

      }
      else if ((numRow == 3 || numRow == 4 || numRow == 5) &&
               (numCol == 6 || numCol == 7 || numCol == 8))
      {
         for (int row = 3; row < 6; row++)
            for (int col = 6; col < 9; col++)
               if (board[row][col] == value[0])
               {
                  cout << "ERROR: Value '"
                       << value[0]
                       << "' in square '"
                       << (char)toupper(square[0][0])
                       << square[0][1]
                       << "' is invalid"
                       << endl;
                  return;
               }
               else
                  validity = true;
      }
      else if ((numRow == 6 || numRow == 7 || numRow == 8) &&
               (numCol == 0 || numCol == 1 || numCol == 2))
      {
         for (int row = 6; row < 9; row++)
            for (int col = 0; col < 3; col++)
               if (board[row][col] == value[0])
               {
                  cout << "ERROR: Value '"
                       << value[0]
                       << "' in square '"
                       << (char)toupper(square[0][0])
                       << square[0][1]
                       << "' is invalid"
                       << endl;
                  return;
               }
               else
                  validity = true;
      }
      else if ((numRow == 6 || numRow == 7 || numRow == 8) &&
               (numCol == 3 || numCol == 4 || numCol == 5))
      {
         for (int row = 6; row < 9; row++)
            for (int col = 3; col < 6; col++)
               if (board[row][col] == value[0])
               {
                  cout << "ERROR: Value '"
                       << value[0]
                       << "' in square '"
                       << (char)toupper(square[0][0])
                       << square[0][1]
                       << "' is invalid"
                       << endl;
                  return;
               }
               else
                  validity = true;
      }
      else if ((numRow == 6 || numRow == 7 || numRow == 8) &&
          (numCol == 6 || numCol == 7 || numCol == 8))
      {
         for (int row = 6; row < 9; row++)
            for (int col = 6; col < 9; col++)
               if (board[row][col] == value[0])
               {
                  cout << "ERROR: Value '"
                       << value[0]
                       << "' in square '"
                       << (char)toupper(square[0][0])
                       << square[0][1]
                       << "' is invalid"
                       << endl;
                  return;
               }
               else
                  validity = true;
      }
      else
      {
         cout << "ERROR: Value '"
              << value[0]
              << "' in square '"
              << (char)toupper(square[0][0])
              << square[0][1]
              << "' is invalid"
              << endl;
         return;
      }
   }
   else
   {
      cout << "ERROR: Value '"
           << value[0]
           << "' in square '"
           << (char)toupper(square[0][0])
           << square[0][1]
           << "' is invalid"
           << endl;
      return;
   }
   if (validity == true)
      board[numRow][numCol] = value[0];
}

/**********************************************************************
 * Compute and display possible values of any specific square.
 ***********************************************************************/
void showValues(char coordinates[][1], int board[][256])
{
   int numRow;
   int numCol;
   int values[9];

   cout << "What are the coordinates of the square: ";

   for (int i = 0; i < 1; i++)
      cin >> coordinates[i];

   numRow = int(coordinates[0][1]) - 49;
   numCol = toupper(coordinates[0][0]) - 65;

   cout << "The possible values for '"
        << char(toupper(coordinates[0][0]))
        << coordinates[0][1]
        << "' are: ";

   int num = 0;
   for (int i = 0; i < 10; i++)
   {
      if (board[numRow][0] != i
          && board[numRow][1] != i
          && board[numRow][2] != i
          && board[numRow][3] != i
          && board[numRow][4] != i
          && board[numRow][5] != i
          && board[numRow][6] != i
          && board[numRow][7] != i
          && board[numRow][8] != i
          && board[0][numCol] != i
          && board[1][numCol] != i
          && board[2][numCol] != i
          && board[3][numCol] != i
          && board[4][numCol] != i
          && board[5][numCol] != i
          && board[6][numCol] != i
          && board[7][numCol] != i
          && board[8][numCol] != i)
      {
         if ((numRow == 0 || numRow == 1 || numRow == 2) &&
             (numCol == 0 || numCol == 1 || numCol == 2))
         {
            if (board[0][0] != i &&
                board[0][1] != i &&
                board[0][2] != i &&
                board[1][0] != i &&
                board[1][1] != i &&
                board[1][2] != i &&
                board[2][0] != i &&
                board[2][1] != i &&
                board[2][2] != i)
            {
               values[num] = i;
               num++;
            }

         }
         else if ((numRow == 0 || numRow == 1 || numRow == 2) &&
                  (numCol == 3 || numCol == 4 || numCol == 5))
         {
            if (board[0][3] != i &&
                board[0][4] != i &&
                board[0][5] != i &&
                board[1][3] != i &&
                board[1][4] != i &&
                board[1][5] != i &&
                board[2][3] != i &&
                board[2][4] != i &&
                board[2][5] != i)
            {
               values[num] = i;
               num++;
            }

         }
         else if ((numRow == 0 || numRow == 1 || numRow == 2) &&
                  (numCol == 6 || numCol == 7 || numCol == 8))
         {
            if (board[0][6] != i &&
                board[0][7] != i &&
                board[0][8] != i &&
                board[1][6] != i &&
                board[1][7] != i &&
                board[1][8] != i &&
                board[2][6] != i &&
                board[2][7] != i &&
                board[2][8] != i)
            {
               values[num] = i;
               num++;
            }

         }
         else if ((numRow == 3 || numRow == 4 || numRow == 5) &&
                  (numCol == 0 || numCol == 1 || numCol == 2))
         {
            if (board[3][0] != i &&
                board[3][1] != i &&
                board[3][2] != i &&
                board[4][0] != i &&
                board[4][1] != i &&
                board[4][2] != i &&
                board[5][0] != i &&
                board[5][1] != i &&
                board[5][2] != i)
            {
               values[num] = i;
               num++;
            }

         }
         else if ((numRow == 3 || numRow == 4 || numRow == 5) &&
                  (numCol == 3 || numCol == 4 || numCol == 5))
         {
            if (board[3][3] != i &&
                board[3][4] != i &&
                board[3][5] != i &&
                board[4][3] != i &&
                board[4][4] != i &&
                board[4][5] != i &&
                board[5][3] != i &&
                board[5][4] != i &&
                board[5][5] != i)
            {
               values[num] = i;
               num++;
            }

         }
         else if ((numRow == 3 || numRow == 4 || numRow == 5) &&
                  (numCol == 6 || numCol == 7 || numCol == 8))
         {
            if (board[3][6] != i &&
                board[3][7] != i &&
                board[3][8] != i &&
                board[4][6] != i &&
                board[4][7] != i &&
                board[4][8] != i &&
                board[5][6] != i &&
                board[5][7] != i &&
                board[5][8] != i)
            {
               values[num] = i;
               num++;
            }

         }
         else if ((numRow == 6 || numRow == 7 || numRow == 8) &&
                  (numCol == 0 || numCol == 1 || numCol == 2))
         {
            if (board[6][0] != i &&
                board[6][1] != i &&
                board[6][2] != i &&
                board[7][0] != i &&
                board[7][1] != i &&
                board[7][2] != i &&
                board[8][0] != i &&
                board[8][1] != i &&
                board[8][2] != i)
            {
               values[num] = i;
               num++;
            }

         }
         else if ((numRow == 6 || numRow == 7 || numRow == 8) &&
                  (numCol == 3 || numCol == 4 || numCol == 5))
         {
            if (board[6][3] != i &&
                board[6][4] != i &&
                board[6][5] != i &&
                board[7][3] != i &&
                board[7][4] != i &&
                board[7][5] != i &&
                board[8][3] != i &&
                board[8][4] != i &&
                board[8][5] != i)
            {
               values[num] = i;
               num++;
            }

         }
         else if ((numRow == 6 || numRow == 7 || numRow == 8) &&
                  (numCol == 6 || numCol == 7 || numCol == 8))
         {
            if (board[6][6] != i &&
                board[6][7] != i &&
                board[6][8] != i &&
                board[7][6] != i &&
                board[7][7] != i &&
                board[7][8] != i &&
                board[8][6] != i &&
                board[8][7] != i &&
                board[8][8] != i)
            {
               values[num] = i;
               num++;
            }
         }
      }
   }
   for (int i = 0; i < num; i++)
   {
      if (i != 0)
         cout << ", ";
      cout << values[i];
   }

   cout << endl;
}

/**********************************************************************
 * User interface used to perform other functions according to the desire of
 * the user.
 ***********************************************************************/
void interact(int board[][256], char coordinates[][1], char filename2[])
{
   char command;
   do
   {
      cout << endl
           << "> ";
      cin >> command;
      if (command == '?')
      {
         displayMenu();
         cout << endl
              << endl;
      }
      if (command == 'D' || command == 'd')
         displayBoard(board);
      if (command == 'E' || command == 'e')
         editSquare(board);
      if (command == 'S' || command == 's')
         showValues(coordinates, board);
      if (command == 'Q' || command == 'q')
         saveQuit(filename2, board);
   }
   while (command != 'Q' && command != 'q');

}

/**********************************************************************
 * Call other functions to guide user through solving a sudoku board of their
 * choice.
 ***********************************************************************/
int main()
{
   char filename[256];
   char filename2[256];
   int board[256][256];
   char coordinates[2][1];

   getFilename(filename);
   readFile(filename, board);
   displayMenu();

   cout << endl
        << endl;

   displayBoard(board);
   interact(board, coordinates, filename2);
   return 0;
}
