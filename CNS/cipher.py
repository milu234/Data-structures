x = input("Enter the plain text : ")
result = ""

for i in range(len(x)):
    str = x[i]

    if(str.isupper()):
        result += chr((ord(str)+3-65)%26+65)  #For upper case
        
    elif(str.islower()):
        result += chr((ord(str)+3-97)%26+97)   #For lower case
        
    elif(str == " "):
        result += " "                       #For spaces
        
    elif(str.isdigit()):
	result += chr((ord(str)+3-48)%10+48)  #for numbers
    else:
	result += chr((ord(str))
        
print("The Encoded Text is : "+result)

