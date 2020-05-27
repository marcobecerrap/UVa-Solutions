import sys

InputCases = int( sys.stdin.readline() )
SizeUrl = 10

for K in range( InputCases ):
    InputList = []
    for U in range( SizeUrl ):
        InputLine = sys.stdin.readline()
        InputList += [[ S for S in InputLine.split() ]]
    Keys = []
    #print( InputList )
    for U in range( SizeUrl ):
        Keys.append( int( InputList[ U ][ 1 ] ) )
    Keys.sort()

    MaxKey = Keys[ SizeUrl - 1 ]
    print( 'Case #', ( K + 1 ), ':', sep='' )
    for U in range( SizeUrl ):
        Key = int( InputList[ U ][ 1 ] )
        if Key == MaxKey:
            print( InputList[ U ][ 0 ] )
    
