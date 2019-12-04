'''*------------------------------------------------------------------------------*

                                AUTHOR: RAVI VOLETI
					SAM
					VIGNESH

                                ****ALGORITHM****

                       ***************ENCRYPTION****************

                            1. K =  Generate 256 bit random key.
                            2. E = Apply a one way function to get 128 bit encrypted key output.
                            3. P = We get plain Text 128 bits.
                            4. C = Random 128 bits.
                            5. R = P-C.
                            6. C'= C xor E
                            7. R'= R xor E
                            8. A = C'xor K's 128 MSB. -> Text file A.
                            9. B = R'xor K's 128 LSB. -> Text file B
                       ******************************************

                       ****************DECRYPTION****************

                            1. C'= A xor K's 128 MSB.
                            2. R'= B xor K's 128 LSB.
                            3. C = C' xor E.
                            4. R = R' xor E.
                            5. P = C+R.

                       ******************************************
*------------------------------------------------------------------------------*'''
import random
import os
from twofish import Twofish


# 1. K =  Generate 256 bit random key.
def randhex(number_of_bits):
    mx = (2 ** number_of_bits) - 1
    b = hex(random.randint(0, mx))
    return b[2:]

def split_key(hex_to_split):
    fake_plain_text = hex_to_split[0:32]
    fake_key_text = hex_to_split[32:64]
    return fake_plain_text,fake_key_text

def generate_C(plain_text):
    y = True
    while y == True:
        C = randhex(128)
        if C >= temp:
            C = randhex(128)
        else:
            y = False
            return C

def generate_R(plain_text,c):
    PT = int(plain_text,16)
    C = int(c,16)
    R = PT - C
    R = hex(R)
    return R[2:]

def generate_P(c,r):
    C = int(c,16)
    R = int(r,16)
    P = C+R
    P = hex(P)
    return P[2:]

def sxor(s1,s2):

    s1 = int(s1,base=16)
    s2 = int(s2,base=16)
    #xored = ''.join(chr(ord(a) ^ ord(b)) for a,b in zip(s1,s2))
    k = hex(s1 ^ s2)
    return k[2:]

def cloud_A(cd,k):
     encrypted_text = sxor(cd,k)
     file = open("cloudA.txt","a")
     file.write(encrypted_text)
     file.close()


def cloud_B(rd, k):
    encrypted_text = sxor(rd, k)
    file = open("cloudB.txt", "a")
    file.write(encrypted_text)
    file.close()

if __name__ == "__main__":

    choice = input("1.for encryption 2.for decryption: ")
    if choice == '1':
        try:
            os.remove("cloudA.txt")
            os.remove("cloudB.txt")
        except OSError:
            pass
        K = randhex(256)
        k2 = split_key(K)
        print('SECRET KEY PLEASE NOTE DOWN :',K)
        #print(k2)
    # 2. E = Apply a one way function to get 128 bit encrypted key output.
        fake_plain_text_byte = bytes.fromhex(k2[0])
        fake_key_text_byte = bytes.fromhex(k2[1])

        Twofish_key = Twofish(fake_key_text_byte)

        E = Twofish_key.encrypt(fake_plain_text_byte)
        E = E.hex()
        #print('E: ', E)

        #print(Twofish_key.decrypt(E).decode())

    # 3. P = We get plain Text 128 bits at a time.
        Plain_Text = input("TYPE PLAIN TEXT TO CIPHER : ")
        Plain_Text = Plain_Text.encode('utf-8')
        P = Plain_Text.hex()
        #print('PLAIN TEXT IN HEX: ',P)

        #To convert back to string and print
        #P = bytes.fromhex(Plain_Text);
        #print(P)

        i = 32
        j = 0
        length_of_plain_text =  len(P)
        range_value = int(length_of_plain_text/32)+1

        for x in range(0,range_value):
            temp = P[0+j:i]
            #print('temp: ', temp, x)
            if len(temp) == 32:
                # 4. C = Random 128 bits.
                C = generate_C(temp)
                #print('C: ',C, x)
                R = generate_R(temp, C)
                #print('R: ', R, x)
                Cd = sxor(C,E)
                #print('Cd: ', Cd, x)
                Rd = sxor(R, E)
                #print('Rd: ', Rd, x)
                cloud_A(Cd, k2[0])
                cloud_B(Rd, k2[1])

            else:
                append = '1'
                # Padding
                padding = 32
                temp = temp+append
                temp = temp.ljust(padding,'0')
                #print('padded value: ',temp)
                # 4. C = Random 128 bits.
                C = generate_C(temp)
                #print('C: ', C,x)
                R = generate_R(temp,C)
                #print('R: ', R, x)
                Cd = sxor(C, E)
                #print('Cd: ', Cd, x)
                Rd = sxor(R, E)
                #print('Rd: ', Rd, x)
                cloud_A(Cd, k2[0])
                cloud_B(Rd, k2[1])
            i+=32
            j+=32
        #print('CRE: ',type(C),type(R),type(E))

    elif choice == '2':
        K = input("ENTER SECRET KEY : ")
        k2= split_key(K)
        fake_plain_text_byte = bytes.fromhex(k2[0])
        fake_key_text_byte = bytes.fromhex(k2[1])

        Twofish_key = Twofish(fake_key_text_byte)

        E = Twofish_key.encrypt(fake_plain_text_byte)
        E = E.hex()
        #print('E: ',E)
        P = ''

        fileA = open('cloudA.txt')
        fileB = open('cloudB.txt')
        size = len(fileA.read())
        fileA.close()
        fileA = open('cloudA.txt')
        total_size = int(size/32)

        for x in range (0,total_size):
            tempA = fileA.read(32)
            tempB = fileB.read(32)
            #print(tempA)
            Cd = sxor(tempA,k2[0])
            temp_C = sxor(Cd,E)

            #print(tempB)
            Rd = sxor(tempB, k2[1])
            temp_R = sxor(Rd, E)

            #print('C: ', temp_C)
            #print('R: ', temp_R)
            #print('Cd: ', Cd)
            #print('Rd: ', Rd)

            P = P+generate_P(temp_C,temp_R)

        fileA.close()
        fileB.close()
        #print('PLAIN TEXT IN HEX:', P)

        x = True
        length_of_string = len(P)
        while x == True:
            length_of_string-=1
            if P[length_of_string] =='1':
                P = P[:-1]
                x = False
            else:
                P = P[:-1]
        #print('PLAIN TEXT IN HEX:', type(P),P)
        Plain_Text = bytes.fromhex(P)
        Plain_Text = Plain_Text.decode('utf-8')
        #Plain_Text = int(P,16)
        #Plain_Text = str(Plain_Text)
        print('ORIGINAL PLAIN TEXT : ',Plain_Text)

