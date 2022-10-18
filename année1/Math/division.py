import math 
import pandas as pd

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

def decomposition(n):
    liste = diviseurPremier(n)
    listeDiviseurPremier = []
    for i in liste:
        if (divisible(n,i)):
            listeDiviseurPremier.append(i)
    return listeDiviseurPremier

def crible(n):
    l = [2]
    for i in range(3,n+1,2):
        if nombrePremier(i):
            l.append(i)
        i+=2
    return l

def golbach(n):
    l = crible(n)
    calc = ""
    for i in l:
        for j in l:
            if (i + j == n):
                calc = str(i)+ " + " + str(j) + " = " + str(n)
                return calc
    return "impair"

def congruance(n,m):
    return m%n

def pgcd_euclide_rec(n,m):
    if congruance(m,n) == 0 :
        return m
    return pgcd_euclide_rec(m,congruance(m,n))

def addition_gruant(n):
    add=[]
    for i in range(n):
        add.append([])
        for j in range(n):
            add[i].append((i+j)%n)

    df = pd.DataFrame(add,columns=[i for i in range(n)],index =[i for i in range(n)])
    return df

def multiplication_gruant(n):
    add=[]
    for i in range(n):
        add.append([])
        for j in range(n):
            add[i].append((i*j)%n)

    df = pd.DataFrame(add,columns=[i for i in range(n)],index =[i for i in range(n)])
    return df

def tableau_gruant(n):
    tab = []
    TAILLE = 15
    for i in range (0,TAILLE):
        tab.append(congruance(n,i))
    return tab

