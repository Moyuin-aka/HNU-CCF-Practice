def calDA(count,data):
    da=0
    if count == 0:
        return da
    for i in range(0,count):
        da+= int(data)*(10**i)
    return da

def calcount(A,data):
    return A.count(data)

if __name__ == "__main__":
    inputs=input().strip().split()
    A = inputs[0]
    dataA = inputs[1]
    B = inputs[2]
    dataB = inputs[3]

    countA=calcount(A,dataA)
    daA=calDA(countA,dataA)
   
    countB=calcount(B,dataB)
    daB=calDA(countB,dataB)
    print(daA+daB)
   

