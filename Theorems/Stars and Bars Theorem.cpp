/*
Stars and Bars Theorem

How many ways can we write, a+b+c=10, where a,b,c are non-negative number? 
This is similar to the following situation. 
Imagine, we have three containers labeled A,B,C and 10 balls.
How many ways can we place the balls?
2+1+7 means we placed 2 ball in A, 1 balls in B and 7 balls in C.
The same thing can be represented graphically as following: **|*|*******.
This is how it got the name, Stars and Bars theorem.
The two bars, |, divide the stars into three sections. 
Therefore, if we have x containers,
then graphical representation will have x−1 bars.

Lets get back to the problem. We have three containers 
( that is two bars ) and ten balls ( ten stars ).
Our graphical representation will therefore have 12 characters.
Now, how many ways can we place the bars here? (12)C(2).
That is our answer. We can form a+b+c=10 in (12)c(2) ways.

So, formally the Stars and Bars Theorem can be stated as:
If we have N indistinguishable balls and K distinguishable containers,
then we can distribute them in (N+K−1)C(K−1) ways.


Positive Number of Balls in Each Container:

What if every container needs to have at least one ball? 
Simple. Place a ball in each bin and subtract those placed balls from total balls.
Then apply Stars and Bars Theorem normally.
So, a+b+c=10, where a,b,c are positive, has (n−k+k−1)C(k−1)=(n−1)C(k−1) solutions.


Lower Bound with Each Container:

This is more generalized version of the extension above. 
We are given the lower limits for each container. 
If a lower limit of a container is x, then we must place x or more balls in that containers.
I will do it a bit differently this time.
Suppose we want to find solution for a+b+c=100, where lower limits of a,b,c are 10,20,35.
Then, we can rewrite the equation as following: a+b+c=100 (10+x)+(20+y)+(35+z)=100, 
where x,y,z are non-negative integers. ∴x+y+z=100−10−20−35=35
Now, we apply Star and Bars theorem normally. 
The answer is (37)C(2).
So, just subtract the lower bounds from total number of balls and apply the theorem normally.

*/