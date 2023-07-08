# 2D Steady State Heat Equation in a Rectangle
**HEATED\_PLATE** is a C++ program which solves the steady state heat
equation in a 2D rectangular region, and is intended as a starting point
for implementing an OpenMP parallel version.

The final estimate of the solution is written to a file.

The sequential version of this program needs approximately 18/epsilon
iterations to complete.

The physical region, and the boundary conditions, are suggested by this
diagram:

                       W = 0
                 +------------------+
                 |                  |
        W = 100  |                  | W = 100
                 |                  |
                 +------------------+
                       W = 100
          

The region is covered with a grid of M by N nodes, and an N by N array W
is used to record the temperature. The correspondence between array
indices and locations in the region is suggested by giving the indices
of the four corners:

                      I = 0
              [0][0]-------------[0][N-1]
                 |                  |
          J = 0  |                  |  J = N-1
                 |                  |
            [M-1][0]-----------[M-1][N-1]
                      I = M-1
          

The steady state solution to the discrete heat equation satisfies the
following condition at an interior grid point:

> W\[Central\] = (1/4) \* ( W\[North\] + W\[South\] + W\[East\] +
> W\[West\] )

where "Central" is the index of the grid point, "North" is the index of
its immediate neighbor to the "north", and so on.

Given an approximate solution of the steady state heat equation, a
"better" solution is given by replacing each interior point by the
average of its 4 neighbors - in other words, by using the condition as
an ASSIGNMENT statement:

> W\[Central\] &lt;= (1/4) \* ( W\[North\] + W\[South\] + W\[East\] +
> W\[West\] )

If this process is repeated often enough, the difference between
successive estimates of the solution will go to zero.

This program carries out such an iteration, using a tolerance specified
by the user, and writes the final estimate of the solution to a file.

Usage of the application: `heatedplate use_case`\
&nbsp;`heatedplate 0` (tiny)\
&nbsp;`heatedplate 1` (small)\
&nbsp;`heatedplate 2` (large)

## STEP 6:  Presentation of your project (10%)

Prepare presentation in form of slides (pptx, pdf). The slides should address all topics requested above.

The presentation (pdf) as well as all other modifications, and outputs push to your git repository.
