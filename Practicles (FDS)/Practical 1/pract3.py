u=int(input("Total no of students ="))
U=[]
for i in range(u):
    i=i+1
    U.append(i)
print("Total roll numbers ",U)

n=int(input("Total number of present students in the class ="))
P=[]
for i in range(n):
    r=int(input("Roll no of present students ="))
    P.append(r)
print("present students are",P)

M=[]
for i in range(n):
    m=int(input("Enter the marks of present students ="))
    M.append(m)
print("marks of present students",M)
#Avg Score

def a():
    totalscore=0
    for i in range(n): 
        totalscore=totalscore+M[i]
    avgscore=totalscore/n
    print("average score of class is ",avgscore)
a()

#Highest Score and Lowest Score
def b():
    low=100
    for i in range(n):
        if M[i]<low:
            low=M[i]
    print("lowest score in the class is ",low)
    high=-1
    for i in range(n):
        if M[i]>high:
            high=M[i]
    print("Highest score in the class is ",high)
b()

#Absent Roll no
A=[]
def c():
    for i in range(u):
        flag=0
        for j in range(n):
            if U[i]==P[j]:
                flag=1
                break;
        if flag==0:
            A.append(U[i])
    print("Absent roll numbers are ",A)
c()

a()
b()
c()
