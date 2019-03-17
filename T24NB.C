/* Notebook database test programm
 * Protected by GNU GPL v3 license
 * PURPOSE: Main programm file
 * FILE: T24NB.C
 * DATE: 17.03.2019
 * PROGRAMMER: Andrey Shayda
 */

#include <stdio.h>

#include "NB.H"

#define MAX 50

/* Main programm function
 * ARGUMENTS: None.
 * RETURNS: None.
 */
void main( void )
{
  char help[1024] = "Help:\n  0 -> Exit\n  1 -> Add a new student\n  2 -> Delete student by number\n"
                 "  3 -> Output all students\n  4 -> Sort by:\n    1 -> alphabet\n    2 -> age\n  5 -> Reverse database\n"
                 "  6 -> Save database to file\n  7 -> Load database from file\n";
  char Fname[100];
  int i, DBSize = 0, run = 1;
  static PUPIL DB[MAX];

  while (run)
  {
    printf("\n%s\n", help);

    switch(getchar())
    {    
    case '0': 
      run = 0;
      printf("Thank you for using this product!\n"
             "Exiting!\n");
      break; 
    case '1':
      if (DBSize < MAX)
        ReadPupil(&DB[DBSize++]);
      else 
        printf("Not enough space left!\n");  
      break;
    case '2':
      printf("Enter number to delete:");
      scanf("%i", &i);
      GetStr(NULL, 0);

      if (i > DBSize || i < 1)
        printf("Incorrect number!\n");  
      else
      {
        int j;

        for (j = i; j < DBSize - 1; j++)
          DB[j] = DB[j + 1];
        
        DBSize--;
      }  
      break;
    case '3':
      for (i = 0; i < DBSize; i++)
        printf("%i) %s %s (%02i.%02i.%02i)\n", i + 1, DB[i].Name, 
               DB[i].Surname, DB[i].Birthday.Day, 
               DB[i].Birthday.Month, DB[i].Birthday.Year);  
      break;
    case '4':
      break;
    case '5':
      for (i = 0; i < DBSize / 2; i++)
        Swap(&DB[i], &DB[DBSize - i - 1]);  
      break;
    case '6':
      GetStr(NULL, 0);
      printf("Enter file to save:\n");
      GetStr(Fname, 100);
      SaveDB(DB, DBSize, Fname);
      break;
    case '7':
      GetStr(NULL, 0);
      printf("Enter file to load:\n");
      GetStr(Fname, 100);
      DBSize = LoadDB(DB, Fname); 
      break;
    }
    GetStr(NULL, 0);
  }
  getchar();
} /* End of 'main' function */

/* END OF 'T24NB.C' FILE */

