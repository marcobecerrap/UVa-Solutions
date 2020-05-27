import sys
import statistics

commentsAllowed = False

InputCases = int( sys.stdin.readline() )

for InputString in sys.stdin:
    InputData = [ int( N ) for N in InputString.split() ]

    Houses = InputData[ 1:len( InputData ) ]

    #Get Median
    VitoHouse = statistics.median( Houses )

    TotalDistance = 0
    for Num in Houses:
        TotalDistance += abs( Num - VitoHouse )

    print( str( int( TotalDistance ) ) )
