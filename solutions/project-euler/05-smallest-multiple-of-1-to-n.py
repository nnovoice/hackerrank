def get_prime_factors(N):
    factors = []
    for i in range(2, N):
        if (N % i == 0):
            while(N != 0):
                if (N % i == 0):
                    factors.append(i)
                    N /= i
                else:
                    break
    if (len(factors) == 0):
        factors.append(N) #prime 

    factors.sort()
    return factors

factors_map = {}

for k in range(1,41):
    #print k, get_prime_factors(k)
    factors_map[k] = get_prime_factors(k)

T = int(raw_input())

for i in xrange(T):
    N = int(raw_input())
    multiples = []
    for n in range(2,N+1):
        uniq_factors = set(factors_map[n])
        for uf in uniq_factors:
            if (multiples.count(uf) < factors_map[n].count(uf)):
                diff = factors_map[n].count(uf) - multiples.count(uf)
                while (diff > 0):
                    multiples.append(uf)
                    diff -= 1
    
    multiples.sort()

    #print "debug: ", "full list of multiples=", multiples
    smallest_multiple = 1;
    for m in multiples:
        smallest_multiple *= m

    print smallest_multiple

    
