# Snake-And-Ladder-1-Player

This is a 1 player Snake and ladder game developed in C++ language. It uses the console co-ordinates to display the board, the numbers on the board, the ladders 

and the snake on console. The code randomly generates the numbers on the dice and calculates as well as displays the new position of the player on the board. 

While playing the game if the user encounters ladder then it automatically moves up and if encounters the snake then it moves down.

These are the following rules of the game:

  **1: THE YELLOW COLORED BLOCKS ARE THE LADDER**

  **2: THE BROWN COLORED BLOCKS ARE THE SNAKE**
  
  **3: YOU ARE IN GREEN COLOR**
  
  **4: PRESS 1 AND ENTER TO START THE GAME**
  
  **5: PRESS X AND ENTER TO END THE GAME**
  
The functions used are:
  
  _1: board(): It draws the board on the console at appropriate co-ordinates._
  
  _2: snake(): It draws 3 snakes of differrent sizes on the console at appropriate co-ordinates._
  
  _3: call_snake(): It calls the above snake function and calculates as well as passes the starting value of x and y for the snake_
  
  _4: board_number(): It displays the numbers on the board._
  
  _5: ladder_color(): It displays the 3 ladders of different sizes on the console and also fills them with YELLOW color._
  
 _6: ladder(): It calls the above ladder function and calculates as well as passes the starting value of x and y for the ladder._
  
  _7: ladder_move(): It returns 1 if the player encounters the ladder and also move the player at the top of ladder and 0 if player does not encounters ladder._
  
  _8: snake_bite(): It returns  1 if the player encounters the snake and also move the player at the end of the snake and 0 if player does not encounters snake._
  
  _9: cal_y(): It calculates the value of y co-ordinates for the movement of player._
  
  _10: cal_prev(): It calculates the position of the player depending on the previous position and dice value._
  
  _11: winner(): It return 1 if the player reaches 100 i.e. if player wins the game and 0 if not._
  
  _12: movement(): It moves the player from previous position to new position._
 
  Language used: C++
  
  Plateform: TURBO CPP
  
  Header Files: iostream, graphics, conio, dos
  
  Below is the screenshots of the project:

![Screenshot (257)](https://user-images.githubusercontent.com/68001066/133897047-dfed9d6a-6a43-42fb-9aae-5b8583c1b08b.png)

![Screenshot (258)](https://user-images.githubusercontent.com/68001066/133897051-378eb46a-79cb-41ac-a2be-66ff29eaf058.png)

![Screenshot (261)](https://user-images.githubusercontent.com/68001066/133897055-cca87c4c-1be5-4568-a3d0-0e15c2429df3.png)

![Screenshot (262)](https://user-images.githubusercontent.com/68001066/133897057-9b692a84-e9dc-4aca-a653-1289c556dfff.png)



