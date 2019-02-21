#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <LCDColors.h>
#include <FEHBuzzer.h>
#include <stdlib.h>

/*
* This class, FootballField, contains one public function: DrawField().
* */

/*
* This class completes the requirement to include a class.
* */

class FootballField
{
public:
  
   /*
    *  This function contains commands to
    * manipulate the colors of the LCD screen and draw filled-in rectangles
    * that make up the field, endzones, block-O, and progress bar.
    * It is called with no arguments, and is type void so it doesn't return anything.
    * */
  
   void DrawField()
   {
       LCD.Clear( DARKOLIVEGREEN );
       LCD.SetFontColor( BLACK );
       LCD.FillRectangle(0,0,2,320);
       LCD.FillRectangle(0,0,14,2);
       LCD.FillRectangle(0,318,14,2);
       LCD.FillRectangle(12,0,2,320);
       LCD.SetFontColor( WHITESMOKE );
       LCD.FillRectangle(14,0,4,320);
       LCD.FillRectangle(88,0,4,320);
       LCD.FillRectangle(162,0,4,320);
       LCD.FillRectangle(236,0,4,320);
       LCD.FillRectangle(14,38,226,4);
       LCD.FillRectangle(14,86,226,4);
       LCD.FillRectangle(14,134,226,4);
       LCD.FillRectangle(14,182,226,4);
       LCD.FillRectangle(14,230,226,4);
       LCD.FillRectangle(14,278,226,4);
       LCD.SetFontColor( DARKOLIVEGREEN );
       LCD.FillRectangle(18,51,218,24);
       LCD.FillRectangle(18,100,218,24);
       LCD.FillRectangle(18,149,218,24);
       LCD.FillRectangle(18,198,218,24);
       LCD.FillRectangle(18,247,218,24);
       LCD.SetFontColor( SCARLET );
       LCD.FillRectangle(14,0,226,38);
       LCD.FillRectangle(14,282,226,38);
       LCD.FillRectangle(103,143,48,7);
       LCD.FillRectangle(103,170,48,7);
       LCD.FillRectangle(98,148,7,24);
       LCD.FillRectangle(149,148,7,24);
   }
  
};

/*
* This Class contains the various functions used to run the game's
* main menu and difficulty select menu.
* */

class Menu
{
public:
  
   /*
    * This function manipulates the Proteus LCD colors, and draws rectangles
    * as well as words to display the main menu for the game.
    * */
  
   void DrawMain()
   {
       LCD.Clear( DARKGRAY );
       LCD.SetFontColor( BLACK );
       LCD.FillRectangle(42,101,160,24);
       LCD.FillRectangle(42,135,160,24);
       LCD.FillRectangle(42,169,160,24);
       LCD.FillRectangle(42,203,160,24);
       LCD.FillRectangle(42,237,160,24);
       LCD.FillRectangle(127,271,75,24);
       LCD.SetFontColor( SCARLET );
       LCD.FillRectangle(40,99,160,24);
       LCD.FillRectangle(40,133,160,24);
       LCD.FillRectangle(40,167,160,24);
       LCD.FillRectangle(40,201,160,24);
       LCD.FillRectangle(40,235,160,24);
       LCD.FillRectangle(125,269,75,24);
       LCD.FillRectangle(40,19,13,4);
       LCD.FillRectangle(40,23,4,21);
       LCD.FillRectangle(54,23,4,9);
       LCD.FillRectangle(44,32,10,4);
       LCD.FillRectangle(54,36,4,8);
       LCD.WriteAt("EVENGE",60,27);
       LCD.FillRectangle(144,19,18,4);
       LCD.FillRectangle(151,19,4,25);
       LCD.WriteAt("OUR",165,27);
       LCD.FillRectangle(63,54,18,4);
       LCD.FillRectangle(63,54,4,25);
       LCD.FillRectangle(63,75,18,4);
       LCD.WriteAt("ANCELLED",82,62);
       LCD.SetFontColor( WHITE );
       LCD.SetBackgroundColor( SCARLET );
       LCD.WriteAt("START",45,103);
       LCD.WriteAt("INSTRUCTIONS",45,137);
       LCD.WriteAt("STATISTICS",45,171);
       LCD.WriteAt("CLEAR STATS",45,205);
       LCD.WriteAt("CREDITS",45,239);
       LCD.WriteAt("QUIT",130,273);
   }
  
   /*
    * This function manipulates the colors of the Proteus LCD and draws
    * rectangles and characters to the screen to display the difficulty
    * select menu for the game.
    * */
  
   void DrawDiff()
   {
       LCD.Clear( DARKGRAY );
       LCD.SetFontColor( BLACK );
       LCD.FillRectangle(42,135,160,24);
       LCD.FillRectangle(42,169,160,24);
       LCD.FillRectangle(42,203,160,24);
       LCD.SetFontColor( SCARLET );
       LCD.FillRectangle(40,133,160,24);
       LCD.FillRectangle(40,167,160,24);
       LCD.FillRectangle(40,201,160,24);
       LCD.SetFontColor( WHITE );
       LCD.SetBackgroundColor( SCARLET );
       LCD.WriteAt("EASY",45,137);
       LCD.WriteAt("MEDIUM",45,171);
       LCD.WriteAt("HARD",45,205);
   }
  
   /*
    * This function is to be used while the main menu is displayed.
    * It waits for the user to press and subsequently release the screen.
    * It stores the location of the screen press. Based on the location
    * of the screen press, this function returns a number that corresponds
    * to either one of the 6 possible selections, or a screen press that wasn't
    * on a button.
    * */
  
   int MainTouch()
   {
       int selection;
       float x_coord, y_coord, temp, dummyx, dummyy;
       while(!LCD.Touch(&x_coord,&y_coord));
       while(LCD.Touch(&dummyx,&dummyy));
       temp = x_coord;
       x_coord = y_coord;
       y_coord = 320 - temp;
      
       /*
        * Here is the required if-else structure.
        * */
      
       if (x_coord > 39 && x_coord < 200 && y_coord > 98 && y_coord < 123)
       {
           selection = 1;
       }
       else if (x_coord > 39 && x_coord < 200 && y_coord > 132 && y_coord < 157)
       {
           selection = 2;
       }
       else if (x_coord > 39 && x_coord < 200 && y_coord > 166 && y_coord < 191)
       {
           selection = 3;
       }
       else if (x_coord > 39 && x_coord < 200 && y_coord > 200 && y_coord < 225)
       {
           selection = 4;
       }
       else if (x_coord > 39. && x_coord < 200. && y_coord > 234. && y_coord < 259.)
       {
           selection = 5;
       }
       else if (x_coord > 124. && x_coord < 200. && y_coord > 268. && y_coord < 293.)
       {
           selection = 6;
       }
       else
       {
           selection = 0;
       }
       return selection;
   }
  
   /*
    * This function is to be used while the difficulty select menu is displayed.
    * It waits for the user to press and subsequently release the screen.
    * It stores the location of the screen press. Based on the location
    * of the screen press, this function returns a number that corresponds
    * to either one of the 3 possible selections, or a screen press that wasn't
    * on a button.
    * */
  
   int DiffTouch()
   {
       int selection;
       float x_coord, y_coord, temp, dummyx, dummyy;
       while(!LCD.Touch(&x_coord,&y_coord));
       while(LCD.Touch(&dummyx,&dummyy));
       temp = x_coord;
       x_coord = y_coord;
       y_coord = 320 - temp;
       if (x_coord > 39 && x_coord < 200 && y_coord > 132 && y_coord < 157)
       {
           selection = 1;
       }
       else if (x_coord > 39 && x_coord < 200 && y_coord > 166 && y_coord < 191)
       {
           selection = 2;
       }
       else if (x_coord > 39 && x_coord < 200 && y_coord > 200 && y_coord < 225)
       {
           selection = 3;
       }
       else
       {
           selection = 0;
       }
       return selection;
   }
};

/*
* This class runs the main game functions. Some of the functions within are called
* within other member functions in this class. Additionally, it contains public
* variables to keep track of statistics and it contains a private variable array
* that contains the top left coordinate points of each of the game's 14 "grid"
* locations.
* */

class Game
{
private:
  
   /*
    * This array contains coordinate points for each grid location so that
    * player sprites can be drawn and cleared from each grid position and
    * touch can be detected within each grid position.
    * */
  
   int gridIndex[2][14];
  
public:
  
   /*
    * These public variables keep track of the game statistics: both records
    * and individual game stats.
    * */
  
   int score, highScore, completions, maxCompletions;
   float gameTime, minGameTime;
  
   /*
    * This function displays the sprite of an OSU reciever in the given grid
    * position. The input argument is a number 0-13 that refers to the
    * grid position to draw the player. PixelDraw is used in conjunction with
    * various colors in order to fill each coordinate point in the appropriate
    * array with the correctly colored pixel.
    * */
  
   void DisplayReciever(int gridNum)
   {
       int k;
       int redArray[2][23] =
       {{6,7,8,8,9,9,10,10,10,11,11,11,11,12,12,12,12,12,26,26,27,27,29},
        {13,11,9,12,9,10,9,10,11,9,10,11,12,9,10,11,12,13,8,11,9,12,11}};
       //Pants T 2 B, L 2 R, Emblem L 2 R, Helmet L 2 R, B 2 T
       int grayArray[2][182] =
       {{9,9,9,9,10,10,10,10,10,10,11,11,11,11,11,11,11,11,12,12,12,12,12,12,12,12,12,12,12,13,13,13,13,13,13,13,13,13,13,13,14,14,14,14,14,14,14,14,14,15,15,15,15,15,15,16,16,16,16,16,17,17,17,18,18,18,19,19,19,20,20,20,21,21,21,22,22,22,22,23,23,23,24,24,24,24,24,25,25,25,25,25,25,25,25,26,26,26,26,26,26,26,26,26,26,26,27,27,27,27,27,27,27,27,27,27,27,27,28,28,28,28,28,28,28,28,28,28,29,29,29,29,29,29,29,29,30,30,30,30,30,30,17,18,14,14,14,14,15,15,15,15,15,16,16,16,16,16,17,17,17,17,17,18,18,18,18,18,18,18,19,19,19,19,19,20,20,20,20,21,21,22},{33,34,35,36,31,32,33,34,35,36,29,30,31,32,33,34,35,36,26,27,28,29,30,31,32,33,34,35,36,24,25,26,27,28,29,30,31,32,33,34,24,25,26,27,28,29,30,31,32,24,25,26,27,28,29,24,25,26,27,28,24,25,26,23,24,25,23,24,25,23,24,25,23,24,25,23,24,25,26,24,25,26,24,25,26,27,28,24,25,26,27,28,29,30,31,24,25,26,27,28,29,30,31,32,33,34,25,26,27,28,29,30,31,32,33,34,35,36,27,28,29,30,31,32,33,34,35,36,29,30,31,32,33,34,35,36,31,32,33,34,35,36,11,11,3,6,7,8,2,3,4,5,8,2,5,6,7,8,2,3,4,7,8,2,3,4,5,6,7,8,2,3,4,5,8,3,4,5,8,5,8,7}};
       int whiteArray[2][35]=
       {{7,7,8,9,14,15,16,17,17,17,17,17,17,17,17,18,18,18,19,19,19,20,20,20,20,20,20,20,24,24,25,26,26,27,28},{10,12,11,12,5,7,4,6,13,14,15,16,17,18,19,13,16,19,13,16,19,13,14,15,16,17,18,19,9,10,11,10,12,11,12}};
       int skinArray[2][79]=
       {{7,7,7,8,8,8,8,9,9,9,9,9,10,10,10,10,11,11,11,12,12,13,13,14,14,14,15,15,16,16,16,17,17,18,18,19,19,19,20,20,27,27,28,28,28,28,28,28,29,29,29,29,29,29,29,29,29,29,29,30,30,30,30,30,30,30,30,30,30,30,31,31,31,31,31,31,31,31,31},{14,15,16,14,15,16,17,14,15,16,17,18,15,16,17,18,16,17,18,17,18,17,18,16,17,18,17,18,9,9,10,9,10,9,7,6,7,6,7,8,2,6,7,8,9,10,11,0,1,2,3,4,5,6,7,8,9,10,0,1,2,3,4,5,6,7,8,9,10,0,1,2,3,4,5,6,7,8,9}};
       int blackArray[2][86]=
       {{6,7,8,8,9,9,10,13,13,13,13,13,14,15,16,17,18,19,20,21,21,23,23,24,25,26,27,28,29,8,8,9,9,9,9,10,10,10,10,10,11,11,11,11,11,11,12,12,12,12,12,13,13,13,13,14,27,27,27,27,27,28,28,28,28,28,29,29,29,29,29,30,30,30,30,30,31,31,31,31,32,32,32,32,33,33},{12,13,10,13,11,13,12,7,6,5,4,3,2,1,1,1,1,1,2,3,4,9,10,11,12,9,12,11,12,38,39,37,38,39,40,37,38,39,40,41,37,38,39,40,41,42,38,39,40,41,42,39,40,41,42,41,37,38,39,40,41,37,38,39,40,41,37,38,39,40,41,37,38,39,40,41,38,39,40,41,38,39,40,41,39,40}};
      
      
       LCD.SetFontColor ( SCARLET );
       LCD.FillRectangle(gridIndex[0][gridNum] + 13,gridIndex[1][gridNum] + 9,13,15);
      
       /*
        * This for loop completes the for loop requirement.
        * */
      
       for (k = 0; k < 23; k++)
       {
           LCD.DrawPixel(gridIndex[0][gridNum] + redArray[0][k], gridIndex[1][gridNum] + redArray[1][k]);
       }
       LCD.SetFontColor( SILVER );
       for (k = 0; k < 182; k++)
       {
           LCD.DrawPixel(gridIndex[0][gridNum] + grayArray[0][k], gridIndex[1][gridNum] + grayArray[1][k]);
       }
       LCD.SetFontColor( WHITE );
       for (k = 0; k < 35; k++)
       {
           LCD.DrawPixel(gridIndex[0][gridNum] + whiteArray[0][k], gridIndex[1][gridNum] + whiteArray[1][k]);
       }
       LCD.SetFontColor( PERU );
       for (k = 0; k < 79; k++)
       {
           LCD.DrawPixel(gridIndex[0][gridNum] + skinArray[0][k], gridIndex[1][gridNum] + skinArray[1][k]);
       }
       LCD.SetFontColor( BLACK );
       for (k = 0; k < 86; k++)
       {
           LCD.DrawPixel(gridIndex[0][gridNum] + blackArray[0][k], gridIndex[1][gridNum] + blackArray[1][k]);
       }
   }
  
   /*
    * This function displays the sprite of a MICH defender in the given grid
    * position. The input argument is a number 0-13 that refers to the
    * grid position to draw the player. PixelDraw is used in conjunction with
    * various colors in order to fill each coordinate point in the appropriate
    * array with the correctly colored pixel.
    * */
  
   void DisplayDefender(int gridNum)
   {
       int k;
       int blueArray[2][69] =
       {{6,7,8,8,9,9,10,10,10,11,11,11,11,12,12,12,12,12,26,26,27,27,29,14,14,14,14,15,15,15,15,15,16,16,16,16,16,17,17,17,17,17,18,18,18,18,18,18,18,19,19,19,19,19,20,20,20,20,21,21,22,14,14,15,15,16,16,17,17},
        {13,11,9,12,9,10,9,10,11,9,10,11,12,9,10,11,12,13,8,11,9,12,11,3,6,7,8,2,3,4,5,8,2,5,6,7,8,2,3,4,7,8,2,3,4,5,6,7,8,2,3,4,5,8,3,4,5,8,5,8,7,4,5,6,7,3,4,5,6}};
       //Pants T 2 B, L 2 R, Emblem L 2 R, Helmet L 2 R, B 2 T
       int pantsArray[2][144] =
       {{9,9,9,9,10,10,10,10,10,10,11,11,11,11,11,11,11,11,12,12,12,12,12,12,12,12,12,12,12,13,13,13,13,13,13,13,13,13,13,13,14,14,14,14,14,14,14,14,14,15,15,15,15,15,15,16,16,16,16,16,17,17,17,18,18,18,19,19,19,20,20,20,21,21,21,22,22,22,22,23,23,23,24,24,24,24,24,25,25,25,25,25,25,25,25,26,26,26,26,26,26,26,26,26,26,26,27,27,27,27,27,27,27,27,27,27,27,27,28,28,28,28,28,28,28,28,28,28,29,29,29,29,29,29,29,29,30,30,30,30,30,30,17,18},{33,34,35,36,31,32,33,34,35,36,29,30,31,32,33,34,35,36,26,27,28,29,30,31,32,33,34,35,36,24,25,26,27,28,29,30,31,32,33,34,24,25,26,27,28,29,30,31,32,24,25,26,27,28,29,24,25,26,27,28,24,25,26,23,24,25,23,24,25,23,24,25,23,24,25,23,24,25,26,24,25,26,24,25,26,27,28,24,25,26,27,28,29,30,31,24,25,26,27,28,29,30,31,32,33,34,25,26,27,28,29,30,31,32,33,34,35,36,27,28,29,30,31,32,33,34,35,36,29,30,31,32,33,34,35,36,31,32,33,34,35,36,11,11}};
       int stripeOneArray[2][31]=
       {{7,7,8,9,17,17,17,17,17,17,17,18,18,18,19,19,19,20,20,20,20,20,20,20,24,24,25,26,26,27,28},{10,12,11,12,13,14,15,16,17,18,19,13,16,19,13,16,19,13,14,15,16,17,18,19,9,10,11,10,12,11,12}};
       int skinArray[2][79]=
       {{7,7,7,8,8,8,8,9,9,9,9,9,10,10,10,10,11,11,11,12,12,13,13,14,14,14,15,15,16,16,16,17,17,18,18,19,19,19,20,20,27,27,28,28,28,28,28,28,29,29,29,29,29,29,29,29,29,29,29,30,30,30,30,30,30,30,30,30,30,30,31,31,31,31,31,31,31,31,31},{14,15,16,14,15,16,17,14,15,16,17,18,15,16,17,18,16,17,18,17,18,17,18,16,17,18,17,18,9,9,10,9,10,9,7,6,7,6,7,8,2,6,7,8,9,10,11,0,1,2,3,4,5,6,7,8,9,10,0,1,2,3,4,5,6,7,8,9,10,0,1,2,3,4,5,6,7,8,9}};
       int stripeTwoArray[2][86]=
       {{6,7,8,8,9,9,10,13,13,13,13,13,14,15,16,17,18,19,20,21,21,23,23,24,25,26,27,28,29,8,8,9,9,9,9,10,10,10,10,10,11,11,11,11,11,11,12,12,12,12,12,13,13,13,13,14,27,27,27,27,27,28,28,28,28,28,29,29,29,29,29,30,30,30,30,30,31,31,31,31,32,32,32,32,33,33},{12,13,10,13,11,13,12,7,6,5,4,3,2,1,1,1,1,1,2,3,4,9,10,11,12,9,12,11,12,38,39,37,38,39,40,37,38,39,40,41,37,38,39,40,41,42,38,39,40,41,42,39,40,41,42,41,37,38,39,40,41,37,38,39,40,41,37,38,39,40,41,37,38,39,40,41,38,39,40,41,38,39,40,41,39,40}};
      
      
       LCD.SetFontColor ( DARKBLUE );
       LCD.FillRectangle(gridIndex[0][gridNum] + 13,gridIndex[1][gridNum] + 9,13,15);
       for (k = 0; k < 69; k++)
       {
           LCD.DrawPixel(gridIndex[0][gridNum] + blueArray[0][k], gridIndex[1][gridNum] + blueArray[1][k]);
       }
       LCD.SetFontColor( DARKGOLDENROD );
       for (k = 0; k < 144; k++)
       {
           LCD.DrawPixel(gridIndex[0][gridNum] + pantsArray[0][k], gridIndex[1][gridNum] + pantsArray[1][k]);
       }
       LCD.SetFontColor( DARKGOLDENROD );
       for (k = 0; k < 31; k++)
       {
           LCD.DrawPixel(gridIndex[0][gridNum] + stripeOneArray[0][k], gridIndex[1][gridNum] + stripeOneArray[1][k]);
       }
       LCD.SetFontColor( PERU );
       for (k = 0; k < 79; k++)
       {
           LCD.DrawPixel(gridIndex[0][gridNum] + skinArray[0][k], gridIndex[1][gridNum] + skinArray[1][k]);
       }
       LCD.SetFontColor( DARKGOLDENROD );
       for (k = 0; k < 86; k++)
       {
           LCD.DrawPixel(gridIndex[0][gridNum] + stripeTwoArray[0][k], gridIndex[1][gridNum] + stripeTwoArray[1][k]);
       }
   }
  
   /*
    * This function clears the input grid space by filling it with a green
    * rectangle that is the same color as the field.
    * */
  
   void ClearGrid(int gridNum)
   {
       LCD.SetFontColor ( DARKOLIVEGREEN );
       LCD.FillRectangle(gridIndex[0][gridNum],gridIndex[1][gridNum],44,44);
   }
  
   /*
    * This checks if the user touches within the input grid space. If the user
    * touches within the selected space, the function returns 1. A touch outside
    * the grid space returns 2. Not touching returns 0.
    * */
  
   int CheckTouch(int g)
   {
       float x = 0, y = 0, temp;
       int retVal;
       if (LCD.Touch(&x, &y))
       {
           temp = x;
           x = y;
           y = 320 - temp;
          
           /*
            * In this if statement, we meet the requirement for logical AND relational
            * operators.
            * */
          
           if (x >= gridIndex[0][g] && x <= (gridIndex[0][g] + 44) && y >= gridIndex[1][g] && y <= (gridIndex[1][g] + 44))
           {
               retVal = 1;
           }
           else
           {
               retVal = 2;
           }
          
       }
       else
       {
           retVal = 0;
       }
       return retVal;
   }
  
   /*
    * This function plays Fight the Team Across the Field using the
    * Buzzer.Tone command.
    * */
  
   void PlayFightSong()
   {
       Buzzer.Tone( FEHBuzzer::Bf5, 300 );
       Buzzer.Tone( FEHBuzzer::A5,  100 );
       Buzzer.Tone( FEHBuzzer::Bf5, 300 );
       Buzzer.Tone( FEHBuzzer::A5,  100 );
       Buzzer.Tone( FEHBuzzer::Bf5, 200 );
       Buzzer.Tone( FEHBuzzer::A5,  200 );
       Buzzer.Tone( FEHBuzzer::G5,  200 );
       Buzzer.Tone( FEHBuzzer::Bf5, 200 );
       Buzzer.Tone( FEHBuzzer::A5,  300 );
       Buzzer.Tone( FEHBuzzer::Gs5, 100 );
       Buzzer.Tone( FEHBuzzer::A5,  300 );
       Buzzer.Tone( FEHBuzzer::Gs5, 100 );
       Buzzer.Tone( FEHBuzzer::A5,  800 );
       Buzzer.Tone( FEHBuzzer::A5,  300 );
       Buzzer.Tone( FEHBuzzer::Gs5, 100 );
       Buzzer.Tone( FEHBuzzer::A5,  300 );
       Buzzer.Tone( FEHBuzzer::Gs5, 100 );
       Buzzer.Tone( FEHBuzzer::A5,  200 );
       Buzzer.Tone( FEHBuzzer::G5,  200 );
       Buzzer.Tone( FEHBuzzer::F5,  200 );
       Buzzer.Tone( FEHBuzzer::A5,  200 );
       Buzzer.Tone( FEHBuzzer::G5,  300 );
       Buzzer.Tone( FEHBuzzer::A5,  100 );
       Buzzer.Tone( FEHBuzzer::A5,  200 );
       Buzzer.Tone( FEHBuzzer::D5,  200 );
       Buzzer.Tone( FEHBuzzer::F5,  200 );
       Buzzer.Tone( FEHBuzzer::F6,  200 );
       Buzzer.Tone( FEHBuzzer::F6,  200 );
       Buzzer.Tone( FEHBuzzer::F6,  200 );
       Buzzer.Tone( FEHBuzzer::C6,  200 );
       Buzzer.Tone( FEHBuzzer::A5,  200 );
       Buzzer.Tone( FEHBuzzer::G5,  200 );
       Buzzer.Tone( FEHBuzzer::F5,  200 );
       Buzzer.Tone( FEHBuzzer::Bf5, 100 );
       Buzzer.Tone( FEHBuzzer::A5,  200 );
       Buzzer.Tone( FEHBuzzer::G5,  100 );
       Buzzer.Tone( FEHBuzzer::F5,  400 );
       Buzzer.Tone( FEHBuzzer::C6,  200 );
       Buzzer.Tone( FEHBuzzer::A5,  200 );
       Buzzer.Tone( FEHBuzzer::G5,  200 );
       Buzzer.Tone( FEHBuzzer::A5,  200 );
       Buzzer.Tone( FEHBuzzer::Bf5, 100 );
       Buzzer.Tone( FEHBuzzer::A5,  200 );
       Buzzer.Tone( FEHBuzzer::Bf5, 100 );
       Buzzer.Tone( FEHBuzzer::C6,  400 );
       Buzzer.Tone( FEHBuzzer::D6,  400 );
       Buzzer.Tone( FEHBuzzer::D6,  300 );
       Buzzer.Tone( FEHBuzzer::C6,  100 );
       Buzzer.Tone( FEHBuzzer::Bf5, 200 );
       Buzzer.Tone( FEHBuzzer::G5,  200 );
       Buzzer.Tone( FEHBuzzer::F5,  300 );
       Buzzer.Tone( FEHBuzzer::Fs5, 100 );
       Buzzer.Tone( FEHBuzzer::G5,  100 );
       Buzzer.Tone( FEHBuzzer::Bf5, 200 );
       Buzzer.Tone( FEHBuzzer::G5,  100 );
       Buzzer.Tone( FEHBuzzer::Bf5, 200 );
       Buzzer.Tone( FEHBuzzer::A5,  200 );
       Buzzer.Tone( FEHBuzzer::Bf5, 500 );
   }
  
   /*
    * This function draws a combination of rectangles and text to inform
    * the user that they lost the game. It also shows the user their score for
    * the round.
    * */
  
   void ShowLoseScreen()
   {
       float x,y;
       LCD.Clear( DARKBLUE );
       LCD.SetFontColor( DARKGOLDENROD );
       LCD.SetBackgroundColor( DARKBLUE );
       LCD.WriteAt("GAME OVER",62,20);
       LCD.WriteAt("your score:",26,53);
       LCD.WriteAt(score, 158,53);
       LCD.FillRectangle(93,124,15,77);
       LCD.FillRectangle(106,139,10,27);
       LCD.FillRectangle(115,153,10,27);
       LCD.FillRectangle(124,140,10,27);
       LCD.FillRectangle(133,125,15,77);
       LCD.WriteAt("-Touch anywhere-",24,270);
       while(!LCD.Touch(&x,&y));
       while(LCD.Touch(&x,&y));
   }
  
   /*
    * This function draws a combination of rectangles and text to inform
    * the user that they won the game! It also shows the user their score for
    * the round.
    * */
  
   void ShowWinScreen()
   {
       float x, y;
       LCD.Clear( SCARLET );
       LCD.WriteAt("Buckeyes Win!",42,26);
       LCD.WriteAt("your score:",26,53);
       LCD.WriteAt(score, 158, 53);
       LCD.WriteAt("-Touch anywhere-",24,270);
       while(!LCD.Touch(&x,&y));
       while(LCD.Touch(&x,&y));
   }
  
   /*
    * This is the function called in order to run the easy version of the game.
    * */
  
   void gameStartEasy()
   {
      
       /*
        * Here we set game statistics to zero. We measure the start time
        * */
      
       int g, roundCont, gameCont = 1, down = 1, gain, yds = 0, prog = 0;
       int progLocation[2][4] = {{2,2,2,2},{309,206,103,2}};
       float roundStartTime, gameStartTime;
       score = 0;
       gameStartTime = TimeNow();
       completions = 0;
      
       /*
        * This loop continues as long as the game hasn't been won or lost.
        * */
      
       while(gameCont)
       {
           /*
            * Selects a random grid space from the 14 available.
            * */
          
           g = rand()%14;
          
           /*
            * Here we are displaying the current down in the style of an
            * orange down marker at the top right of the screen.
            * */
          
           LCD.SetBackgroundColor( ORANGERED );
           LCD.SetFontColor( GHOSTWHITE );
           LCD.WriteAt("DOWN: ", 140, 21);
           LCD.WriteAt(down, 212, 21);
          
           /*
            * Delay for random amount of time
            * */
          
           Sleep((rand()%4)*250);
          
           /*
            * Here we call the function to display a reciever in a random
            * position on the screen.
            * */
          
           DisplayReciever(g);
           roundStartTime = TimeNow();
           roundCont = 1;
           LCD.SetFontColor( ORANGERED );
           LCD.FillRectangle(progLocation[0][prog],progLocation[1][prog],10,10);
          
           /*
            * This loop runs for a small time and while
            * the screen hasn't been pressed.
            * */
          
           while((TimeNow() < (roundStartTime + rand()%3 + 1)) && roundCont)
           {
              
               /*
                * If the user touches within the grid space, complete pass.
                * Round is over.
                * */
              
               if (CheckTouch(g) == 1)
               {
                   roundCont = 0;
                   LCD.SetBackgroundColor( SCARLET );
                   LCD.SetFontColor( WHITE );
                   gain = rand()%9 + 1;
                   LCD.WriteAt("COMPLETE! +", 25, 4);
                   LCD.WriteAt(gain, 157, 4);
                   LCD.WriteAt(" yds      ", 169, 4);
                   yds = yds + gain;
                   score = score + gain;
                   completions++;
                  
                   /*
                    * If the gain takes the total recent gains to or above
                    * 10 yds, then it is a first down and the gains are reset
                    * */
                  
                   if (yds >= 10)
                   {
                       ClearGrid(g);
                       Sleep(1500);
                       LCD.SetFontColor( WHITE );
                       LCD.WriteAt("FIRST DOWN BUCKS!     ", 25, 4);
                       Sleep(250);
                       yds = 0;
                       down = 1;
                       prog++;
                       score = score + 50;
                   }
                   else
                   {
                       ClearGrid(g);
                       down++;
                       Sleep(150);
                   }
                   Sleep((rand()%4)*250);
               }
              
               /*
                * If the user touches a spot with no player,
                * it is an incomplete pass.
                * */
              
               else if (CheckTouch(g) == 2)
               {
                   ClearGrid(g);
                   roundCont = 0;
                   LCD.SetBackgroundColor( SCARLET );
                   LCD.SetFontColor( WHITE );
                   LCD.WriteAt("INCOMPLETE! 0 yds          ", 25,4);
                   down++;
                   score = score - 10;
               }
              
           }
          
           /*
            * If the user didn't touch a space after an amount of time,
            * it is a sack.
            * */
          
           if (CheckTouch(g) == 0 && roundCont == 1)
           {
               ClearGrid(g);
               LCD.SetBackgroundColor( SCARLET );
               LCD.SetFontColor( WHITE );
               LCD.WriteAt("SACKED! -5 yds       ", 25, 4);
               down++;
               yds = yds - 5;
               score = score - 35;
              
           }
          
           /*
            * If the user doesn't get a first down on 4th down, they lose.
            * The game loop will stop. The lose screen is shown.
            * */
          
           if (down > 4)
           {
               gameTime = TimeNow() - gameStartTime;
               score = score - 60;
               gameCont = 0;
               ShowLoseScreen();
           }
          
           /*
            * If the user gets the required 5 first downs, they win!
            * The game loop will stop because gameCont = 0. The win screen
            * is shown and the fight song is played.
            * */
          
           if (prog > 4)
           {
               gameTime = TimeNow() - gameStartTime;
               score = score + 60;
               ShowWinScreen();
               PlayFightSong();
               gameCont = 0;
           }
          
       }
   }
  
   /*
    * This is the function called in order to run the medium version of the game.
    * */
  
   void gameStartMedium()
   {
       /*
        * Here we set game statistics to zero. We measure the start time
        * */
      
       int g, roundCont, gameCont = 1, down = 1, gain, yds = 0, prog = 0, team, defSkill;
       int progLocation[2][4] = {{2,2,2,2},{309,206,103,2}};
       float roundStartTime;
       completions = 0;
      
       /*
        * This loop continues as long as the game hasn't been won or lost.
        * */
      
       while(gameCont)
       {
           g = rand()%14;
           team = rand()%5;
          
           /*
            * Here we are displaying the current down in the style of an
            * orange down marker at the top right of the screen.
            * */
          
           LCD.SetBackgroundColor( ORANGERED );
           LCD.SetFontColor( GHOSTWHITE );
           LCD.WriteAt("DOWN: ", 140, 21);
           LCD.WriteAt(down, 212, 21);
          
           /*
            * Delay for random amount of time
            * */
          
           Sleep((rand()%4)*250);
          
           /*
            * Here we call the function to display a reciever in a random
            * position on the screen.
            * */
          
           roundStartTime = TimeNow();
           roundCont = 1;
           LCD.SetFontColor( ORANGERED );
           LCD.FillRectangle(progLocation[0][prog],progLocation[1][prog],10,10);
           if (team > 0)
           {
               DisplayReciever(g);
               while((TimeNow() < (roundStartTime + rand()%3 + 1)) && roundCont)
               {
                  
                   /*
                    * This loop runs for a small time and while
                    * the screen hasn't been pressed.
                    * */
                  
                   if (CheckTouch(g) == 1)
                   {
                       roundCont = 0;
                       LCD.SetBackgroundColor( SCARLET );
                       LCD.SetFontColor( WHITE );
                       gain = rand()%5 + 5;
                       LCD.WriteAt("COMPLETE! +", 25, 4);
                       LCD.WriteAt(gain, 157, 4);
                       LCD.WriteAt(" yds      ", 169, 4);
                       yds = yds + gain;
                       completions++;
                      
                       /*
                        * If the gain takes the total recent gains to or above
                        * 10 yds, then it is a first down and the gains are reset
                        * */
                      
                       if (yds >= 10)
                       {
                           ClearGrid(g);
                           Sleep(1500);
                           LCD.SetFontColor( WHITE );
                           LCD.WriteAt("FIRST DOWN BUCKS!     ", 25, 4);
                           Sleep(250);
                           yds = 0;
                           down = 1;
                           prog++;
                       }
                       //if no first down increase the down
                       else
                       {
                           ClearGrid(g);
                           down++;
                           Sleep(150);
                       }
                      
                      
                       Sleep((rand()%4)*250);
                      
                      
                   }
                  
                   /*
                    * If the user touches a spot with no player,
                    * it is an incomplete pass.
                    * */
                  
                   else if (CheckTouch(g) == 2)
                   {
                       ClearGrid(g);
                       roundCont = 0;
                       LCD.SetBackgroundColor( SCARLET );
                       LCD.SetFontColor( WHITE );
                       LCD.WriteAt("INCOMPLETE! 0 yds          ", 25,4);
                       down++;
                   }
                  
               }
              
               /*
                * If the user didn't touch a space after an amount of time,
                * it is a sack.
                * */
              
               if (CheckTouch(g) == 0 && roundCont == 1)
               {
                   ClearGrid(g);
                   LCD.SetBackgroundColor( SCARLET );
                   LCD.SetFontColor( WHITE );
                   LCD.WriteAt("SACKED! -5 yds       ", 25, 4);
                   down++;
                   yds = yds - 5;
                  
               }
              
           }
           else
           {
               DisplayDefender(g);//displaying the defender
               while((TimeNow() < (roundStartTime + rand()%3 + 1)) && roundCont)
               {
                   if (CheckTouch(g) == 1)//if the michigan player is tapped
                   {
                       defSkill = rand()%2; //randomizing wheather the defender blocks or intercepts the ball
                       if (defSkill == 0)
                       {
                           roundCont = 0;
                           LCD.SetBackgroundColor( SCARLET );
                           LCD.SetFontColor( WHITE );
                           LCD.WriteAt("BLOCKED PASS! 0 yds      ", 25, 4);
                           down++;
                           ClearGrid(g);
                           Sleep(150);
                           Sleep((rand()%4)*250);
                           score -= 25;
                       }
                       else if (defSkill == 1)// the ball is intercepted
                       {
                           roundCont = 0;
                           LCD.SetBackgroundColor( SCARLET );
                           LCD.SetFontColor( WHITE );
                           LCD.WriteAt("INTERCEPTION! 0 yds      ", 25, 4);
                           down++;
                           ClearGrid(g);
                           Sleep(1500);
                           gameCont = 0;
                           score -= 70;
                           ShowLoseScreen();//displays the losing screen :(
                       }
                      
                   }
                   else if (CheckTouch(g) == 2)// if they click not on a player
                   {
                       ClearGrid(g);
                       roundCont = 0;
                       LCD.SetBackgroundColor( SCARLET );
                       LCD.SetFontColor( WHITE );
                       LCD.WriteAt("INCOMPLETE! 0 yds          ", 25,4);//incomplete pass
                       down++;
                       score -= 10;//penalize the player
                   }
                  
               }
              
               if (CheckTouch(g) == 0 && roundCont == 1)// if the defender is not clicked
               {
                   ClearGrid(g);
                   LCD.SetBackgroundColor( SCARLET );
                   LCD.SetFontColor( WHITE );
                   LCD.WriteAt("DEFENDER EVADED       ", 25, 4);
                   score += 10;// add points
               }
           }
          
          
           /*
            * If the user doesn't get a first down on 4th down, they lose.
            * The game loop will stop. The lose screen is shown.
            * */
          
           if (down > 4)
           {
               gameCont = 0;
               ShowLoseScreen();
           }
           if (prog > 4)
           {
               ShowWinScreen();
               PlayFightSong();
               gameCont = 0;
           }
       }
   }
  
   /*
    * This is the function called in order to run the hard version of the game.
    * */
  
   void gameStartHard()
   {
       /*
        * Here we set game statistics to zero. We measure the start time
        * */
      
       int g, roundCont, gameCont = 1, down = 1, gain, yds = 0, prog = 0, team, defSkill;
       int progLocation[2][4] = {{2,2,2,2},{309,206,103,2}};
       float roundStartTime;
       score = 0;
       completions = 0;
      
       /*
        * This loop continues as long as the game hasn't been won or lost.
        * */
      
       while(gameCont)
       {
           g = rand()%14;
           team = rand()%10;
          
           /*
            * Here we are displaying the current down in the style of an
            * orange down marker at the top right of the screen.
            * */
          
           LCD.SetBackgroundColor( ORANGERED );
           LCD.SetFontColor( GHOSTWHITE );
           LCD.WriteAt("DOWN: ", 140, 21);
           LCD.WriteAt(down, 212, 21);
          
           /*
            * Delay for random amount of time
            * */
          
           Sleep((rand()%4)*250);
          
           /*
            * Here we call the function to display a reciever in a random
            * position on the screen.
            * */
          
           roundStartTime = TimeNow();
           roundCont = 1;
           LCD.SetFontColor( ORANGERED );
           LCD.FillRectangle(progLocation[0][prog],progLocation[1][prog],10,10);
           if (team > 3)
           {
               DisplayReciever(g);
               while((TimeNow() < (roundStartTime + (rand()%3 * 0.5) + 0.25)) && roundCont)
               {
                   /*
                    * This loop runs for a small time and while
                    * the screen hasn't been pressed.
                    * */
                  
                   if (CheckTouch(g) == 1) // if a pass is completed - osu player tapped on time
                   {
                       roundCont = 0;
                       LCD.SetBackgroundColor( SCARLET );
                       LCD.SetFontColor( WHITE );
                       gain = rand()%5 + 5;
                       LCD.WriteAt("COMPLETE! +", 25, 4);
                       LCD.WriteAt(gain, 157, 4);
                       LCD.WriteAt(" yds      ", 169, 4);
                       yds = yds + gain;
                       score = score + gain;
                       completions++; // increment pass completions for the stats page
                      
                       /*
                        * If the gain takes the total recent gains to or above
                        * 10 yds, then it is a first down and the gains are reset
                        * */
                      
                       if (yds >= 10) // displays a first down
                       {
                           ClearGrid(g);
                           Sleep(1500);
                           LCD.SetFontColor( WHITE );
                           LCD.WriteAt("FIRST DOWN BUCKS!     ", 25, 4);
                           Sleep(250);
                           yds = 0;
                           down = 1;
                           prog++; // number of first downs incremented to decide win
                           score += 50;
                       }
                       else
                       {
                           ClearGrid(g);
                           down++;
                           Sleep(150);
                       }
                      
                      
                       Sleep((rand()%4)*250);
                      
                      
                   }
                  
                   /*
                    * If the user touches a spot with no player,
                    * it is an incomplete pass.
                    * */
                  
                   else if (CheckTouch(g) == 2) // if the player touches the field
                   {
                       ClearGrid(g);
                       roundCont = 0;
                       LCD.SetBackgroundColor( SCARLET );
                       LCD.SetFontColor( WHITE );
                       LCD.WriteAt("INCOMPLETE! 0 yds          ", 25,4);
                       down++;
                       score -= 10; // subtract points
                   }
                  
               }
              
               /*
                * If the user didn't touch a space after an amount of time,
                * it is a sack.
                * */
              
               if (CheckTouch(g) == 0 && roundCont == 1)// if a pass is not completed in time
               {
                   ClearGrid(g);
                   LCD.SetBackgroundColor( SCARLET );
                   LCD.SetFontColor( WHITE );
                   LCD.WriteAt("SACKED! -5 yds       ", 25, 4);
                   down++;
                   yds = yds - 5;
                   score -= 35; // subtract 35 points from the score
               }
              
           }
           else if (team > 1)// displaying a michigan player
           {
               DisplayDefender(g);
               while((TimeNow() < (roundStartTime + rand()%3 * 0.5 + 1)) && roundCont)
               {
                   if (CheckTouch(g) == 1)// if the player is tapped
                   {
                       defSkill = rand()%2;
                       if (defSkill == 0)
                       {
                           roundCont = 0;
                           LCD.SetBackgroundColor( SCARLET );//blocked pass
                           LCD.SetFontColor( WHITE );
                           LCD.WriteAt("BLOCKED PASS! 0 yds      ", 25, 4);
                           down++;
                           ClearGrid(g);
                           Sleep(150);
                           Sleep((rand()%4)*250);
                           score -= 25;// if the ball is blocked sub points
                       }
                       else if (defSkill == 1)// if the ball is intercepted
                       {
                           roundCont = 0;
                           LCD.SetBackgroundColor( SCARLET );
                           LCD.SetFontColor( WHITE );
                           LCD.WriteAt("INTERCEPTION! 0 yds      ", 25, 4);
                           down++;
                           ClearGrid(g);
                           Sleep(1500);
                           gameCont = 0;
                           score -= 70;
                           ShowLoseScreen();//displaying the lose screen
                       }
                      
                   }
                   else if (CheckTouch(g) == 2)// if a pass is not made to an OSU player
                   {
                       ClearGrid(g);
                       roundCont = 0;
                       LCD.SetBackgroundColor( SCARLET );
                       LCD.SetFontColor( WHITE );
                       LCD.WriteAt("INCOMPLETE! 0 yds          ", 25,4);
                       down++;
                       score -= 10;
                   }
                  
               }
              
               if (CheckTouch(g) == 0 && roundCont == 1)// if the defender is not clicked
               {
                   ClearGrid(g);
                   LCD.SetBackgroundColor( SCARLET );
                   LCD.SetFontColor( WHITE );
                   LCD.WriteAt("DEFENDER EVADED       ", 25, 4);
                   score += 10;
               }
           }
           else
           {
               DisplayReciever(g);// displaying the osu plauyer
               while((TimeNow() < (roundStartTime + 0.25)) && roundCont)
               {
                   if (CheckTouch(g) == 1)// if a first down is made
                   {
                       roundCont = 0;
                       LCD.SetBackgroundColor( SCARLET );
                       LCD.SetFontColor( WHITE );
                       gain = rand()%5 + 5;
                       LCD.WriteAt("COMPLETE! +", 25, 4);
                       LCD.WriteAt(gain, 157, 4);
                       LCD.WriteAt(" yds      ", 169, 4);
                       yds = yds + gain;
                       score += gain;
                       completions++;
                       if (yds >= 10)
                       {
                           ClearGrid(g);
                           Sleep(1500);
                           LCD.SetFontColor( WHITE );
                           LCD.WriteAt("FIRST DOWN BUCKS!     ", 25, 4);
                           Sleep(250);
                           yds = 0;
                           down = 1;
                           prog++;
                           score += 50;// add points
                       }
                      
                       else
                       {
                           ClearGrid(g);
                           down++;
                           Sleep(150);
                       }
                      
                      
                   }
                   else if (CheckTouch(g) == 2) // if a pass is not made
                   {
                       ClearGrid(g);
                       roundCont = 0;
                       LCD.SetBackgroundColor( SCARLET );
                       LCD.SetFontColor( WHITE );
                       LCD.WriteAt("INCOMPLETE! 0 yds          ", 25,4);
                       down++;
                       score -= 10; // subtract points
                      
                   }
               }
               if (CheckTouch(g) == 0 && roundCont == 1)
               {
                   DisplayDefender(g);// displaying the defender
                   while((TimeNow() < (roundStartTime + rand()%3 + 1)) && roundCont)
                   {
                       if (CheckTouch(g) == 1)// if a michigan player is tapped
                       {
                           roundCont = 0;
                           LCD.SetBackgroundColor( SCARLET );
                           LCD.SetFontColor( WHITE );
                           LCD.WriteAt("INTERCEPTION! 0 yds      ", 25, 4);
                           down++;
                           ClearGrid(g);
                           Sleep(1500);
                           gameCont = 0;
                           score -= 70; //subtra
                           ShowLoseScreen();
                       }
                       else if (CheckTouch(g) == 2)
                       {
                           ClearGrid(g);
                           roundCont = 0;
                           LCD.SetBackgroundColor( SCARLET );
                           LCD.SetFontColor( WHITE );
                           LCD.WriteAt("INCOMPLETE! 0 yds          ", 25,4);
                           down++;
                           score -= 10;
                       }
                      
                   }
                  
                   if (CheckTouch(g) == 0 && roundCont == 1)
                   {
                       ClearGrid(g);
                       LCD.SetBackgroundColor( SCARLET );
                       LCD.SetFontColor( WHITE );
                       LCD.WriteAt("DEFENDER EVADED       ", 25, 4);
                   }
                  
                  
               }
           }
       }
       /*
        * If the user doesn't get a first down on 4th down, they lose.
        * The game loop will stop. The lose screen is shown.
        * */
      
      
       if (down > 4)
       {
           gameCont = 0;
           ShowLoseScreen();
       }
       if (prog > 4)
       {
           ShowWinScreen();
           PlayFightSong();
           gameCont = 0;
       }
   }
  
   /*
    * This is the constructor for the class. It uses a for loop to fill in the
    * values of the grid index array from a pre-defined array of the same values.
    * */
  
   Game()
   {
       int k;
      
       /*
        * These are the upper-left coordinate points of each of the 14 grid positions
        * */
      
       int gi[2][14]=
       {{31, 106, 179, 31, 106, 179, 31, 179, 31, 106, 179, 31, 106, 179},{42, 42, 42, 90, 90, 90, 138, 138, 186, 186, 186, 234, 234, 234}};
       for (k = 0; k < 14; k++)
       {
           gridIndex[0][k] = gi[0][k];
           gridIndex[1][k] = gi[1][k];
       }
      
       /*
        * Here we are initializing the high scores and round scores
        * */
      
       score = 0;
       gameTime = 0;
       highScore = 0;
       minGameTime = 999999;
       completions = 0;
       maxCompletions = 0;
   }
};




int main(void)
{
  
  
   Menu GameMenu;
   FootballField OSUField;
   Game TheGame;
   int g, totalRun = 1, playRun = 1, menuRun, menuSel, doDraw, gameComp, diffSel, win;
   float x_coord, y_coord, temp, gmStrtTim, drwStrtTim, dummyx, dummyy;
   TheGame.minGameTime = 99999999;
   TheGame.highScore = 0;
   LCD.SetOrientation( FEHLCD::East ); // This line flips the orientation of the printing
  
   /*
    * This loop completes the while loop requirement.
    * */
  
   while(totalRun)
   {
      
       do
       {
           if (doDraw)
           {
               GameMenu.DrawMain(); // this draws the main menu
           }
           doDraw = 1;
           menuSel = GameMenu.MainTouch(); // checks what button is touched on the menu
           //when Start is clicked
           if (menuSel == 1)
           {
               srand(TimeNow()); //getting a random time
               GameMenu.DrawDiff();
               diffSel = GameMenu.DiffTouch();
              
               /*
                * Here the required do while loop is used.
                * */
              
               do
               {
                  
                   /*
                    * This switch case structure meets the requirement for this
                    * type of structure.
                    * */
                  
                   switch (diffSel) // this switch case uses the selected difficulty
                   {
                   case 1:
                      
                       OSUField.DrawField(); // this draws the field
                       win = TheGame.gameStartEasy();
                       gameComp = 1;
                       // check if this game beats the record stats, if so replace the record
                       if (TheGame.score > TheGame.highScore)
                       {
                           TheGame.highScore = TheGame.score;
                       }
                       if (TheGame.gameTime < TheGame.minGameTime)
                       {
                           TheGame.minGameTime = TheGame.gameTime;
                       }
                       if (TheGame.completions > TheGame.maxCompletions)
                       {
                           TheGame.maxCompletions = TheGame.completions;
                       }
                       break;
                   case 2:
                      
                       OSUField.DrawField(); // in case of medium diff draw the field
                       TheGame.gameStartMedium();
                       gameComp = 1;
                       //checking if current stat beats record stat
                       if (TheGame.score > TheGame.highScore)
                       {
                           TheGame.highScore = TheGame.score;
                       }
                       if (TheGame.gameTime < TheGame.minGameTime)
                       {
                           TheGame.minGameTime = TheGame.gameTime;
                       }
                       if (TheGame.completions > TheGame.maxCompletions)
                       {
                           TheGame.maxCompletions = TheGame.completions;
                       }
                       break;
                   case 3:
                      
                       OSUField.DrawField();
                       TheGame.gameStartHard();
                       gameComp = 1;
                       //checking if stat beats current stat
                       if (TheGame.score > TheGame.highScore)
                       {
                           TheGame.highScore = TheGame.score;
                       }
                       if (TheGame.gameTime < TheGame.minGameTime)
                       {
                           TheGame.minGameTime = TheGame.gameTime;
                       }
                       if (TheGame.completions > TheGame.maxCompletions)
                       {
                           TheGame.maxCompletions = TheGame.completions;
                       }
                       break;
                   case 0:
                       gameComp = 1;
                   }
               } while (!gameComp);
              
              
           }
           //Instructions is clicked
           //displaying the instructions screen below
           else if (menuSel == 2)
           {
               LCD.Clear( DARKGRAY );
               LCD.WriteLine("   INSTRUCTIONS");
               LCD.WriteLine(" ");
               LCD.WriteLine("As the game starts");
               LCD.WriteLine("Tap OSU players");
               LCD.WriteLine("to complete passes");
               LCD.WriteLine("and gain yardage");
               LCD.WriteLine("Get a first down");
               LCD.WriteLine("with 10 passing yards");
               LCD.WriteLine("4 1st downs to score a");
               LCD.WriteLine("touchdown and win");
               LCD.WriteLine(" ");
               LCD.WriteLine(" -Tap to Continue-");
               while(!LCD.Touch(&dummyx,&dummyy));
               while(LCD.Touch(&dummyx,&dummyy));
               LCD.WriteLine("The first down marker");
               LCD.WriteLine("will move up the field");
               LCD.WriteLine("on the left hand side");
               LCD.WriteLine("The down is displayed");
               LCD.WriteLine("in the upper right");
               LCD.WriteLine("4th down is your last");
               LCD.WriteLine("chance for a 1st down");
               LCD.WriteLine("or lose the ball + the game");
               LCD.WriteLine(" ");
               LCD.WriteLine(" -Tap to Continue-");
               while(!LCD.Touch(&dummyx,&dummyy));
               while(LCD.Touch(&dummyx,&dummyy));
               LCD.WriteLine("Avoid tapping");
               LCD.WriteLine("Michigan Players");
               LCD.WriteLine("or your pass will be");
               LCD.WriteLine("blocked or  intercepted");
               LCD.WriteLine(" ");
               LCD.WriteLine("good luck");
               LCD.WriteLine("and go Bucks!");
               LCD.WriteLine(" -Tap to Exit-");
               while(!LCD.Touch(&dummyx,&dummyy));
               while(LCD.Touch(&dummyx,&dummyy));
           }
           //Statistics is clicked
           //displaying the statistic screen
           else if (menuSel == 3)
           {
               LCD.Clear( DARKGRAY );
               LCD.WriteLine("RECORD STATISTICS:");
               LCD.Write("High Score: ");
               LCD.WriteLine(TheGame.highScore);
               LCD.Write("Low Time: ");
               LCD.WriteLine(TheGame.minGameTime);
               LCD.Write("Most Passes: ");
               LCD.WriteLine(TheGame.maxCompletions);
               LCD.WriteLine(" ");
               LCD.WriteLine("LAST GAME'S STATS:");
               LCD.Write("Score: ");
               LCD.WriteLine(TheGame.score);
               LCD.Write("Game Time: ");
               LCD.WriteLine(TheGame.gameTime);
               LCD.Write("Completions: ");
               LCD.WriteLine(TheGame.completions);
               LCD.WriteLine(" ");
               LCD.WriteLine(" ");
               LCD.Write("  -Tap To Return-");
               while(!LCD.Touch(&dummyx,&dummyy));
               while(LCD.Touch(&dummyx,&dummyy));
           }
           //Clear Stats is clicked
           //clears the statistics
           else if (menuSel == 4)
           {
               LCD.Clear( DARKGRAY );
               TheGame.highScore = 0;
               TheGame.score = 0;
               TheGame.maxCompletions = 0;
               TheGame.completions = 0;
               TheGame.minGameTime = 0;
               TheGame.gameTime = 0;
               LCD.Write("Statistics Cleared!");
               LCD.WriteLine("");
               LCD.WriteLine("");
               LCD.Write("  -Tap To Return-");
               while(!LCD.Touch(&dummyx,&dummyy));
               while(LCD.Touch(&dummyx,&dummyy));
           }
           //Credits is clicked
           //displays the credits screen
           else if (menuSel == 5)
           {
               LCD.Clear( DARKGRAY );
               LCD.WriteLine("       CREDITS");
               LCD.WriteLine(" GAME CREATED BY");
               LCD.WriteLine(" Kamren Zirger");
               LCD.WriteLine(" and");
               LCD.WriteLine(" Brian Lesko");
               LCD.WriteLine(" ");
               LCD.WriteLine(" FEH: Fall ");
               LCD.WriteLine(" Ohio State");
               LCD.WriteLine(" ");
               LCD.WriteLine(" Special Thanks to");
               LCD.WriteLine(" Dip Patel");
               LCD.WriteLine(" Jared Mitten");
               LCD.WriteLine(" Dr. Parke");
               LCD.WriteLine(" ");
               LCD.WriteLine("  -Tap to Exit-");
               while(!LCD.Touch(&dummyx,&dummyy));
               while(LCD.Touch(&dummyx,&dummyy));
              
           }
           //Quit is clicked
           //quits the game
           else if (menuSel == 6)
           {
               menuRun = 0;
               totalRun = 0;
           }
           //Click was not on a button
           //returns the user to the menu on difficulty screen if a button is not pressed
           else
           {
               menuRun = 1;
               doDraw = 0;
              
           }
          
       } while(menuRun);
       LCD.Clear( BLACK );
   }
}
