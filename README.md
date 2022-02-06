# black_jack

Simple console game black_jack for Windows.

My first project on github 

## Compilation

Project is compiled in QT Creator 6.0.2 (QT 6.2.2 for qmake) with MinGW 9.0.0.

Build steps: 
1. qmake.exe black_jack.pro
2. mingw32-make.exe -j8
3. Run black_jack.exe

## View of the game 
![Screenshot](https://github.com/miloann/black_jack/blob/main/pictures/black_jack_screenshot.PNG)

## Rules

Each player gets 2 cards at the beginn and attempts to win by getting a count as close to 21 as possible, without going over 21.
At each step, the player chooses whether to get a card or stop the game.

- Game for 2 Players

The players get cards one by one.

- Game with computer

If player stop the game, computer can make a choice of the next step. 

 