import sys
import math

InputList = []

for InputString in sys.stdin:
    NewList = [ int( II ) for II in InputString.split() ]
    InputList = InputList + NewList


print( 'PERFECTION OUTPUT' )

for Number in InputList:
    if Number == 0:
        break

    DivisorList = [ 1 ]

    if Number == 1:
        DivisorList = [ 0 ]

    Limit = int( math.sqrt( Number ) )

    #print( Limit )

    for DD in range( 2, Limit + 1 ):
        if ( Number % DD ) == 0:
            D1 = DD
            D2 = int( Number / DD )            
            DivisorList.append( D1 )
            if D1 != D2:
                DivisorList.append( D2 )
    #print( Number, '-', DivisorList )

    DigitCount = len( list( str( Number ) ) )
    WhiteSpaceCount = 5 - DigitCount

    Result = ''
    SumDivisors = sum( DivisorList )
    if SumDivisors == Number:
        Result = 'PERFECT'
    elif SumDivisors < Number:
        Result = 'DEFICIENT'
    else:
        Result = 'ABUNDANT'
        

    print( ( ' '*WhiteSpaceCount ), Number, '  ', Result, sep='' )


print( 'END OF OUTPUT' )
