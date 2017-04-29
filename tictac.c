
#include <stdio.h>

/* array/string declarations */
char a1 = ' ',
     a2 = ' ',
     a3 = ' ',
     b1 = ' ',
     b2 = ' ',
     b3 = ' ',
     c1 = ' ',
     c2 = ' ',
     c3 = ' ';

/* function prototypes */
void clrscrn( void );
void top_coords( void );
void dashes( void );
int  check_position( int pos );
void place_mark( int pos, char mark );
int  check_winner( void );
int  check_tie( void );

main()
{
   /* variable declarations */
   char coordinates[3] = " "; /* where to place mark */
   char x_o            = 'X'; /* X goes first */

   int taken_flag   = 0, /* flag = 1 if spot already used */
       invalid_flag = 0, /* flag = 1 if user select spot outside of c3 range */
       position     = 0,
       winner       = 0,
       tie          = 0;

   do
   {
      /* display board */
      clrscrn();

      if( taken_flag == 1 )
      {
         printf( "That spot is already taken.\n\n" );
         taken_flag--;
      }

      if( invalid_flag == 1 )
      {
         printf( "Invalid entry.\n\n" );
         invalid_flag--;
      }

      top_coords();
      printf( "1  %c | %c | %c\n", a1, b1, c1 );
      dashes();
      printf( "2  %c | %c | %c\n", a2, b2, c2 );
      dashes();
      printf( "3  %c | %c | %c\n", a3, b3, c3 );

      printf( "Where would you like to the %c?\n", x_o );
      puts( "Type a letter-number combination (example: a1) and hit 'Enter'." );
      gets( coordinates );

      coordinates[2] = '\0';

      /* set position from coordinates */
      if( coordinates[0] == 'a' && coordinates[1] == '1' )
         position = 1;

      else if( coordinates[0] == 'b' && coordinates[1] == '1' )
         position = 2;

      else if( coordinates[0] == 'c' && coordinates[1] == '1' )
         position = 3;

      else if( coordinates[0] == 'a' && coordinates[1] == '2' )
         position = 4;

      else if( coordinates[0] == 'b' && coordinates[1] == '2' )
         position = 5;

      else if( coordinates[0] == 'c' && coordinates[1] == '2' )
         position = 6;

      else if( coordinates[0] == 'a' && coordinates[1] == '3' )
         position = 7;

      else if( coordinates[0] == 'b' && coordinates[1] == '3' )
         position = 8;

      else if( coordinates[0] == 'c' && coordinates[1] == '3' )
         position = 9;

      else
      {
         invalid_flag = 1;
         continue;
      }

      taken_flag = check_position( position );

      if( taken_flag == 0 )
         place_mark( position, x_o );

      else
         continue;

      winner = check_winner();

      if( winner == 1 )
      {
         clrscrn();
         printf( "CONGRATULATIONS! %c's have won!\n", x_o );

         top_coords();
         printf( "1  %c | %c | %c\n", a1, b1, c1 );
         dashes();
         printf( "2  %c | %c | %c\n", a2, b2, c2 );
         dashes();
         printf( "3  %c | %c | %c\n", a3, b3, c3 );

         break;
      }

      else
         tie = check_tie();

      if( tie == 1 )
      {
         clrscrn();
         puts( "IT'S A DRAW!" );

         top_coords();
         printf( "1  %c | %c | %c\n", a1, b1, c1 );
         dashes();
         printf( "2  %c | %c | %c\n", a2, b2, c2 );
         dashes();
         printf( "3  %c | %c | %c\n", a3, b3, c3 );

         break;
      }

      /* toggle between X and O */
      if( x_o == 'X' )
         x_o = 'O';

      else
         x_o = 'X';

   } while( 1 );

}

/* clrscrn() clears the screen */
void clrscrn( void )
{
   int x = 0;

   for( x = 0; x < 20; x++ )
      printf( "\n" );
}

/* ASCII Tic Tac Toe Grid

   a   b   c

1    |   |
  ---+---+---
2    |   |
  ---+---+---
3    |   |

*/

/* top_coords() displayes letters at the top.
   Lets players select column on which to place mark. */
void top_coords( void )
{
   int count = 0;

   for( count = 0; count < 13; count++ )
   {
      if( count == 3 )
         printf( "a" );
      else if( count == 7 )
         printf( "b" );
      else if( count == 11 )
         printf( "c" );
      else
         printf( " " );
   }

   printf( "\n\n" );
}

/* dashes() prints horizontal separators */
void dashes( void )
{
   /* variable declarations */
   int count = 0;

   printf( " " );

   for( count = 0; count < 13; count++ )
   {
      if( count % 4 == 0 && count != 0 && count != 12)
         printf( "+" );
      else if( count > 0 && count != 12 )
         printf( "-" );
      else
         printf( " " );
   }

   printf( "\n" );
}

/* check_position() checks slot indicated by user.
   Returns 0 if empty/1 if taken. */
int check_position( int pos )
{
   /* variable declarations */
   int taken = 0;

   switch ( pos )
   {
      case 1:
         if( a1 != ' ' )
            taken = 1;
         break;

      case 2:
         if( b1 != ' ' )
            taken = 1;
         break;

      case 3:
         if( c1 != ' ' )
            taken = 1;
         break;

      case 4:
         if( a2 != ' ' )
            taken = 1;
         break;

      case 5:
         if( b2 != ' ' )
            taken = 1;
         break;

      case 6:
         if( c2 != ' ' )
            taken = 1;
         break;

      case 7:
         if( a3 != ' ' )
            taken = 1;
         break;

      case 8:
         if( b3 != ' ' )
            taken = 1;
         break;

      default: /* if pos = 9 */
         if( c3 != ' ' )
            taken = 1;
         break;
   }

   return taken;
}

/* place_mark() places X or O into the slot indicated by user.
   Takes position and returns 0 if successful/1 if slot previously used. */
void  place_mark( int pos, char mark )
{
   switch( pos )
   {
      case 1:
         a1 = mark;
         break;

      case 2:
         b1 = mark;
         break;

      case 3:
         c1 = mark;
         break;

      case 4:
         a2 = mark;
         break;

      case 5:
         b2 = mark;
         break;

      case 6:
         c2 = mark;
         break;

      case 7:
         a3 = mark;
         break;

      case 8:
         b3 = mark;
         break;

      default: /* if pos = 9 */
         c3 = mark;
         break;
   }         
}

/* check_winner() checks to see if last turn won the game */
int check_winner( void )
{
   int win = 0;

   /* horizontal checks */
   if( a1 != ' ' && a1 == a2 && a1 == a3 )
      win = 1;

   else if( a2 != ' ' && a2 == b2 && a2 == c2 )
      win = 1;

   else if( a3 != ' ' && a3 == b3 && a3 == c3 )
      win = 1;

   /* vertical checks */
   else if( a1 != ' ' && a1 == b1 && a1 == c1 )
      win = 1;

   else if( a2 != ' ' && a2 == b2 && a2 == c2 )
      win = 1;

   else if( a3 != ' ' && a3 == b3 && a3 == c3 )
      win = 1;

   /* diagnal checks */
   else if( a1 != ' ' && a1 == b2 && a1 == c3 )
      win = 1;

   else if( a3 != ' ' && a3 == b2 && a3 == c1 )
      win = 1;

   /* no winner yet */
   else
      win = 0;

   return win;
}

/* check_tie() checks to see if game is a draw */
int check_tie( void )
{
   int tie = 0;

   if( a1 != ' ' && b1 != ' ' && c1 != ' '
       && a2 != ' ' && b2 != ' ' && c2 != ' '
       && a3 != ' ' && b3 != ' ' && c3 != ' ' )
      tie = 1;

   return tie;
}
