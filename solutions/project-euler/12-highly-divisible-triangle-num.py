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
    #print "num primes= ", len(primes)
    #for i in range(len(primes)):
    #    print i, primes[i]

def get_prime_factors(n):
    f = []
    j = 0
    #print "get_prime_factors: ", n, j, f, primes[j]
    while (n > 0 and primes[j] <= n):
        if (n % primes[j] == 0):
            #print n, j, f, primes[j]
            while (n > 0):
                #print "ok", n, j, f, primes[j]
                if (n % primes[j] == 0):
                    f.append(primes[j])
                    #print "appended ", primes[j]
                    n /= primes[j]
                else:
                    break
        j += 1

    if (len(f) == 0):
        f.append(n)
        #print primes[j], n, "appended: ", n
    return f

trinums = []
def gen_trinums(n):
    trinums.append(1)
    for i in range(1,n):
        trinums.append(trinums[i-1] + i + 1)
        #print trinums[i]

gen_trinums(NUM_TRINUMS)
gen_primes(MAX)
max_factors = 0
tfactors[0] = 0
tfactors[1] = 1

def print_tfactors():
    for i in range(1, 1025):
        if (tfactors[i] != 0):
            print i, tfactors[i], get_prime_factors(tfactors[i])

for i in range(1,NUM_TRINUMS):
    factors = get_prime_factors(trinums[i])
    nfactors = 1
    for f in set(factors):
        a = factors.count(f)
        nfactors *= (a + 1)

    if (tfactors[nfactors] == 0):
        tfactors[nfactors] = trinums[i]

    #print trinums[i], factors, "nfactors= ", nfactors
    if (nfactors > max_factors):
        max_factors = nfactors

#print "max factors= ", max_factors
#print_tfactors()

T = int(raw_input())
for i in range(T):
    N = int(raw_input())
    j = N + 1
    while (j < len(tfactors)):
        if (tfactors[j] != 0):
            print tfactors[j]
            break
        j += 1

