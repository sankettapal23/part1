a=int(input("Enter No. of Rows :- "))
b=int(input("Enter No. of Cols :- "))
print("Enter Elements in an 1st Array \n")
A=[]
B=[]
for i in range(a):
    sub=[]
    for j in range(b):
       z=int(input())
       sub.append(z)
    A.append(sub)
print("Enter Elements in an 2nd Array \n ")
for i in range(a):
     sub=[]
     for j in range(b):
        z=int(input())
        sub.append(z)
     B.append(sub)
print("****************** FIRST MATRIX ******************")
print("First Array :-\n")
for i in range(a):
        for j in range(b):
            print(A[i][j],end="  ")
        print("\n")
print("******************* SECOND MATRIX ***************")
print("Second Array :-\n")
for i in range(a):
        for j in range(b):
            print(B[i][j],end="  ")
        print("\n")
def add():
      C=[]
      print("**************** ADDITION ****************")
      for i in range(a):
         sub=[]
         for j in range(b):
             z=A[i][j]+B[i][j]
             sub.append(z)
         C.append(sub)
      # print("Addition :- ",C)
      print("Addition :-\n")
      for i in range(a):
        for j in range(b):
            print(C[i][j],end="  ")
        print("\n")
def sub():
    C=[]
    print("**************** SUBTRACTION **************")
    for i in range(a):
       sub=[]
       for j in range(b):
           z=A[i][j]-B[i][j]
           sub.append(z)
       C.append(sub)
    #print("Subraction :- ",C)
    print("Subraction :-\n")
    for i in range(a):
      for j in range(b):
          print(C[i][j],end="  ")
      print("\n")
def tra():
    C=[]
    D=[]
    print("**************** TRANSPOSE ***************")
    print("Matrix A :- \n")
    '''for i in range(a):
       sub=[]
       for j in range(b):
           sub.append(0)
       C.append(sub)'''
    for i in range(a):
       for j in range(b):
          C[j][i]=A[i][j]
    for i in range(a):
      for j in range(b):
          print(C[i][j],end="  ")
      print("\n")
    print("\nMatrix B :- \n")
    '''for i in range(a):
       sub=[]
       for j in range(b):
           sub.append(0)
       D.append(sub)'''
    for i in range(a):
       for j in range(b):
          D[j][i]=B[i][j]
    for i in range(a):
      for j in range(b):
          print(D[i][j],end="  ")
      print("\n")
           
add()
sub()
tra()
def mul():
   A=[]
   B=[]
   C=[]
   print("************ MULTIPLICATION ************")
   m1=int(input("Enter Rows of First Matrix :- "))
   n1=int(input("Enter Cols of First Matrix :- "))
   m2=int(input("Enter Rows of Second Matrix :- "))
   n2=int(input("Enter Cols of Second Matrix :- "))
   if n1==m2:
      print("Enter First Matrix : - :\n")
      for i in range(m1):
        sub=[]
        for j in range(n1):
          z=int(input())
          sub.append(z)
        A.append(sub)
      print("Enter Second Matrix :-\n ")
      for i in range(m2):
       sub=[]
       for j in range(n2):
          z=int(input())
          sub.append(z)
       B.append(sub)
      print("**************** FIRST MATRIX ****************")
      print("First Matrix :-\n")
      for i in range(m1):
        for j in range(n1):
            print(A[i][j],end="  ")
        print("\n")
      print("**************** SECOND MATRIX  ****************")
      print("Second Matrix :-\n")
      for i in range(m2):
        for j in range(n2):
            print(B[i][j],end="  ")
        print("\n")
      print("**************** MULTIPLICATION ******************")
      for i in range(m1):
         sub=[]
         for j in range(n2):
              sum=0
              for k in range(n1):
                sum=sum+(A[i][k]*B[k][j])
              sub.append(sum)
         C.append(sub)  
      print("Multiplication :- \n")
      for i in range(m1):
        for j in range(n2):
            print(C[i][j],end="  ")
        print("\n")         
   else:
      print("Enter Equal Cols of First Matrix and Rows of Second Matrix \n")
mul()   
   
