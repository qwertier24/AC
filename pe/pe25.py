from math import log10
cnt=2
f0=1
f1=1
while log10(f1)<999:
    tmp=f0
    f0=f1
    f1+=tmp
    cnt+=1
print cnt
    
