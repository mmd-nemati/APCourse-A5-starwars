# STAR WARS

This repository contains 5th project of UTAP 1400 course. A clone of [Lord of Galaxy](https://gameforge.com/en-US/littlegames/lord-of-galaxy/) game.

- This clone is written in C++ and uses Makefile.
___
To play the game:
1. Make sure you have SDL2 packages installed on your machine. You can see [here](https://github.com/UTAP/RSDL/wiki/Installation).
- **Beware that this package cannot be installed on Ubuntu 21.04 or next versions. It can break your OS!**
3. clone this repo.
```
git clone https://github.com/mmd-nemati/A5-starwars.git
```
3. Go to the repo directory:
```
cd A5
```

4. Make games files:
```
make
```
5. Run the game with given map:
```
./starwars.out map.txt
```
___
You can change the GUI of the game. 
<br> Put your photos inside **/assets/photos** directory. Then inside **gui.cpp** change the address to your own photo. 
