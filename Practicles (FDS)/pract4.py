n=int(input("Enter the no of students present in training program = "))
st=[]
for i in range(n):
   r=int(input("Enter the Roll No "))
   st.append(r)
key=int(input("Enter which roll no you want to check"))
print("Total Student are = ",st)
   
#linear search
def linear():
   print("BY LINEAR SEARCH",end=" ")
   flag=0
   for i in range(n):
       if(st[i]==key):
           flag=1
           print("Roll no ",key," is present")
           break
   else:
      print("Roll no ",key ,"is absent")
      
#sentinal search
def sentinal():
    print("BY SENTINAL SEARCH",end=" ")
    st.append(key)
    i=0
    while(st[i]!=key):
       i=i+1
    if(i<n):
        print("Roll no",key,"is present")
    else:
        print("Roll no",key,"is absent")
#binary search
def binary():
    print("BY BINARY SEARCH",end=" ")
    st.sort()
    l=0
    h=n-1
    flag=0
    while(l<=h):
       mid=(l+h)//2
       if(key==st[mid]):
          flag=1
          break
       elif(key<st[mid]):
          h=mid-1
       else:
          l=mid+1
    if(flag==1):
       print("Roll no",key,"is present")
    else:
       print("Roll no",key,"is absent")

#fibonaccci       
def fibo():
   print("BY FIBONACCI SERACH",end=" ")
   fib2=0
   fib1=1
   fib=fib1+fib2
   while (fib<n):
      fib2=fib1
      fib1=fib
      fib=fib1+fib2
   offset=0
   flag=0
   while(fib>1):
      i=min(offset+fib2,n)
      if(st[i]==key):
          flag=1
          break
      elif(st[i]>key):
          fib=fib2
          fib1=fib1-fib2
          fib2=fib-fib1
      else:
          fib=fib1
          fib1=fib2
          fib2=fib-fib1
          offset=i
   if(flag==1):
         print("Roll no",key,"is present")
   else:
         print("Roll no",key,"is absent")
linear()
binary()
sentinal()
fibo()
