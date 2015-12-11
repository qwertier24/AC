n=1
for i in range(1000):
    n*=2
ans=0
while n:
    ans+=n%10
    n/=10
print ans
