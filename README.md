# Cub3d, the raycaster
<br>

Ever wondered how those classic FPS games like Wolfenstein 3D pulled off those cool 3D graphics? It wasn't actually magic (though it might have felt like it at the time). It's a clever technique called raycasting, which is what we've used to build our own simplified version of Wolfenstein, **cub3d**!
<br><br>

### Cool, but what's the deal with raycasting?

Raycasting is a technique used in video games to create a 3D effect from a 2D map. Imagine you are standing in a maze. Raycasting works by shooting out lines, like rays of light, from your eyes in all directions. When a ray hits a wall, the game calculates how far away the wall is. The farther away the wall, the smaller it will appear on the screen. By doing this, we create a sense of depth and realism in a 2D world.

<p align="center">
  <br>
  <img src="https://github.com/jlbernardo/cub3d/assets/56981667/3f700cf3-38ce-4436-9970-12f43af70da4" />
</p>

Raycasters often use an algorithm called DDA (Digital Differential Analysis) to determine which cells of the map a ray intersects. DDA is particularly useful for working with grid-based maps, which is a common approach in raycasting. Explore in depth how it is done by reading [this article](https://lodev.org/cgtutor/raycasting.html) (that guided our journey) or watching [this video](https://youtu.be/gYRrGTC7GtA?si=9brMIv_Qib9LyMq6).
<br><br>

## How to play
Download the repository using one of the formats below and type `make run` at the root of the project.

If you want to explore different maps, use `./cub3d phases/[name of the map].cub` and choose one of the valid maps (or use one you built yourself following that same structure or modifying one of the existing valid maps).

#### ssh
```ssh
git clone git@github.com:jlbernardo/cub3d.git
```
#### https
```bash
git clone https://github.com/jlbernardo/cub3d.git
```
#### github cli (gh)
```bash
gh repo clone jlbernardo/cub3d
```

### Controls

| Key | Action |
| --- | --- |
| `WASD` | Moves the player in the fours directions: front, back, left and right |
| `space` | Opens doors, but make sure you are close enough to them |
| `←` `→` | Moves the camera left and right so you can look around |
| `mouse` | Also moves the camera and you can click to shoot |
