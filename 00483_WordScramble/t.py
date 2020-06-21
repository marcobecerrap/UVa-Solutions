import sys

DebugOn = False

for InputString in sys.stdin:

    InputString = InputString.rstrip()

    Words = [ str( N ) for N in InputString.split() ]

    if( DebugOn ):
        print( repr( Words ) )

    ReversedString = ""
    IDX = 0
    WW = 0
    while( IDX < len( InputString ) ):
        
        if( ( Words[ WW ] )[ 0 ] == InputString[ IDX ] ):
            ReversedString += ( Words[ WW ] )[ len( Words[ WW ] ) : : -1 ]
            IDX += len( Words[ WW ] )
            WW += 1
        else:
            ReversedString += InputString[ IDX ]
            IDX += 1

    print( ReversedString )
        
        
    


    
            


