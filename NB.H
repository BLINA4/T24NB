/* Notebook database test programm
  * Protected by GNU GPL v3 license
  * PURPOSE: Database declaration & function prototypes
  * FILE: T24NB.C
  * DATE: 17.03.2019
  * PROGRAMMER: Andrey Shayda
  */

typedef struct 
{
  int Year, Month, Day;
} DATE;

typedef struct
{
  char Surname[30], Name[30];
  DATE Birthday;
  char Phone[20];
  char Sex;
  int Form;
  char FormDigit;
} PUPIL;

/* Pupil read function */
void ReadPupil( PUPIL *P );

/* String reading function */
void GetStr( char *Str, int StrLen );

/* Swap pupils function */
void Swap( PUPIL *P1, PUPIL *P2 );

/* Database load function */
int LoadDB( PUPIL *DB, char *FileName );

/* Database save function */
void SaveDB( PUPIL *DB, int DBSize, char *FileName );

/* END OF 'NB.H' FILE */

