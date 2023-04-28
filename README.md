# Computational Geometry Algorithms

Algorithms implemented in C++ for the first half Advanced Algorithms course, centered around computational geometry algorithms.



## Tabel of contents


## Laboratory 1
In the first laboratory I approached the problems:
* [Orientation Test](https://cms.fmi.unibuc.ro/problem/l1p1)
* [Roby](https://cms.fmi.unibuc.ro/problem/l1p2)
* [Convex Cover](https://cms.fmi.unibuc.ro/problem/l1p3)

### Orientation Test
You are given 3 points on a plane: P, Q, R, with the coordinates P = (xP, yP), Q = (xQ, yQ) and R = (xR, yR). Determine the position of the R point relative to the line determined by points P and Q, using an orientation test.

#### Input:
The input will consist of an integer t, representing the number of tests, followed by t lines, each with 6 integers, representing the coordinates of the P, Q, and R points.

#### Output:
For each test you will print a line featuring a message coresponding to the R point:
* LEFT - if the R point is situated to the left of the (PQ) line
* RIGHT - if the R point is situated to the right of the (PQ) line
* TOUCH - if the R point is situated on the (PQ) line

### Roby
Roby is a vacuum-robot which must clean a room. The robot starts from a starting point P1 and follows a path determined by the set of points P1, P2, ..., Pn, P1. Each Pi point is describes by a set a of coordinates (xi, yi). In each point Pi, the robot must either make a left turn, a right turn, or keep going forwards. At the end, besides cleaning the room, Roby must indicate the number of total left turns, right turns and the number of situations where he stayed on the same line.

#### Input:
The input will be read from the keyboard. The input contains an unsigned integer n, and n lines featuring the pairs of integers representing the coordinates of the Pi points (i=0..n), separated by a space.

#### Output:
The output will be printed on a single line, featuring the total number of left turns, the total number of right turns, and the total number of situations where the robot remained on the same line, all separated by a space.

### Convex Cover:
A polygon P1P2...PnP1 is called _starred_ if there exists a point M inside of it so that no matter how a point X is chosen on the sides of the polygon or on one of its vertices, the [MX] segment is contained entirely inside of the polygon.
Given a starred polygon, you must implement an algorithm with a liniar time complexity which must find the conver cover of a starred polygon.

#### Input:
The input will be read from the keyboard. The input contains an integer n, representing the number of vertices of the polygon, followed by n lines containing pairs of integers (xi, yi), separated by a space, representing the coordinates of the respective Pi point, traveled in trigonometric order.

#### Output:
The output will contain an integer k, representing the number of vertices of the convex cover of the set {P1, P2, ..., Pn}, followed by k pairs of integers, on different lines, representing the coordinates of said vertices, traveled, once again, in trigonometric order.
