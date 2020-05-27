import sys

InputCases = int( sys.stdin.readline() )

for PP in range( InputCases ):
    Number = int( sys.stdin.readline() )
    DigitList = list ( str( Number ) )
    DigitCount = len( DigitList )

    Total = 0
    for DD in DigitList:
        Total += ( int( DD ) )**DigitCount

    if Total == Number:
        print( 'Armstrong' )
    else:
        print( 'Not Armstrong' )

    #print( DigitList )

    
