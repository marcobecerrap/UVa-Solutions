import sys

InputCases = int( sys.stdin.readline() )

for K in range( InputCases ):
    Count = 0
    InputLine = sys.stdin.readline()
    InputData =[ int( N ) for N in InputLine.split() ]
    if InputData[ 0 ] == 29 and InputData[ 1 ] == 2:
        StartYear = InputData[ 2 ] + 1
        EndYear = InputData[ 3 ] + 1
        for P in range( StartYear, EndYear ):
            #print( '% ', P )
            if ( P % 400 ) == 0:
                Count += 1
            elif ( P % 100 ) == 0:
                continue
            elif ( P % 4 ) == 0:
                Count += 1
            else:
                continue        
    else:
        Count = InputData[ 3 ]  - InputData[ 2 ]
    print( 'Case ', ( K + 1), ': ', Count, sep='' )
    #print( '----------' )
    

    
