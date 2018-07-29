import math
def main():
    p = input("Enter the plain text : ")
    n = int(input("Enter the key : "))
    result = ""
    x = len(p)
    y = math.ceil(x / n)

    if (n * y == x):
        result += p
    else:
        z = (n * y - x)
        result += p + ("#" * z)
    ciphertext = encryptMessage(n,result)
    li=list(ciphertext)
    #
    # matrix = [li[i:i + y] for i in range(0, len(li), y)]
    # for l in matrix:
    #     print(l)
    print("The Encrypted Message is : "+ciphertext)

    # print(li)
    print("The Decrypted Message is : "+decryptMessage(n,ciphertext))







def encryptMessage(key , message):
    ciphertext = ['']*key
    for row in range(key):
        pointer = row
        while(pointer<len(message)):
            ciphertext[row] += message[pointer]
            pointer += key

    return ''.join(ciphertext)

def decryptMessage(key, message):
    v=math.ceil(len(message)/key)
    ciphertext = ['']*v
    for col in range(v):
        pointer = col
        while(pointer<len(message)):
            ciphertext[col] += message[pointer]
            pointer += v

    return ''.join(ciphertext)


if __name__=='__main__':
    main()
