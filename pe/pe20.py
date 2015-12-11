n=1
for i in range(1,101):
    n*=i
ans=0
while n:
    ans+=n%10
    n/=10
print ans
