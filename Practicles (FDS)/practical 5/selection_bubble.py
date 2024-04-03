# Selection sort in Python
# time complexity O(n*n)
# sorting by finding min_index
def selectionSort(array, size):
    for ind in range(size):
        min_index = ind
        #offset=True
        for j in range(ind + 1, size):
            # select the minimum element in every iteration
            if array[j] < array[min_index]:
                min_index = j

        # swapping the elements to sort the array
        (array[ind], array[min_index]) = (array[min_index], array[ind])

        print("iteration ",ind,array)



#arr = [-2, 45, 0, 11, -9, 88, -97, -202, 747]
str=int(input("how many no are"))
arr=[]
for i in range(str):
    e=int(input("enter the roll no"))
    arr.append(e)
size = len(arr)
selectionSort(arr, size)

print('The array after sorting in Ascending Order by selection sort is:')
print(arr)


def bubblesort(elements):
    swapped = False
    # Looping from size of array from last index[-1] to index [0]
    for n in range(len(elements) - 1, 0, -1):
        for i in range(n):

            if elements[i] > elements[i + 1]:
                swapped = True
                # swapping data if the element is less than next element in the array
                elements[i], elements[i + 1] = elements[i + 1], elements[i]
                #temp=elements[i]
                #elements[i]=elements[i+1]
                #elements[i+1]=temp
        if not swapped:
            # exiting the function if we didn't make a single swap
            # meaning that the array is already sorted.
            return


elements = [39, 12, 18, 85, 72, 10, 2, 18]

print("Unsorted list is,")
print(elements)
bubblesort(elements)
print("Sorted Array is, ")
print(elements)

print(elements[-5:])
re= elements[-5:]
re.reverse()
print(re)