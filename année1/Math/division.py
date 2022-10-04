import math 
def divisible(nombre,a):
    return nombre%2 == 0

def listeDiviseur(nombre):
    listeDiviseur = [1]
    for i in range(2,round(math.sqrt(nombre))+1):
        if (nombre % i == 0):
            listeDiviseur.append(i)
    return listeDiviseur

    
        
def nombrePremier(nombre):
    listeDiviseur = [1]
    nbPremier = False
    
    for i in range(2, round(math.sqrt(nombre))+1):
        if (nombre % i == 0):
            listeDiviseur.append(i)
    listeDiviseur.append(nombre)
    
    if (listeDiviseur == [1,nombre]):
        nbPremier = True
    
    return nbPremier


def diviseurPremier(nombre):
    liste = listeDiviseur(nombre)
    print(liste)
    diviseurPremier = []
    for i in liste:
        print(liste[i])
        if (nombrePremier(liste[i])):
            diviseurPremier.append(list[i])
    return diviseurPremier 

print(diviseurPremier(68))

def decomposition(n):
    liste = diviseurPremier(n)
    listeDiviseurPremier = []
    for i in liste:
        if (divisible(n,i)):
            append.listeDiviseurPremier(i)
    return listeDiviseurPremier

print(decomposition(720))
    
