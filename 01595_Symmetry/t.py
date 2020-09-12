import sys

TotalCases = int( ( sys.stdin.readline() ).strip() )
#print( TotalCases )

for CC in range( TotalCases ):
    TotalCoords = int( ( sys.stdin.readline() ).strip() )
    #print( TotalCoords )
    Coords = []

    for XX in range( TotalCoords ):
        Coords.append( [ int( RR ) for RR in ( ( sys.stdin.readline() ).strip() ).split() ] )

    Coords.sort()
    #print( Coords )
    MidCoord = int( len( Coords ) / 2 )

    # Make pair list
    SCoords = []
    Center = []
    for RR in range( len( Coords ) ):
        SCoords.append( Coords[ RR ].copy() )
        if( RR == MidCoord and ( ( MidCoord * 2 ) != len( Coords ) )):
            SCoords.append( Coords[ RR ].copy() )

    # Compute CenterX (mean value X)
    CenterX = 0
    for RR in range( len( SCoords ) ):
        CenterX += ( SCoords[ RR ] )[ 0 ]
    CenterX = CenterX / len( SCoords )
    
    # Substract CenterX so all points are centered in 0    
    for RR in range( len( SCoords ) ):
        ( SCoords[ RR ] )[ 0 ] -= CenterX
    #print( SCoords )

    # Multiply by -1 all negative x-coords and delete all center points
    NoCenterCoords = []
    for RR in range( len( SCoords ) ):
        if( ( SCoords[ RR ] )[ 0 ] > 0 ):
            NoCenterCoords.append( SCoords[ RR ].copy() )
        elif( ( SCoords[ RR ] )[ 0 ] < 0 ):
            ( SCoords[ RR ] )[ 0 ] *= -1
            NoCenterCoords.append( SCoords[ RR ].copy() )
    #print( SCoords )

    # Check if all points appear two times
    NoCenterCoords.sort()
    #print( NoCenterCoords )
    IsSymmetric = True
    for RR in range( 0, len( NoCenterCoords ), 2 ):
        if( NoCenterCoords[ RR ] != NoCenterCoords[ RR + 1 ] ):
            IsSymmetric = False
            break
    
    if( IsSymmetric == True ):
        print( "YES" )
    else:
        print( "NO" )

    
    

    
