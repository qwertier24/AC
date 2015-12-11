MAXN=1000000
primeTable=[]
isPrime=[]
ans=0
for i in range(MAXN+1):
    isPrime.append(1)
for i in range(2,MAXN+1):
    if isPrime[i]==1:
        primeTable.append(i)
        if(len(primeTable)==10001):
            print i
    for j in primeTable:
        if i*j>MAXN:
            break
        isPrime[i*j]=0
        if i%j==0:
            break
