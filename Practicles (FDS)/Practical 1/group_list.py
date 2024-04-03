cricket = list(input("Enter the roll no of student who play cricket : ").split(','))
badminton = list(input("Enter the roll no of student who play badminton : ").split(','))
football = list(input("Enter the roll no of student who play football : ").split(','))
#for (A) students who plays both cricket and badminton
a = list()
for i in cricket:
        for j in badminton:
                if i == j : 
                       a.append(i)
                        
print("students who plays both cricket and badminton " +str(a))  
                     
#for(B) students who plays either cricket or badminton
b = list()
for i in cricket:
        if i not in badminton:
                b.append(i)
c = list()
for j in badminton:
        if j not in cricket:
                c.append(j)
print("only cricket " + str (b) + " only badminton"+ str(c))

#for (C) neither play cricket nor badminton
d = list()
for i in football:
        if (i not in cricket) and (i not in badminton):
                d.append(i) 
print("no of students neither play cricket nor badminton : "+ str(len(d)) + " and their roll no are " + str(d))

#for(D) play cricket and football but not badminton

e = list()
for i in cricket:
        for j in football:
                if i==j:
                        e.append(i)
f = list()
for i in e:
        if i not in badminton:
                f.append(i)
print("No of students play cricket and football but not badminton :" + str(f) )               
          
                         
                
                
                        
                       
       

