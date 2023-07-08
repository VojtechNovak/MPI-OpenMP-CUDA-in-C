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

## STEP 0: Create git repository (10%)

Your code should be forked from this repository and hosted on code.it4i.cz as a private project with reporter access for all teachers (bes0030, vys0053, jansik, lriha, mec059, milanjaros, vav0038).

## STEP 1:  Building the library (10%)

Provide compilation script for your application (the script should run independently on a current path). Script should load all necessary modules and call `cmake`.

## STEP 2:  Analysis of the application (10%)

Use `Arm map` (module Forge) to analyze a sequential run of your application with given use case (`large`). Identify the most time consuming regions that can be parallelized by OpenMP.

## STEP 3:  Use OpenMP to run the application in parallel (10%)

Put OpenMP pragmas to a correct positions with appropriate variables visibility in order to utilize more threads effectively.

## STEP 4:  Test the correctness of the code (10%)

Create script that automatically check correctness of your application for at least 3 different test cases. Comparison can be implemented as comparison of outputs of sequential and parallel runs.

## STEP 5:  Test the behavior of the code on the Karolina cluster (40%)

1. Implement time measurement for all parallel regions using omp_get_wtime(). 
2. Create script for run strong scalability measurement (PBS script).
3. Evaluate strong scalability of measured regions up to 128 threads and different thread affinity (compact, scatter, balanced, none).
4. Prepare charts for all measurements.

## STEP 6:  Presentation of your project (10%)

Prepare presentation in form of slides (pptx, pdf). The slides should address all topics requested above.

The presentation (pdf) as well as all other modifications, and outputs push to your git repository.
