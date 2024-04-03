U=[]
A=[]
B=[]
C=[]

u=int(input("Enter total no. of student "))
for i in range (1,u+1):
 U.append(i)

a=int(input("Enter total no. of student who like cricket "))
for i in range (1,a+1):
 l=int(input("Enter the Roll no."))
 A.append(l)

b=int(input("Enter total no. of student who like Badminton "))
for i in range (1,b+1):
 m=int(input("Enter the Roll no."))
 B.append(m)

c=int(input("Enter total no. of student who like Football "))
for i in range (1,c+1):
 n=int(input("Enter the Roll no."))
 C.append(n)

print("Total student in class",U)
print("Total student in class who like Cricket",A)
print("Total student in class who like badminton",B)
print("Total student in class who like Football",C)

AandB=[]
for i in range(a):
  for j in range(b):
    if A[i]==B[j]:
      AandB.append(A[i])
      break
print("The student who like cricket and Badminton-",AandB)

AorB=[]
for i in range(a):
    AorB.append(A[i])
for i in range(b):
   for j in range (a):
      flag=0
      if B[i]==A[j]:
        flag=1
        break
   if flag==0:
     AorB.append(B[i])
print("The student who like either Cricket or Badminton-",AorB)

N=[]
for i in range(len(AorB)):
  flag=0 
  for j in range(len(AandB)):
   if AorB[i]==AandB[j]:
    flag=1
    break
  if flag==0:
    N.append(AorB[i])
print("The Student who either Cricket or Badminton but not both-",N)  

P=[]
for i in range(u):
 flag=0
 for j in range(len(AorB)): 
    if U[i]==AorB[j]:
      flag=1
      break
 if flag==0:
  P.append(U[i])
print("The student who like neighter Cricket not Badminton-",P)

AandC=[]
for i in range(a):
  for j in range(c):
    if A[i]==C[j]:
      AandC.append(A[i])
      break
print("The student who like cricket and Football-",AandC)

Q=[]
for i in range(len(AandC)):
 flag=0
 for j in range(len(B)): 
    if AandC[i]==B[j]:
      flag=1
      break
 if flag==0:
  Q.append(AandC[i])
print("The student who like neighter Cricket and Football but not Badminton-",Q)





