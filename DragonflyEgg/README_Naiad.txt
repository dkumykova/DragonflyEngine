DragonflyNaiad README
Diana Kumykova
dkumykova@wpi.edu

Developed for Windows 10 in Visual Studio 2019; no makefile necessary.
To run project load into VS2019 and run on platform x64 on Debug.

Implemented 2 test objects: Bee and ExampleObject.

What to look for in log file - test results:

-each manager should have a start up + shut down
-mouse movement events are logged
-mouse click and whether it's right or left is logged
-escape is logged and causes the program to stop (calls GM.shutdown())
-1 object of each type, Bee and ExampleObject, is created with their own
	strings, color, and altitude
	-the altitude of Bee changes 2-3 loops within the game loop and gets logged; 
	causes the Bee object to "disappear"
-Object constructors + destructors called, vector positions set and reset on certain loops
-Each object move with its velocity
-step events and collision are passed to each object; log statement for each case
-out of bounds should be called once Bee leaves screen.
-objects marked for deletion near end of game run - last loop, added to list and
	printed out
*probably some other stuff that I can't remember right now

Things to watch out for:
-the movement of ExampleObject is a little inconsistent
	-issue with velocity logic
-I accidentally read the wrong chapter and began the logic for collision boxes
but none of it is complete or implemented; please disregard for now.

-git messed up and deleted all my collision and movement code so that won't work now
i guess
