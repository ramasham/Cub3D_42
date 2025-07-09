# 🕹️ Cub3D

<p align="center">
  <img src="https://github.com/user-attachments/assets/f6a32b7b-3b91-4875-97f5-afe998db44e5" width="600" />
</p>

**Cub3D** is a 3D graphical project developed as part of the curriculum at [42 School](https://42.fr/).  
It recreates a classic raycasting engine like that in *Wolfenstein 3D*, transforming a simple 2D map into a real-time 3D first-person experience — built entirely in C using the MiniLibX graphics library.

> 🛠️ **Technologies:** C, MiniLibX (X11), Math (Raycasting, Vectors), Linux

---

## 🚀 Features

- 🔭 **Raycasting Engine**
  - DDA (Digital Differential Analyzer) algorithm to detect wall collisions
  - Perspective projection for depth simulation

- 🧱 **Wall Rendering**
  - Texture support for all directions (North, South, East, West)
  - Accurate texture mapping

- 📜 **Map Parsing & Validation**
  - Parses `.cub` files with textures, floor/ceiling colors, and layout
  - Validates player position, map closure, and identifier correctness

- 👤 **Player Movement**
  - `W`, `A`, `S`, `D` for movement
  - Arrow keys for smooth rotation
  - Collision detection

- 🎨 **Floor & Ceiling Colors**
  - Customizable RGB values from `.cub` file

- 🗺️ **Minimap (Bonus)**
  - Displays player position and field of view
  - Updates in real time

- 🚪 **Doors & Animations (Bonus)**
  - Interactive elements like doors or animated textures

---

## 🧾 File Format Example (`.cub`)
```cub
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

1111111111
1000000001
1000110001
1000N00001
1111111111

NO/SO/WE/EA: Texture paths for walls

F/C: RGB colors for Floor and Ceiling

1: Wall, 0: Empty space

N: Player starting position and direction

```

## 👥 Team
This project was developed as part of the 42 School curriculum by:  
🧑‍💻 [@ramasham](https://github.com/ramasham)  
🧑‍💻 [@sarahayman22](https://github.com/sarahayman22)
