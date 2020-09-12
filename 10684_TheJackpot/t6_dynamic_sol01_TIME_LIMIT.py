import sys


def CanBeReduced3( myData ):
    CanBeReduced = False

    if( len( myData ) <= 2 ):
        return False    
    
    for FF in range( len( myData ) - 2 ):
        if( myData[ FF ] > 0 ):
            Inter = myData[ FF ] + myData[ FF + 1 ] + myData[ FF + 2 ]
            if( Inter >= myData[ FF ] and Inter >= myData[ FF + 2 ] ):
                CanBeReduced = True                
            else:
                continue
        if( CanBeReduced == True ):
            break
        
    return CanBeReduced



while( True ):

    # Read CaseSize
    Case = []
    while( len( Case ) == 0 ):
        InputString = ( sys.stdin.readline() ).strip()
        Case = [ int( SS ) for SS in InputString.split() ]        

    CaseSize = Case[ 0 ]

    # Exit condition
    if( CaseSize == 0 ):
        break

    # Read Data
    Data = []
    while( len( Data ) < CaseSize ):
        InputData = sys.stdin.readline()
        Data += [ int( DD ) for DD in InputData.split() ]
    #print( "Data" )
    #print( repr( Data ) )

    
    MaxStreak = []

    
    # PROCESS DATA

    # 1) Delete zeros
    NoZerosData = []
    for NN in Data:
        if( NN == 0 ):
            continue
        else:
            NoZerosData.append( NN )            
    #print( "NoZeros" )
    #print( repr( NoZerosData ) )
    Data = NoZerosData.copy()


    # 2) Cluster same sign elements
    CompressedData = []
    CurrentIDX = 0
    for NN in range( len( Data ) ):
        if( NN == 0 ):
            CompressedData.append( Data[ 0 ] )
            CurrentIDX = 0
            continue
        elif( Data[ NN ] > 0 and CompressedData[ CurrentIDX ] > 0  ):
            CompressedData[ CurrentIDX ] += Data[ NN ]
        elif( Data[ NN ] < 0 and CompressedData[ CurrentIDX ] < 0  ):
            CompressedData[ CurrentIDX ] += Data[ NN ]
        else:
            CompressedData.append( Data[ NN ] )
            CurrentIDX += 1            
    #print( repr( CompressedData ) )
    Data = CompressedData.copy()


    # Del negative boundary elements
    if( len( Data ) > 0 ):
        if( Data[ 0 ] < 0 ):
            del Data[ 0 ]
    if( len( Data ) > 0 ):
        if( Data[ len( Data ) - 1 ] < 0 ):
            del Data[ len( Data ) - 1 ]            
    #print( "No negative boundaries" )
    #print( repr( Data ) )

    # No gain ( len = 0 ) or nothing to reduce ( len = 1, 2 ), exit
    if( len( Data ) <= 2 ):
        if( len( Data ) > 0 ):
            MaxStreak.append( max( Data ) )
    else:    
        CumulativeMax = []


        # Initd Additive matrix
        EmptyVector = [ 0 ] * len( Data )
        Matrix = []
        for JJ in range( len( Data ) ):
            Matrix.append( EmptyVector.copy() )

        # Start matrix values, the Data vector in the main diagonal
        for AA in range( len( Data ) ):
            Matrix[ AA ][ AA ] = Data[ AA ]

        # Fill matrix values
        for XX in range( 0, len( Data ) ):
            for YY in range( XX, len( Data ) - 1 ):
                cRow = YY + 1
                cColumn = YY - XX
                #print( "( %d, %d )" % ( YY + 1, YY - XX ) )
                if( XX == 0 ):
                    Matrix[ cRow ][ cColumn ] = Matrix[ cRow - 1 ][ cColumn ] + Matrix[ cRow ][ cColumn + 1 ]
                else:
                    Matrix[ cRow ][ cColumn ] = Matrix[ cRow - 1 ][ cColumn ] + Matrix[ cRow ][ cColumn + 1 ] - Matrix[ cRow - 1 ][ cColumn + 1 ]
                Matrix[ cColumn ][ cRow ] = Matrix[ cRow ][ cColumn ]

            #print( "----" )
                    
        #print( repr( Matrix ) )

        # Make Matrix a big vector
        MaxVector = []
        for VV in Matrix:
            #print( repr( VV ) )
            MaxVector += VV.copy()
        #print( repr( MaxVector ) )

        MaxStreak.append( max( MaxVector ) )
            

        """
        for CC in range( 0, len( Data ), 2 ):
            PrunedData = Data[ CC : ].copy()

            # Make CumulativeData
            CumulativeData = [ Data[ CC ] ]
            for GG in range( 1, len( PrunedData ) ):
                CumulativeData.append( CumulativeData[ GG - 1 ] + PrunedData[ GG ] )
                
            CumulativeMax.append( max( CumulativeData ) )
        """

        # NEED DYNAMIC PROGRAMMING

        #print( repr( CumulativeMax ) )

    #print( repr( MaxStreak ) )

    
    if( len( Data ) == 0 ):
        print( "Losing streak." )
    else:
        print( "The maximum winning streak is %d." % max( MaxStreak ) )

        
            
    

    
    #print( "----------" )

