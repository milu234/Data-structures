import math
def main():
    p = input("Enter the plain text : ")                                     #Enter the message
    n = int(input("Enter the key : "))                                       #Enter the key
    result = ""
    x = len(p)
    y = math.ceil(x / n)

    if (n * y == x):                                                       #if the matrix is getting completed r not
        result += p
    else:
        z = (n * y - x)
        result += p + ("#" * z)
    ciphertext = encryptMessage(n,result)                                  #EncryptMwssage function()
    li=list(ciphertext)                                                    #Matrix
    matrix = [li[i:i + y] for i in range(0, len(li), y)]
    for l in matrix:
        print(l)

    print("The Encrypted Message is : " + ciphertext)
    #


    # print(li)
    print("The Decrypted Message is : "+decryptMessage(n,ciphertext))       #Decrypt Message function()

def encryptMessage(key , message):
    ciphertext = ['']*key                                                      #make a list according to length of message
    for row in range(key):                                                      #traverse the message in the row wise matrix
        pointer = row
        while(pointer<len(message)):
            ciphertext[row] += message[pointer]
            pointer += key

    return ''.join(ciphertext)

def decryptMessage(key, message):
    v=math.ceil(len(message)/key)
    ciphertext = ['']*v                                                         #make a list according to length of message
    for col in range(v):
        pointer = col
        while(pointer<len(message)):
            ciphertext[col] += message[pointer]                                 #traverse the message in the row wise matrix
            pointer += v                                                        #traverse the pointer towards the whole matrix

    return ''.join(ciphertext)


if __name__=='__main__':
    main()
