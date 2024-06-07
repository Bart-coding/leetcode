# 735. Asteroid Collision
* Given an array "asteroids", of integers representing asteroids in a row, you should calculate which asteroids remains after possible collisions
* Positive integers represents asteroids flying right nad negative integers represents astereoids flying left
* When left-directed asteroid (e.g. with index 4) meets right-directed asteroid (e.g. with index 2), they colide
* Left-directed asteroid cannot collide with asteroid on the right (with higher index)
* Absolute value of integer represents a size of an astereoid
* After collision, asteroid with smaller size explodes
* If two colliding asteroids has the same size, they both explode
* Asteroid after collision still can collide with the next asteroids in its direction