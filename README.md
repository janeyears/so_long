# so_long

so_long is a 2D game project from the Hive curriculum that involves creating a simple game using the MLX42 graphics library. The objective is to navigate a player through a map, collecting all items and reaching the exit, while adhering to specific constraints and requirements.

## 🚀 Project Overview

The goal of so_long is to develop a small 2D game where a player moves through a map, collects collectibles, and exits the map. This project enhances understanding of:

- Graphics rendering with MLX42
- Event handling and user input
- Map parsing and validation
- Game logic and state management

## 📁 Project Structure

### ✅ Mandatory Part

- Read and parse a map file with the `.ber` extension.
- Display the map in a window using MLX42.
- Allow the player to move using `W`, `A`, `S`, and `D` keys.
- Prevent the player from moving through walls.
- Collect all collectibles before exiting.
- Display the number of movements in the shell.
- Close the game when the player reaches the exit, presses `ESC`, or clicks the window's close button.

## 🗺️ Map Specifications

- The map must be rectangular and surrounded by walls.
- It must contain:
  - `1` for walls
  - `0` for empty spaces
  - `C` for collectibles (at least one)
  - `E` for the exit
  - `P` for the player's starting position (only one)

## 🔧 Compilation & Usage

The project includes a `Makefile` for building the game.

./so_long maps/normal_map.ber

## 🎮 Controls

- W / A / S / D: Move up / left / down / right
- ESC: Exit the game

## 🧠 What I Learned

- Utilizing the MLX42 library for graphics rendering
- Handling user input and events in a graphical window
- Parsing and validating game maps from files
- Implementing game mechanics and logic
