import pandas as pd

def addition_gruant(n):
    add=[]
    for i in range(n):
        add.append([])
        for j in range(n):
            add[i].append((i*j)%n)

    df = pd.DataFrame(add,columns=[i for i in range(n)],index =[i for i in range(n)])
    return df

addition_gruant(7)