# PingPong
A PingPong game made with UE4
A Pong game made with UE4.

This is a basic pingpong game.

How to Use the Project:

The C++ Classes: 

    1)GoalZone - represents the zone where if ball overlap the score will be added for current player
    2)MovingBall - a ball which fly around the map and overlapping with objects
    3)Wall - simple wall
    4)PlayerPaddle - paddle possesed by a player. Also overlapped mechanics are here.
    5)PingPongGameModeBase - game mode where stores all the info about scoring. Game starts from here.

The Blueprint classes: 
    1)BP_Paddle - Child class of PlayerPaddle.
    2)AIPaddle - Child class of BP_Paddle. Represent an simple AI who follows the ball.
    3)BP_MovingBall - Child class of MovingBall.
    4)BP_Wall - Child class of BP_Wall.
    5)BP_GoalZone - Child class of GoalZone.
    6)BP_MenuController - Creating Main Menu Widget
    7)BP_PingPongController - Creating InGame Widget