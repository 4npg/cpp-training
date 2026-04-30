import math

n = int(input())

if n<2:
    print("Khong phai la so nguyen to")
else:
    ok = True
    for i in range(2, int(math.sqrt(n))+1):
        if n%i==0:
            ok = False
            break
    if ok:
        print("La so nguyen to")
    else:
        print("Khong phai la so nguyen to")