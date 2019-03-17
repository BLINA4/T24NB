/* Notebook database test programm
  * Protected by GNU GPL v3 license
  * PURPOSE: Database handle functions
  * FILE: T24NB.C
  * DATE: 17.03.2019
  * PROGRAMMER: Andrey Shayda
  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NB.H"

/* String reading function */
void GetStr( char *Str, int StrLen )
{
  int i = 0;
  char ch;

  while ((ch = getchar()) != '\n')
    if (Str != NULL && i < StrLen - 1)
      Str[i++] = ch;
  if (Str != NULL && i < StrLen)
    Str[i] = 0;  
} /* End of 'GetStr' function */

/* Pupil read function */
void ReadPupil( PUPIL *P )
{
  GetStr(NULL, 0);

  printf("Enter surname:\n");
  GetStr(P->Surname, 30);

  printf("Enter name:\n");
  GetStr(P->Name, 30);

  printf("Birthday:\n Day:\n");
  scanf("%i", &P->Birthday.Day);
  GetStr(NULL, 0);
  printf(" Month:\n");
  scanf("%i", &P->Birthday.Month);
  GetStr(NULL, 0);
  printf(" Year:\n");
  scanf("%i", &P->Birthday.Year);
  GetStr(NULL, 0);

  printf("Enter phone number:\n");
  GetStr(P->Phone, 20);

  printf("Enter sex:\n");
  if (getchar() == 'm')
    P->Sex = 'm';
  else
    P->Sex = 'f';
  GetStr(NULL, 0);

  printf("Enter form:\n");
  scanf("%i", &P->Form);
  GetStr(NULL, 0);

  printf("Enter form digit:\n");
  scanf("%c", &P->FormDigit);
  GetStr(NULL, 0);

  printf("Succes!\n");
} /* End of 'ReadPupil' function */

/* Swap pupils function */
void Swap( PUPIL *P1, PUPIL *P2 )
{
  PUPIL Tmp;

  Tmp = *P1;
  *P1 = *P2;
  *P2 = Tmp;
} /* End of 'Swap' function */

/* Database save function */
void SaveDB( PUPIL *DB, int DBSize, char *FileName )
{
  FILE *F;

  if ((F = fopen(FileName, "wb")) == NULL)
  { 
    printf("Error creating file!\n");  
    return;
  }

  fwrite(&DBSize, sizeof(int), 1, F);
  fwrite(DB, sizeof(PUPIL), DBSize, F);
} /* End of 'SaveDB' function */

/* Database load function */
int LoadDB( PUPIL *DB, char *FileName )
{
  int DBSize;
  FILE *F;
 
  if ((F = fopen(FileName, "rb")) == NULL)
  { 
    printf("Error loading file!\n"); 
    return 0;
  }

  fread(&DBSize, sizeof(int), 1, F);
  fread(DB, sizeof(PUPIL), DBSize, F);

  return DBSize;
} /* End of 'LoadDB' function */

/* Quick sort by alphabet function */
void SortAlphabet( PUPIL *DB, int N )
{
  int b, e;
  char x[30];

  strncpy(x, DB[N / 2].Surname, 30);

  b = 0;
  e = N - 1;
 
  if (N < 2)
    return;
 
  while (b <= e)
  {
    while (strncmp(DB[b].Surname, x, 30) < 0)
      b++;
    while (strncmp(DB[e].Surname, x, 30) > 0)
      e--;
    if (b <= e)
      Swap(&DB[b++], &DB[e--]);
  }
 
  SortAlphabet(DB, e + 1);
  SortAlphabet(DB + b, N - b);
} /* End of 'SortAlphabet' function */

/* Check date function */
int IsDateBigger( DATE A, DATE B )
{
  if (A.Year > B.Year)
    return 1;
  else
    if (A.Year == B.Year && A.Month > B.Month)
      return 1;
    else
      if (A.Year == B.Year && A.Month == B.Month && A.Day > B.Day)
        return 1;
  return 0;
} /* End of 'IsDateBigger' function */

/* Quick sort by DOB function */
void SortDOB( PUPIL *DB, int N )
{
  int b, e;
  DATE x = DB[N /2].Birthday;
 
  b = 0;
  e = N - 1;
 
  if (N < 2)
    return;
 
  while (b <= e)
  {
    while (IsDateBigger(x, DB[b].Birthday))
      b++;
    while (IsDateBigger(DB[e].Birthday, x))
      e--;
    if (b <= e)
      Swap(&DB[b++], &DB[e--]);
  }
 
  SortAlphabet(DB, e + 1);
  SortAlphabet(DB + b, N - b);
} /* End of 'SortDOB' function */

/* END OF 'NB.C' FILE */

