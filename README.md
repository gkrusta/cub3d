# cub3D

> This project is inspired by the classic game Wolfenstein 3D, which is considered to be the first true FPS in gaming history.

- `cub3D` offers a modern twist on this classic, utilizing raycasting technology to create a dynamic 3D labyrinth exploration experience.

<div align="center">
  <img src="images/cub3d2.png" alt="Standard Version">
</div>

## Controls

- **Arrow Keys**:
  - **Left/Right**: Rotate the view left or right.
  - **Up/Down**: Move forward or backward.

- **WASD Keys**:
  - **W**: Move forward.
  - **S**: Move backward.
  - **A**: Slide left.
  - **D**: Slide right.

### Standard Version
- 3D rendering of a labyrinth using raycasting techniques.
- Simple collision detection to prevent walking through walls.
- Ability to load different maps from file.
- The unique textures used in the game were custom-made by me using [Piskel](https://www.piskelapp.com/)

<div align="center">
  <img src="images/cub3d1.png" alt="Standard Version">
</div>

### Bonus Features
- **Mini-Map**: A top-down view that shows the layout of the labyrinth, your current position, and your viewing direction. This is especially useful for navigation and strategy planning.
- **Enhanced Collision**: Unlike many traditional raycasting games where the player can get stuck on walls, `cub3D` implements an advanced collision algorithm.Even when colliding with a wall, the player can continue moving along the wall smoothly without getting stuck. This makes for a more fluid and realistic movement experience.

<div align="center">
  <img src="images/cub3d3.png" alt="Bonus Version">
</div>

## Installation

1. **Clone the Repository**:

```bash
git clone https://github.com/gkrusta/cub3d cub3d

```
2. **Build the Project**:
Run `make` to build the standard version or `make bonus` for the version with bonus features.

```bash
cd cub3d && make
```

3. **Run the Game**:

```bash
./cub3d map.cub or /cub3d_bonus map.cub
```

### My Teammate => [Victor](https://github.com/vnaslund-19)
