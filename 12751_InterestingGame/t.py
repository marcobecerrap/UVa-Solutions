import sys

InputCases = int( sys.stdin.readline() )

for JJ in range( InputCases ):
    InputString = sys.stdin.readline()
    InputData = [ int( D ) for D in InputString.split() ]
    Marbles = range( 1, InputData[ 0 ] + 1 )
    TotalSum = sum( Marbles )
    TakenMarbles = range( InputData[ 2 ], InputData[ 2 ] + InputData[ 1 ] )
    TakenSum = sum( TakenMarbles )
    print( 'Case ', ( JJ + 1 ), ': ', ( TotalSum - TakenSum ), sep='' )
