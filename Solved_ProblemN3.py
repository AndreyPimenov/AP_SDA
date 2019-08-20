pich = 3.141592654
echi = 2.718281828

# B - https://studopedia.ru/4_14595_pryamaya-i-ploskost.html
# C - http://www.webmath.ru/poleznoe/formules_6_11.php
#     https://studfiles.net/preview/2047677/page:2/

#n, m = int(input())
#print (n,m)4 5


# Задача с камнями: str1 - кол-во камней в куче, str2 - числа L и R
import math
N = int(input()) # stones in general
LR = input()
L = int(LR[0]) # min stones
R = int(LR[2]) # max stones
i = 0 #iterations
while (N > L):
    stones_random = random.randint(L,R)
    N = N - stones_random
    i = i+1
print (N, i)
