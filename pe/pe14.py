dp={}
def getdp(i):
    if i in dp:
        return dp[i]
    if i == 1:
        dp[i]=1
        return 1
    if i % 2==1:
        dp[i]=getdp(3*i+1)+1
    else:
        dp[i]=getdp(i/2)+1
    return dp[i]

maxC=0
for i in range(1,1000000):
    dp[i]=getdp(i)
    if maxC<dp[i]:
        maxC=dp[i]
        ans=i
print ans
