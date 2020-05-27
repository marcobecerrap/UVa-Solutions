import sys

# Make primes
MAX_NUM = 1000100
Cribe = [ None ] * MAX_NUM

Cribe[ 0 ] = False
Cribe[ 1 ] = False

PrimeList = []

for JJ in range( 2 , MAX_NUM ):
    if Cribe[ JJ ] == None:
        Cribe[ JJ ] = True
        PrimeList.append( JJ )
        for TT in range( 2*JJ, MAX_NUM, JJ ):
            Cribe[ TT ] = False
    else:
        continue

PrimeIdx = [ 0 ] * 1000001
Idx = 0
for JJ in range( 1000001 ):
    if JJ < PrimeList[ Idx ]:
        PrimeIdx[ JJ ] = Idx
    else:
        Idx += 1
        PrimeIdx[ JJ ] = Idx

#print( PrimeList[0:8] )
            


for InputString in sys.stdin:
    InputNumber = int( InputString )

    if InputNumber == 0:
        break

    FoundPair = False
    N1 = 0
    N2 = 0
    for TT in range( PrimeIdx[ InputNumber ], 0, -1 ):
        N1 = PrimeList[ TT ]
        for FF in range( TT + 1 ):
            N2 = PrimeList[ FF ]
            if ( N2 + N1 ) < InputNumber:
                continue
            elif ( N2 + N1 ) == InputNumber:
                FoundPair = True
                break
            else:
                break
        if FoundPair == True:
            break

    
    print( InputNumber, '=', N2, '+', N1 )


    
