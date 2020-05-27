import sys

COLOUR_A = 1
COLOUR_B = 2
NO_COLOUR = 0

for InputString in sys.stdin:
    InputNodes = int( InputString )

    if InputNodes == 0:
        break
    
    InputConnections = int( sys.stdin.readline() )

    # Create list with difference references
    NodeConnectionList = [ [] for _ in range( InputNodes) ]


    for FF in range( InputConnections ):
        Read = sys.stdin.readline()
        Connection = [ int( NN ) for NN in Read.split() ]
        #print( Connection )
        NodeConnectionList[ Connection[ 0 ] ].append( Connection[ 1 ] )
        NodeConnectionList[ Connection[ 1 ] ].append( Connection[ 0 ] )
        #print( NodeConnectionList )

    for SS in range( InputNodes ):
        CleanSet = set( NodeConnectionList[ SS ].copy() )
        CleanList = list( CleanSet )
        NodeConnectionList[ SS ] = CleanList.copy()

    IsBicolourGraph = True

    IsColoured = [ 0 ] * InputNodes
    IsColoured[ 0 ] = 1
    myColour = COLOUR_B
    nextColour = COLOUR_A
    WhichColour = [ NO_COLOUR ] * InputNodes

    for FF in range( InputNodes ):

        #print( IsColoured )
        
        if IsBicolourGraph == False:
            break

        if sum( IsColoured ) == 2*len( IsColoured ):
            break

        if myColour == COLOUR_B:
            myColour = COLOUR_A
            nextColour = COLOUR_B
        else:
            myColour = COLOUR_B
            nextColour = COLOUR_A

        ChangeColoured = IsColoured.copy()

        for NN in range( InputNodes ):
            #print( '*', WhichColour )
            #print( '-', ChangeColoured )
            if IsBicolourGraph == False:
                break
            
            if IsColoured[ NN ] == 0 or IsColoured[ NN ] == 2:
                continue
            else:
                if WhichColour[ NN ] == NO_COLOUR or WhichColour[ NN ] == myColour:
                    #print( NN, WhichColour[ NN ] )
                    WhichColour[ NN ] = myColour
                    ChangeColoured[ NN ] = 2

                    for ZZ in NodeConnectionList[ NN ]:
                        if IsColoured[ ZZ ] == 0:
                            ChangeColoured[ ZZ ] = 1
                        elif WhichColour[ ZZ ] == myColour:
                            IsBicolourGraph = False
                        
                else:
                    IsBicolourGraph = False
        
        IsColoured = ChangeColoured.copy()
        
        ##########################################################

    #print( 'W', WhichColour )


    if IsBicolourGraph == True:
        print( 'BICOLORABLE.' )
    else:
        print( 'NOT BICOLORABLE.' )
    #print( InputNodes )
    #print( NodeConnectionList )
