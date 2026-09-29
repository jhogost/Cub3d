*This project has been created as part of the 42 curriculum by jbayet, hhervieu.*

[![jbayet's 42 stats](https://42cv.dev/api/badge/cmmevnk9g0006n286hxhjp6au/stats?cursusId=21&coalitionId=piscine)](https://42cv.dev)
[![hhervieu's 42 stats](https://42cv.dev/api/badge/cmmkqicmn0000pkpd0wgzlibp/stats?cursusId=21&coalitionId=48)](https://42cv.dev)

# cub3D

## Description

**cub3D** is a 42 school project that challenges students to build a 3D graphical engine from scratch. Inspired by the world-famous 1992 game *Wolfenstein 3D*, the engine uses the **Raycasting** technique to simulate a three-dimensional perspective within a two-dimensional grid map.

The primary objective of this project is to explore fundamental concepts in computer graphics, such as window management, event handling (keyboard and mouse inputs), texture mapping, and mathematical applications (specifically trigonometry and linear algebra). The entire engine is written in **C** and utilizes the [**MiniLibX**](https://github.com/42paris/minilibx-linux) (a simple 2D graphics library).

### Key Features
* **Smooth 3D Rendering:** Fast and responsive raycasting engine mimicking true 3D perspective.
* **Texture Mapping:** Different textures applied to walls based on their cardinal orientation (North, South, East, West).
* **Environment Customization:** Configurable colors for both floor and ceiling.
* **Collision Detection:** Complete handling of wall collisions to prevent the player from passing through walls.
* **Strict Map Parsing:** Validation of the `.cub` configuration file, ensuring it is properly enclosed by walls, contains no invalid characters, and includes a single valid player starting orientation.

## Instructions

### Prerequisites

To compile and run this project, you need standard development tools (`gcc`, `make`) and the [**MiniLibX**](https://github.com/42paris/minilibx-linux) library dependencies installed on your system, named "minilibx-linux".

### Compilation

You can compile the project using the provided `Makefile`. Open your terminal at the root of the repository and run:

```bash
make
```

This will compile the source files and generate the cub3D executable.

Other Available Rules:

```bash
make clean
```

Removes the temporary object files (.o).

```bash
make fclean
```

Removes the object files and the compiled cub3D executable.

```bash
make re
```

Recompiles the entire project from scratch.
### Execution

The executable requires a single argument: the path to a map file with a .cub extension.

```bash
./cub3D mandatory/maps/subject.cub
```

### Controls

| Key | Action|
| :- | :- |
|  W  |  Move Forward |
| S | Move Backward |
| A | Strafe Left |
| D | Strafe Right |
| Right Arrow | Rotate Camera |
| Left Arrow | Rotate Camera |
| ESC | Window Close |
| Close Button | Window Close |

## Resources

- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx): Official and community-contributed guides for window management and pixel manipulation using the MiniLibX library.
- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html): The fundamental guide to understanding the mathematics and logic behind raycasting engines (Lode's Computer Graphics Tutorial).
- [Wolfenstein 3D Internals](https://www.scribd.com/document/444631412/Game-Engine-Black-Book-Wolfenstein-3D-pdf): Historic documentation regarding early game engine optimizations and layout.

## AI Usage

AI was used to help us write this README, doing a task such as correcting our spelling mistakes or confusing sentences.

# Bonus

## Description
As Gamers, we've been quite hyped to make our own game. So, in addition to the regular bonuses, we did some sort of gameplay. Seek at the bottom of the README to know everything.
The regular bonuses were :

- Wall collisions (Which we ended up doing for the regular project)
- A Minimap system (Also Indicating things, seek at the bottom again)
- Doors which can open and close
- Animated Sprites
- Rotating the camera with the mouse

You'll soon notice that cub3d got all of his sprites and textures inspired by the 42 Paris Campus and the v3 Intra. Starting from the white walls, the windows, paintings, alcoves, lockers, computer logo, floors/floors layers and Moulinette herself !

### Compilation

You can compile the bonus using the provided `Makefile`. Open your terminal at the root of the repository and run:

```bash
make bonus
```

This will compile the source files and generate the bonus cub3D executable. 

Other Available Rules:

```bash
make clean
```

Removes the temporary object files (.o).

```bash
make fclean
```

Removes the object files and the compiled bonus cub3D executable.

### Execution

The executable doesn't requires an argument: but can take the path to a map file with a .cub extension.

```bash
./cub3D_bonus bonus/maps/map_stage_0.cub 
```
Is an example to load the first stage

### Bonus Controls

| Key | Action|
| :- | :- |
|  Mouse moving  |  Rotate Camera |
| L | Lock or Unlock the Camera Rotation for the mouse |
| E | Interact |

yes, we know our program have a leak with mlx_mouse_hide, but we cannot fix it without modifying the minilibx. Here is the Fix using X11 to fix that leak
https://github.com/42paris/minilibx-linux/issues/48

### Bonus Content

Spoilers Alert, if you want to discover the game first, now's the time to play it.

Rules are simple to go to the next stage, you need to interact with the computers and find the good one that will indicate you the correct elevator door. If you get into the wrong door, you simply get black holed and have to start again.

Here's a list of additional content that we did for fun:

- A minimap that indicates you a few things in real-time
- Doors are sliding
- HUD that indicates your floor (stage)
- FPS at the top right of your screen
- Moulinette that you can interact for ??? and that meows
- A secret puzzle to finish the last stage