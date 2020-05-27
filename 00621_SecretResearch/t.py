import sys

InputCases = int( sys.stdin.readline() )

for JJ in range( InputCases ):
    InputNumber = int( sys.stdin.readline() )
    InputList = [ int( D ) for D in list( str( InputNumber ) ) ]
    #print( InputNumber )
    #print( InputList )
    if InputNumber == 1 or InputNumber == 4 or InputNumber == 78:
        print( '+' )
    elif InputList[ len( InputList ) - 2 ] == 3 and InputList[ len( InputList ) - 1 ] == 5:
        print( '-' )
    elif InputList[ 0 ] == 9 and InputList[ len( InputList ) - 1 ] == 4:
        print( '*' )
    elif InputList[ 0 ] == 1 and InputList[ 1 ] == 9 and InputList[ 2 ] == 0:
        print( '?' )
    else:
        print( '?' )
        
