# !!!BETA ACCESS!!! Ship Battle 3D! THE NEW HOT CRAZE REPLACING Ship Battle 2D

This assignment builds on the Island Defence game from assignment one and makes it 3D, and slightly changes the gameplay. A player controls the island cannon shooting at enemy boats which are shooting at the island. The score is the number of boats destroyed before being overwhelmed - the island always loses, so it is a kind of survival game. The boats should be controlled by a simple AI - they spawn a distance from the island and then navigate towards the island.

All the elements from assignment 1 are again required: water, increasing/decreasing tesselation, boats rocking and bobbing on the water, wireframe/filled rendering modes, normal and tangent visualisation, cannonball projectile motion trajectory visualisation, anti-missile defence for boat and island, animation toggle, cooldown, transparent water, health bars, arrays to store vertices and indices, OSD including frame rate and frame time, game over.

More complicated and realistic water surfaces can be implemented using sums of sine waves. 

## Features
In addition to the features from assignment 1:

* 3D: water, boats, island, cannon
* camera, scene viewer
* lighting
* texture mapping
* skybox


## Features Not Implemented
[BLANK]


## Controls

*   Esc - Quits the game

### Display Controls
*   +/= - Increases the tesselation
*   '-' - Decreases the tesselation
*   Shift + T - Toggles the textures
*   Shift + N - Toggles the SIN wave normals
*   Shift + W - Toggles Pollygon Mode
*   Shift + G - Toggles all game animations
*   Shift + O - Toggles OSD
*   Shift + L - Toggles Lighting

### Island
[TO IMPLEMENT]

## Authors

* **Joseph Garner** - *Completed Work* - [s3550293](https://github.com/s3550293)

## Marking Guide

This is a guide only, and may change.

PA: basic assignment with boats bobbing and rocking on 3D water and and 3D island with lighting and scene viewer/camera

CR: boats spawning with simple AI directing them towards the island, firing cannonballs with projectile motion as well as an island with a cannon able to similarly fire a cannon.

DI: projectile path display, collision detection, texturing

HD: polished gameplay, multiple missiles, cooldown, rendering, OSD, missle defence, complex water, better boat AI, use of arrays to store vertex data

Note: Quality of implementation, including code, and fine detail matter and will be taken into account e.g. correctly firing cannon balls from end of turret rather than centre of boat  