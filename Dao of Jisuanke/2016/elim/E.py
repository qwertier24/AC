import sys
sys.stdin = open("in","r")
n = input()
if n % 3 == 0:
    print n/3,n/3,n/3
else:
    print -1
