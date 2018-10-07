#include <stdio.h>

int josephus(int n, int k)
{
  if (n == 1)
    return 1;
  else
    /* The position returned by josephus(n - 1, k) is adjusted because the
       recursive call josephus(n - 1, k) considers the original position
       k%n + 1 as position 1 */
    return (josephus(n - 1, k) + k-1) % n + 1;
}

// Returns position of survivor among a circle
// of n persons and every second person being
// killed

/*
if n = 2 ^ m + l and 0 <= l < 2^m
then f(n) = 2l + 1
*/

int josephus(int n)
{
    // Find value of 2 ^ (1 + floor(Log n))
    // which is a power of 2 whose value
    // is just above n.
    int p = 1;
    while (p <= n)
        p *= 2;

    // Return 2n - 2^(1+floor(Logn)) + 1
    return (2*n) - p + 1;
}

