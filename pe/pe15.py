C=[[0 for i in range(41)] for i in range(41)]
C[0][0]=1
for i in range(1,41):
    C[i][0]=1
    for j in range(1,i+1):
        C[i][j]=C[i-1][j-1]+C[i-1][j]
print C[40][20]
