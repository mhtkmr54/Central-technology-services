bool fun(int n)
{
    int sum = 0;
    for (int odd = 1; n > sum; odd = odd+2)
       sum = sum + odd;
    return (n == sum);
}

//true if n is perfect square