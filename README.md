# Snake Game - README

## Overview
This project is a console-based Snake game implemented in C++. 
The goal is to control the snake, avoid collisions with walls and itself, 
and collect food to achieve the highest possible score. The game ends when the snake collides
with either one of the walls or itself.

## Features
- ASCII-based graphical representation of the game.
- Control the snake using keyboard keys (`w`, `a`, `s`, `d`, 0 to end the game).
- Random food generation on the board.
- Collision detection:
  - Wall collision.
  - Self-collision.
- Displays the current score in real-time.

## Requirements
- **Operating System:** Windows 10 or newer
- **Compiler/IDE:** Visual Studio 2022
- **Additional Requirements:** "Desktop development with C++" workload installed in Visual Studio.

## How to Run

### Step 1: Clone or Download the Project
1. Clone the repository or download the `.cpp` file to your local machine.

### Step 2: Open the Project in Visual Studio
1. Open Visual Studio 2022.
2. Create a new project:
   - Choose **Console App (C++)**.
   - Enter a name for the project (e.g., `SnakeGame`).
3. Replace the default content of `Source.cpp` with the code from the downloaded `snake.cpp` file.
4. Run with CTRL+f5


## Game Rules
1. **Controls:**
   - `W`: Move up
   - `A`: Move left
   - `S`: Move down
   - `D`: Move right
   - `X`: End the game
2. Avoid collisions with walls and your own body.
3. Collect food (`*`) to increase your score and snake length.
4. The game ends upon collision with a wall or the snake’s body.

## Project Structure
- **SnakeGame:** The main class that implements the game logic.
- **Pixel:** Base class for different pixel types in the game (e.g., wall, food, snake body, snake head).
- **Exceptions:**
  - `HitTheWallEx`: Indicates a collision with a wall.
  - `SelfCollisionEx`: Indicates a collision with the snake’s body.

## Customization
- You can adjust the game board dimensions by modifying the `sirina` and `visina` variables in the `SnakeGame` class.
- To change the game speed, adjust the value in the `Sleep()` function in the `Run()` method.

## Troubleshooting
- **Problem:** "`_getch()` function not recognized."
  - **Solution:** Ensure the `<conio.h>` header file is included.
- **Problem:** "Code doesn't work on Linux or macOS."
  - **Solution:** The code is designed for Windows and uses platform-specific libraries such as `<windows.h>`.
- **Problem:** "`.exe` file not found."
  - **Solution:**
    1. Verify there are no build errors.
    2. Check the output directory in **Project Properties**:
       - Right-click on the project > **Properties**.
       - Navigate to **Configuration Properties > General**.
       - Ensure the **Output Directory** is correct.
    3. Rebuild the project.
