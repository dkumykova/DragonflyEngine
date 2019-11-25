DragonflyEgg README
Diana Kumykova
dkumykova@wpi.edu

Developed for Windows 10 in Visual Studio 2019; no makefile necessary.
To run project load into VS2019 and run on platform x64 on Debug.

In addition to previous tests, added in:

Bee and Example object sprites and animations loaded.
Starting music loaded and played, as well as additional music.
Bee on destroyed sound played, all sounds loaded in beginning as well.
Example Object (player controlled) movement based on keyboard input still there.

Around 50 loops in the view is changed to only draw a 20 by 20 square, which should
only show Bee object; at 80 loops, the view is changed back and now follows 
the first Bee to appear.

Event outs are still being generated, as well as collisions using boxes now;
different collision scenarios can be simulated by controlling the player
character to collide sideways, head-on and other ways with bees; collision
output is in log file.

There is an option to draw an approximation of the collision boxes of each object
in the object draw method; just uncomment the lines of code that draw variables
topleft, topright, bottomleft, and bottomright
	-this can be used to give further assurance that collision is working for
the object boxes correctly.
Another way to test different collision angles is to adjust the starting position
of Bee with id=2 in the Bee.cpp file; changing the X spawn position can allow
for easy collisions without the player having to move very far for testing.