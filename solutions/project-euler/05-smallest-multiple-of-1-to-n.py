T = int(raw_input())
squares = [2*2, 3*3, 4*4, 5*5, 6*6]
factors = [2,3,4,5,6]
print T
for i in xrange(T):
    N = int(raw_input())
    print N
    multiple = 1
    for j in range(1,N+1):
        multiple *= j;
        print "multiple=" , multiple
        for l in range(5):
            print "j = ", j, "l= ", l
            if (j == squares[l]):
                multiple /= factors[l]
                print "got a square. new multiple=", multiple
    print multiple

