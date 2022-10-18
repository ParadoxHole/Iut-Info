equation1 = [0,8,6,8]
equation2 = [4,8,6,3]
equation3 = [9,0,1,0]

resultat = [equation1,equation2,equation3[[4, 8, 6, 3], [8.0, 6.0, 8.0], [1.0, 11.25]]]

def PivotDeGausse(resultat):
    
    #check if the pivot multiplicator is not 0
    if resultat[0][0] == 0:
        for i in range(1, len(resultat)):
            if resultat[i][0] != 0 : # swap as soon as he find a value that is not 0
                resultat[0], resultat[i] = resultat[i] ,resultat[0]
                break
        else: #didn't found 
            raise ValueError
    
    if len(resultat) == 1:
        return resultat
       
    for i in range(1,len(resultat)):
        pivot = resultat[i][0]/resultat[0][0]
        for j in range(1, len(resultat[i])):
            resultat[i][j] -= pivot * resultat[0][j]
        resultat[i].pop(0)
        
    listRec = PivotDeGausse(resultat[1:])
    nouveauSys = resultat[0:1]
    for i in listRec:
        nouveauSys.append(i)
    return nouveauSys
    
print(PivotDeGausse(resultat))
