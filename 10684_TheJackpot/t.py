import sys


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
            MaxStreak = Data[ 0 ]
    else:    

        Cumulative = [ Data[ 0 ] ]
        Count = Data[ 0 ]        
        for II in range( 1, len( Data ) ):
            if( ( Count + Data[ II ] ) >= 0  ):
                Count += Data[ II ]
                Cumulative.append( Count )
            else:
                Count = 0

        MaxStreak = max( Cumulative )
            

        
    if( len( Data ) == 0 ):
        print( "Losing streak." )
    else:
        print( "The maximum winning streak is %d." % MaxStreak )

        
            
    

    
    #print( "----------" )

