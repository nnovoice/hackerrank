def get_digits_list(n):
    l = []
    while (n != 0):
        dig = n % 10;
        n /= 10
        l.append(dig)
        #print l
    l.reverse()
    return l

def get_largest_product(t, l, N, K):
    #print "#t=", t, "len(l)=",len(l),"N=", N, "K=", K, "N%K=", N%K
    best = 0
    #print "N-K=", N-K
    for i in range(N-K + 1):
        cur = 1
        for j in range(i, i+K):
            #print "i=",i,"j", j,"K", K,"i+K=", i+K,"cur=", cur,"l[j]=", l[j]
            cur *= l[j]
        if (best < cur):
            best = cur
    return best

T = int(raw_input())
for t in range(T):
    a, b = raw_input().split()
    N = int(a)
    K = int(b)
    digits = int(raw_input())
    #print N, K, digits
    l = get_digits_list(digits)
    print get_largest_product(t, l, N, K)
