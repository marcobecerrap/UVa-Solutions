import sys


def GetDivisors( Number, DivisorList ):
    TopD = int( ( Number / 2 ) + 1 )
    #print( 'top ', TopD )
    for K in range( TopD ):
        #print( 'K ', K ) 
        if K > 1 and ( Number % K ) == 0:
            DivisorList.append( K )
            #print( '---> ', K )
    

Cases = int( sys.stdin.readline() )

for K in range( Cases ):
    InputNumber = int( sys.stdin.readline() )
    DivisorList = [1]
    #print( InputNumber )
    GetDivisors( InputNumber, DivisorList )
    #print( DivisorList )
    #print( '---------' )
    if sum( DivisorList ) < InputNumber:
        print( 'deficient' )
    elif sum( DivisorList ) == InputNumber:
        print( 'perfect' )
    else:
        print( 'abundant' )

