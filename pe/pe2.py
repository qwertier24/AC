ans=0
f0=1
f1=1
while f1<=4e6:
    if(f1&1==0):
        ans+=f1
    tmp=f0
    f0=f1
    f1+=tmp
print ans
