def isLeapYear(y): #check if y is a leap year
    if y%400==0 or (y%4==0 and y%100!=0):
        return True
    else:
        return False

monthDays=[31,0,31,30,31,30,31,31,30,31,30,31]
cur=0 #the first day in the current month
ans=0 
for y in range(1900,2001):
    for m in range(12):
        if cur==6 and y>1900: #check if y is in [1901,2000]
            ans+=1
        if m==1:
            if isLeapYear(y):
                cur+=29
            else:
                cur+=28
        else:
            cur+=monthDays[m]
        cur%=7
print ans
