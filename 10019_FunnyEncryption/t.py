import sys

InputCases = int( sys.stdin.readline() )

for PP in range( InputCases ):
    NumberA = int( sys.stdin.readline() )
    NumberB = int( '0x' + str( NumberA ), 16 )

    BinA = list( bin( NumberA ) )
    BinB = list( bin( NumberB ) )

    print( BinA.count( '1' ), ' ', BinB.count( '1' ), sep='' )

    #print( NumberA )
    #print( NumberB )
    #print( '------------' )

    
