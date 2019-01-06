/*
number of ways to go from one point to another

for n dimentions:

let 4 dimention point (p1,p2,p3,p4) and (n1,n2,n3,n4)

the sutro will be

( (n1-p1) + (n2 - p2) + (n3 - p3) + (n4 - p4) )! / ( (n1-p1)! * (n2-p2)! * (n3-p3)! * (n4-p4)! )

p.s. we are assuming that we can only go in the positive direction.
So if any of the (ni-pi) term is negative number of ways will be 0.

*/