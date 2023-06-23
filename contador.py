lista = []
for k in range(0,219):
    a = str(input("palvras:"))
    lista.append(a)
sorted(lista)
b = 0
for k in range(0,219):
    if lista[k] == lista[k-1]:
        pass
    else:
        b+=1
print("o número é {}".format(b))