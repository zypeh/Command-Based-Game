# Text-Based-Game

===

### Branches
* "Old" - The first attempt of coding/making this game.

* "Master" - The most stable code of the game. Coded in ~~C#~~ C++.

* "Port" - ~~The C++ port of the game, will merge into master and ultimately replace the C# code with C++ code.~~ </br> Merged into master. Bye, port!

* "C#" - The C# version of the game, obsolete.

===

##About this project branch:

###Why port to C++?
C# takes a huge amount of RAM (3MB > 1MB) as it needs a runtime (it does, when we decided to port CBG to C++, and still does now. We decided that trading memory off for productivity is not feasible, as we want this game to run on as many platforms as possible.)

===

###Build

##Prerequisites
* cmake

##Build
Run these commands at the directory, this make require _cmake_ .
```sh
$ cmake .
$ make
```

###Todos:

- Majority of game logic (importance are sorted ascendingly!)
  * Time system
  * Combat system
  * Weather, maybe?
- Don't know, maybe Pizzas? (delicious)

###Milestone:
- Some game logic:
  * Player status
  * Item system
  * Inventory system(we may revise it later.)
- Handling command history
- Command Line Handling
- GUI
- Shortcut Keys
- About Tab
- Icon Scaling

###Author:
- Koh Jun Dong
- Hoe Hao Cheng
- Zypeh <zypeh.geek@gmail.com>

=======
###### C++ is complex when compared to C#...
