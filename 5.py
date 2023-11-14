import math

b = int(input("podaj liczbę b "))
a = int(input("podaj liczbę a "))
c = int(input("podaj liczbę c "))

delta = pow(b, 2) - 4 * a * c
print("delta jest rowna", delta)

x1 = (-b - math.sqrt(delta)) / (2 * a)
x2 = (-b + math.sqrt(delta)) / (2 * a)

print("x1 jest rowne", x1)
print("x2 jest rowne", x2)
