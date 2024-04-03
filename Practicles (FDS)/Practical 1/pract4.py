def linear_search(a,target):
    for i in range(len(a)):
        if(a[i]==target):
            print("Roll no.",target,"is present at index",i)
            break
    else:
        print("Roll no.",target,"not found in list")



def sentinelSearch(arr, n, key):

 
 last = arr[n - 1]

 
 arr[n - 1] = key
 i = 0

 while (arr[i] != key):
  i += 1

 
 arr[n - 1] = last

 if ((i < n - 1) or (arr[n - 1] == key)):
  print(key, "is present at index", i)
 else:
  print("Element Not found")

 Driver code
arr = [10, 20, 180, 30, 60, 50, 110, 100, 70]
n = len(arr)
key = 180

sentinelSearch(arr, n, key)


def binary_search(a,target):
    start=0
    end=len(a)-1
    while(start<=end):
        mid=int((start+end)/2)
        if(a[mid]==target):
            print("Roll no.",target,"is present at index",mid)
            break
        elif(target>a[mid]):
            start=mid+1
        elif(target<a[mid]):
            end=mid-1





def fibonacci_search(a,target):
    n=len(a)
    fibn_1=0
    fibn_2=1
    fibn=fibn_1+fibn_2
    while(fibn<=n):
        fibn_1=fibn_2
        fibn_2=fibn
        fibn=fibn_1+fibn_2
        print(fibn_1,fibn_2, fibn)
    offset=-1
    while(fibn_2!=0):
        i=min((offset+fibn_1),n-1)
        if(target>a[i]):
            fibn=fibn_2
            fibn_2=fibn_1
            fibn_1=fibn-fibn_2
            
            offset=i
            print("target>",fibn_1,fibn_2, fibn)
        elif(target<a[i]):
            fibn=fibn_1
            fibn_2=fibn_2-fibn_1
            fibn_1=fibn-fibn_2
            print("target<",fibn_1,fibn_2, fibn)
        elif(target==a[i]):
            print("Roll no.",target,"is present at index",i)
            break
    else:
        print("Roll no.",target,"not found in list")

a=input("Enter the roll list").split()
target=input("enter element to find")
fibonacci_search(a,target)