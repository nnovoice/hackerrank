MAX = 50001
NUM_TRINUMS = 42000
primes = []
ps = [] #prime slots
tfactors = [0] * 1026 

def gen_primes(n):
    ps = [True] * n
    ps[0] = False
    ps[1] = False
    for i in range(2, n):
        if (ps[i] == True):
            primes.append(i)
            j = i + i
            while (j < MAX):
                ps[j] = False
                j += i

def get_prime_factors(n):
    f = []
    j = 0
    while (n > 0 and primes[j] <= n):
        if (n % primes[j] == 0):
            while (n > 0):
                if (n % primes[j] == 0):
                    f.append(primes[j])
                    n /= primes[j]
                else:
                    break
        j += 1

    if (len(f) == 0):
        f.append(n)
    return f

trinums = []
def gen_trinums(n):
    trinums.append(0)
    trinums.append(1)
    for i in range(2, n):
        trinums.append(trinums[i-1] + i)

def sum_n(n):
    return (n * (n + 1)) / 2

def print_tfactors():
    for i in range(1, 1025):
        if (tfactors[i] != 0):
            print i, tfactors[i]

# number of factors is determined using the divisor or Tau function
# d(n) = p^a * q^b * r^c ...
# num divisors = (a + 1) * (b + 1) * (c + 1) ...
#####
def gen_num_divisors():
    max_factors = 0
    tfactors[0] = 0
    tfactors[1] = 1

    for i in range(2, NUM_TRINUMS):
        factors = get_prime_factors(trinums[i])
        nfactors = 1
        for f in set(factors):
            a = factors.count(f)
            nfactors *= (a + 1)
        
        #print trinums[i], sum_n(i), nfactors, factors

        #if (tfactors[nfactors] == 0):
        #    print "got best for ", nfactors, "i=", i, "trinum=", trinums[i], "sum_n=", sum_n(i), "nfactors=", nfactors, "all factors=", factors
        #    tfactors[nfactors] = trinums[i]

        if (nfactors > max_factors):
            max_factors = nfactors
            tfactors[nfactors] = trinums[i]
            #print "got best for ", nfactors, "i=", i, "trinum=", trinums[i], "sum_n=", sum_n(i), "nfactors=", nfactors, "all factors=", factors

gen_primes(MAX)

gen_trinums(NUM_TRINUMS)

gen_num_divisors()

T = int(raw_input())
for i in range(T):
    N = int(raw_input())
    j = N + 1
    while (j < len(tfactors)):
        if (tfactors[j] != 0):
            print tfactors[j]
            break
        j += 1

