import math

p = input("Enter the String : ")
n = int(input("Enter the key"))
result = ""
x= len(p)
y = math.ceil(x/n)
print(y)
if(n*y == x):
    result += p
else:
    z= (n*y-x)
    result += p+("X"*z)
li = list(result)
print(li)

matrix =[li[i:i+y] for i in range(0,len(li),y)]
for l in matrix:
    print (l)


