mp={}
for i in xrange(2,100+1):
    for j in xrange(2,100+1):
        mp[i**j]=1
print len(mp)
