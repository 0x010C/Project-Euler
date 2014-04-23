nt isPrime(int n)
{
        int i = 3;
        if(n%2 == 0)
                return 0;
        while(i <= n/2)
        {
                if(n%i == 0)
                        return 0;
                i++;
        }
        return 1;
}

