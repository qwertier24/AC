import sys
n=100
sys.stdin=open("in.txt","r");
ans=0
for i in range(n):
    a=input()
    ans+=a
print ans
