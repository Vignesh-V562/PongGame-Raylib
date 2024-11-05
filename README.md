# PongGame-Raylib

# Vignesh's Pong Game

A simple Pong game built using the Raylib library in C. This game features a player paddle, a CPU-controlled paddle, and a ball that bounces across the screen. The goal is to score points by getting the ball past the opposing paddle.

## Features

- Player vs. CPU Pong game mechanics.
- Ball bouncing physics with randomized start direction.
- Dynamic paddle control for both player and CPU.
- Simple scoring system.

## Getting Started

### Prerequisites

- **Raylib**: Install the Raylib library to compile and run this game. You can download it from [Raylib's official website](https://www.raylib.com/).

### Installing Raylib

If you are using Linux or MacOS, you can install Raylib with:
bash
On Ubuntu or Debian-based systems
sudo apt install libraylib-dev

### Compiling the Game
- After installing Raylib, compile the game using gcc or any C compiler that supports Raylib.
gcc pong_game.c -o pong_game -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./pong_game

### Controls
Up Arrow: Move player paddle up.
Down Arrow: Move player paddle down.

### How to Play
- The goal is to score by getting the ball past the CPU paddle on the left side of the screen.
- Control the player paddle on the right using the arrow keys to block the ball from passing.
- Each time the ball goes past a paddle, the opposing player scores a point.
- The ball resets to the center after each score with a random direction.

### Game Structure
Ball: A struct representing the game ball's position, speed, and movement.
Paddle: A struct representing both the player and CPU paddles, with position and speed controls.

### Functions:
Draw(Ball b): Draws the ball on the screen.
ResetBall(Ball* ball): Resets the ball to the center after scoring.
Update(Ball* b): Updates the ball's position, including collision detection with screen boundaries.
DrawPaddle(Paddle p): Draws a paddle on the screen.
UpdatePaddle(Paddle* p): Updates player paddle movement based on keyboard input.
UpdateCpu(Paddle* cpu, int ball_y): Updates CPU paddle movement based on ball position.

### Scoring
The player's score is shown on the right, and the CPU's score is on the left.
The first player to reach a specified score limit (not implemented in the current version) would win the game.

License
This project is licensed under the MIT License.

Acknowledgments
Thanks to Raylib for providing a lightweight and easy-to-use library for game development in C.
