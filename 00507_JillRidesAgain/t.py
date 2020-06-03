import sys

DebugOn = False

NCases = int( sys.stdin.readline() )

for AA in range( NCases ):

    if( DebugOn == True ):
        print( "---------" )
        print( "Case %d" % ( AA + 1 ) )

    # Get Data
    StreetSize = int( sys.stdin.readline() )
    Street = []
    for BB in range( StreetSize - 1 ):
        Street.append( int( sys.stdin.readline() ) )
        
    if( DebugOn == True ):
        print( "Street" )
        print( repr( Street ) )
    
    SatCount = 0
    SatList = []
    SatCoords = []
    rawCoord = 0
    colCoord = 0


    for CC in range( 0, len( Street ) ):
        Inter = SatCount + Street[ CC ]
        if( Inter >= 0 ):
            SatCount += Street[ CC ]
            SatList.append( SatCount )
            SatCoords.append( [ rawCoord, colCoord ] )
            colCoord += 1
        else: 
            SatCount = 0
            rawCoord = CC + 1
            colCoord = CC + 1

    if( DebugOn == True ):
        print( "Sat" )
        print( repr( SatList ) )
        print( repr( SatCoords ) )


    if( len( SatList ) > 0 ):
        MaxSat = max( SatList )
    else:
        MaxSat = 0

  

    if( MaxSat <= 0 ):
        print( "Route %d has no nice parts" % ( AA + 1 ) )
    else:
        MaxCoords = []
        Difference = []
        for KK in range( len( SatList ) ):
            if( SatList[ KK ] == MaxSat ):
                Coord = list( sorted( SatCoords[ KK ] ) )
                MaxCoords.append( Coord.copy() )
                Difference.append( Coord[ 1 ] - Coord[ 0 ] )

        if( DebugOn == True ):
            print( "MaxCoords & Difference" )
            print( repr( MaxCoords ) )
            print( repr( Difference ) )


        MaxDifference = max( Difference )
        MaxDiffCoords = []
        for KK in range( len( MaxCoords ) ):
            if( Difference[ KK ] == MaxDifference ):
                MaxDiffCoords.append( MaxCoords[ KK ].copy() )

        MaxDiffCoords.sort()

        if( DebugOn == True ):
            print( "MaxDiffCoords" )
            print( repr( MaxDiffCoords ) )

        print( "The nicest part of route %d is between stops %d and %d" % ( ( AA + 1 ), ( MaxDiffCoords[ 0 ][ 0 ] + 1 ), ( MaxDiffCoords[ 0 ][ 1 ] + 2 ) ) )

