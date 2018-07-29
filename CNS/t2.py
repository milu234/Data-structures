message = input()
key = int(input())
ciphertext = ['']*key
print(ciphertext)
for row in range(key):
    pointer = row
    print(row)
    while(pointer<len(message)):
        ciphertext[row] += message[pointer]
        print(pointer)
        print(ciphertext[row])
        pointer += key
        print(pointer)







