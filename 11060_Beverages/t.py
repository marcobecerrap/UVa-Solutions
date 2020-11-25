import sys
from collections import defaultdict

DEBUG = False
CountCases = 0

for Input in sys.stdin:
    CountCases += 1
    
    TotalBeverages = int( Input.rstrip() )
    Beverages = []
    for BB in range( TotalBeverages ):
        Beverages.append( ( sys.stdin.readline() ).rstrip() )
    TotalRules = int( ( sys.stdin.readline() ).rstrip() )
    Rules = []
    for BB in range( TotalRules ):
        Rules.append( [ DD for DD in ( ( sys.stdin.readline() ).rstrip() ).split() ] )
    EmptyLine = sys.stdin.readline()

    if( DEBUG == True ): print( "========================" )
    if( DEBUG == True ): print( "BEVERAGES: {}".format( Beverages ) )
    if( DEBUG == True ): print( "RULES: {}".format( Rules ) )

    Index = {}    
    for II in range( len( Beverages ) ):
        Index[ Beverages[ II ] ] = II
    if( DEBUG == True ): print( "INDEXES: {}".format( Index ) )

    PostNodeList = {}
    PreNodeList = {}
    for TT in Beverages:        
        PostNodeList[ TT ] = []
        PreNodeList[ TT ] = []
    for RR in range( len( Rules ) ):    
        PostNodeList[ ( Rules[ RR ] )[ 0 ] ].append( ( Rules[ RR ] )[ 1 ] )
        PreNodeList [ ( Rules[ RR ] )[ 1 ] ].append( ( Rules[ RR ] )[ 0 ] ) 
    if( DEBUG == True ): print( "POST NODE LIST: {}".format( PostNodeList ) )
    if( DEBUG == True ): print( "PRE NODE LIST: {}".format( PreNodeList ) )

    
    PreNodeCount = {}
    for NN in Beverages:
        PreNodeCount[ NN ] = len( PreNodeList[ NN ] )
    if( DEBUG == True ): print( "PRE NODE COUNT: {}".format( PreNodeCount ) )


    PostNodeLeaves = []
    PreNodeRoots = []
    for TT in Beverages:
        if len( PostNodeList[ TT ] ) == 0:
            PostNodeLeaves.append( TT )
        if len( PreNodeList[ TT ] ) == 0:
            PreNodeRoots.append( TT )
    if( DEBUG == True ): print( "POST NODE LEAVES: {}".format( PostNodeLeaves ) )
    if( DEBUG == True ): print( "PRE NODE ROOTS: {}".format( PreNodeRoots ) )


    
    BitIndex = {}
    for NN in Beverages:
        BitIndex[ NN ] = 2 ** Index[ NN ]

    # BitPreNodes & BitPostNodes
    BitPreNodes = {}
    BitPostNodes = {}
    for NN in Beverages:
        # print( NN )
        # print( "-" )
        BitPreNodes[ NN ] = 0
        BitPostNodes[ NN ] = 0
        for PP in PreNodeList[ NN ]:
            # print( PP )
            BitPreNodes[ NN ] |= BitIndex[ PP ]
        # print( "-" )
        for PP in PostNodeList[ NN ]:
            # print( PP )
            BitPostNodes[ NN ] |= BitIndex[ PP ]
        #print( "IDX: {0:b} - Pre: {1:b} - Post: {2:b}".format( BitIndex[ NN ], BitPreNodes[ NN ], BitPostNodes[ NN ] ) )
        #print( "IDX: {} - Pre: {} - Post: {}".format( BitIndex[ NN ], BitPreNodes[ NN ], BitPostNodes[ NN ] ) )


    BitTotalPreNodes = {}
    BitTotalPostNodes = {}
    for NN in Beverages:
        BitTotalPreNodes[ NN ] = 0
        BitTotalPostNodes[ NN ] = 0
    
    Wait = 0
    for NN in PostNodeLeaves:
        Wait += 2 ** Index[ NN ]
    
    while( Wait > 0 ):
        NewWait = 0

        for WW in Beverages:
            if( ( BitIndex[ WW ] & Wait ) > 0 ): # Is in wait list
                if BitPostNodes[ WW ] == 0: # No post nodes or all postnodes have registered. 'BitTotalPostNode' is complete
                    #print( "DONE {}".format( WW ) )
                    for TT in PreNodeList[ WW ]:
                        BitTotalPostNodes[ TT ] |= ( BitIndex[ WW ] | BitTotalPostNodes[ WW ] )
                        BitPostNodes[ TT ] &= ( ~BitIndex[ WW ] ) # Substract registered node WW from PostNode lists on PreNodes
                        NewWait  &= ( ~BitIndex[ WW ] ) # Substract from NewWait list
                        NewWait |= BitIndex[ TT ] # Add PreNodes to new Wait list
                else:
                    NewWait |= BitIndex[ WW ]

        Wait = NewWait
        # print( "Wait {0:b}".format( Wait ) )
        # print( "NewWait {0:b}".format( NewWait ) )
        # print( BitPostNodes )
        # print( "===" )
        # #break

    # Here we already have the TotalPostNodes, we need to compute the TotalPreNodes
    for NN in Beverages:
        if( BitTotalPostNodes[ NN ] > 0 ):
            for KK in Beverages:
                if( ( BitIndex[ KK ] & BitTotalPostNodes[ NN ] ) > 0 ):
                    BitTotalPreNodes[ KK ] |= BitIndex[ NN ]

    # Solve the problem
    Check = 0
    for NN in Beverages:
        Check |= BitIndex[ NN ]

    SortedList = []
    while( Check > 0 ):
        #print( "CHECK: {0:b}".format( Check ) )
        #print( SortedList )
        for NN in Beverages:
            if( ( BitIndex[ NN ] & Check ) > 0 and BitTotalPreNodes[ NN ] == 0 ):
                #print( "DONE {}".format( NN ) ) 
                Check &= ( ~BitIndex[ NN ] ) # Take out of 'Check'
                SortedList.append( NN )

                # Delete NN from TotalPreNode lists
                for KK in Beverages:
                    if( ( BitIndex[ NN ] & BitTotalPreNodes[ KK ] ) > 0 ):
                        BitTotalPreNodes[ KK ] &= ( ~BitIndex[ NN ] )

                break # Breaks FOR loop every time a node without prenodes is found
                

    #print( SortedList )

    # Build output string
    print( "Case #{}: Dilbert should drink beverages in this order: {}.\n".format( CountCases, " ".join( SortedList ) ) )
