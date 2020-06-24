import sys

TotalCases = int( ( sys.stdin.readline() ).strip() )

for CC in range( TotalCases ):
    TotalWalls = int( ( sys.stdin.readline() ).strip() )
    Walls = [ int( FF ) for FF in ( ( sys.stdin.readline() ).strip() ).split() ]

    Jumps = [ ( Walls[ JJ ] - Walls[ JJ - 1 ] ) for JJ in range( 1, len( Walls ) ) ]

    PositiveJumps = [ JJ for JJ in Jumps if( JJ > 0 ) ]
    NegativeJumps = [ JJ for JJ in Jumps if( JJ < 0 ) ]

    print( "Case " + str( CC + 1 ) + ": " + str( len( PositiveJumps ) ) + " " + str( len( NegativeJumps ) ) )
