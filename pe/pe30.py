def check(n):
    m=n
    sum=0
    while n!=0:
        sum+=(n%10)**5
        n/=10
    return sum==m
ans=0
for i in range(10,1000000):
    if check(i):
        ans+=i
print ans
