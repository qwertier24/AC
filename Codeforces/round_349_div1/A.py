import sys
sys.stdin = open("in.txt","r")

s = raw_input()
n = len(s)
ans = set()

if n <= 4:
    print 0
    sys.exit(0)

flag = [True]*n
a = range(n)
a.reverse()
for i in a:
    if i == n - 1:
        flag[i] = True
    else:
        flag[i] = (flag[i+1] and s[i] == s[i+1])

for i in xrange(len(s)):
    for j in xrange(2,4):
        if i < 5:
            continue
        if n - i -j == 1 or n - i - j < 0:
            continue
        if n-i-j == 4 and s[n-4:n-2] == s[n-2:]:
            continue
        if n-i-j > 4 and (n-i-j) % 5 != 0 and (n-i-j) % 5 != 2 and (n-i-j)%5!=3 and flag[i+j]:
            continue
        ans.add(s[i:i+j])
ans = list(ans)
ans.sort()
print len(ans)
for i in ans:
    print i
