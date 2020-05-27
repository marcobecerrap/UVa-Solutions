import sys

def GetOnes( N ):
    return int( '1'*N )

for InputString in sys.stdin:
    InputNumber = int( InputString )
    FirstONE = 1
    FoundMultiple = False
    while FoundMultiple == False:
        if ( GetOnes( FirstONE ) % InputNumber ) != 0:
            FirstONE += 1
        else:
            break
    print( FirstONE )
