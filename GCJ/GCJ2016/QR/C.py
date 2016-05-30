from math import sqrt
import sys

dig = ['' for i in xrange(100)]
num = [0 for i in xrange(100)]
tot = 0
n = 0
j = 0

def push(cur, d):
    dig[cur] = chr(ord('0') + d)
    for i in xrange(2,11):
        num[i] = num[i] * i + d

def pop(cur):
    for i in xrange(2,11):
        num[i] /= i

def print_dig():
    print ''.join(dig),
    for i in xrange(2,11):
        print find_div(num[i]),
    print

factors = [2,3,5,7,11,13]
def find_div(m):
    i = 2;
    for i in factors:
        if m % i == 0:
            return i
        i += 1
        if i * i > m:
            break
    return -1

def check():
    for i in xrange(2,11):
        if find_div(num[i]) == -1:
            return False
    return True
    
def srh(cur):
    global tot
    global j
    if cur == n:
        if check():
            print_dig()
            tot += 1
        return
    if cur != 0 and cur != n - 1:
        push(cur, 0)
        srh(cur + 1)
        pop(cur)
        if tot == j:
            return
    push(cur, 1)
    srh(cur + 1)
    pop(cur)

sys.stdin = open("in.txt","r")
sys.stdout = open("c.out2.txt","w")
a,n,j=input()
print "Case #1:"
srh(0)
