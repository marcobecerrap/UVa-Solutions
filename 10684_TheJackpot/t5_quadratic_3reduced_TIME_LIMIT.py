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

    # 3 - REDUCTION
    # Reduce 3 to 1 if the sum of the 3 is larger than both of the positive boundaries
    while( CanBeReduced3( Data ) == True ):            
        #print( "Can be reduced 3" )

        Red3Data = []
        Red3DataIDX = 0

        RR = 0
        while( RR < ( len( Data ) - 2 ) ):
            if( Data[ RR ] > 0 ):
                Inter = Data[ RR ] + Data[ RR + 1 ] + Data[ RR + 2 ]
                if( Inter >= Data[ RR ] and Inter >= Data[ RR + 2 ] ):
                    Red3Data.append( Inter )
                    RR += 2
                else:
                    Red3Data.append( Data[ RR ] )
            else:
                Red3Data.append( Data[ RR ] )
            RR += 1

        if( RR < len( Data ) ):
            Red3Data.append( Data[ RR ] )
            Red3Data.append( Data[ RR + 1 ] )
            
        Data = Red3Data.copy()

    
    # No gain ( len = 0 ) or nothing to reduce ( len = 1, 2 ), exit
    if( len( Data ) <= 2 ):
        if( len( Data ) > 0 ):
            MaxStreak.append( max( Data ) )
    else:    
        CumulativeMax = []
        for CC in range( 0, len( Data ), 2 ):
            PrunedData = Data[ CC : ].copy()

            # Make CumulativeData
            CumulativeData = [ Data[ CC ] ]
            for GG in range( 1, len( PrunedData ) ):
                CumulativeData.append( CumulativeData[ GG - 1 ] + PrunedData[ GG ] )
                
            CumulativeMax.append( max( CumulativeData ) )

        #print( repr( CumulativeMax ) )
        MaxStreak = CumulativeMax.copy()

    print( repr( MaxStreak ) )

    
    if( len( Data ) == 0 ):
        print( "Losing streak." )
    else:
        print( "The maximum winning streak is %d." % max( MaxStreak ) )

        
            
    

    
    #print( "----------" )

