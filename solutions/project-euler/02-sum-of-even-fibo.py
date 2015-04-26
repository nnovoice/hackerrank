T = int(raw_input())
#print T

sum = 0;

for i in range(0,T):
    N = int(raw_input())
    #print "N is ", N
    sum = 0
    a = 1
    b = 2
    while(True):
        if (a > N or b > N):
            break

        a, b = b, a + b
        if (a % 2 == 0):
		    sum += a
        #print "a=",a, "b=",b, "sum=", sum
    print sum
    
