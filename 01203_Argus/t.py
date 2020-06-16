import sys

# Get Data
QueryDicc = {}
for InputString in sys.stdin:
    
    InputString = InputString.strip()
    if( InputString == "#" ):
        break
    else:
        SplitElements = [ NN for NN in InputString.split() ]
        QueryDicc[ SplitElements[ 1 ] ] = int( SplitElements[ 2 ] )

InputString = sys.stdin.readline()
TotalCases = int( InputString.strip() )
#print( str( TotalCases ) )
#print( repr( QueryDicc ) )

# Make initial delta list
Delta = []
for Qnum, Period in QueryDicc.items():
    Delta.append( [ Period, Qnum ] )
Delta.sort()

#print( "Sorted List" )
#print( repr( Delta[ 0:10 ] ) )


for NN in range( 1, len( Delta ) ):
    ( Delta[ NN ] )[ 0 ] -= QueryDicc[ ( Delta[ NN - 1 ] )[ 1 ] ]

#print( repr( Delta ) )


# Start simulation
Simulation = []
StepSize = []

while( sum( StepSize ) < TotalCases ):
    #print( "=============================" )
    #print( "STEP " + str( len( StepSize ) ) )
    #print( "DELTA " + repr( Delta ) )
    #print( "DELTA " + repr( Delta[0:10] ) )

    # Build TakeOut list
    TakeOut = [ ( Delta[ 0 ] )[ 1 ] ]
    Delta.pop( 0 )
    while( len( Delta ) > 0 ):
        if( ( Delta[ 0 ] )[ 0 ] == 0 ):
            TakeOut.append( ( Delta[ 0 ] )[ 1 ] )
            Delta.pop( 0 )
        else:
            break
            #print( "TAKEOUT " + repr( TakeOut ) )

    # Add TakeOut list to Simulation
    TakeOut.sort()
    Simulation.append( TakeOut.copy() )
    StepSize.append( len( TakeOut ) )

    #print( "SIMULATION " + repr( Simulation ) ) 
    #print( "STEPSIZE " + str( StepSize ) )

    # Reincorporate TakeOut elements to Delta list
    #print( "DELTA1 " + repr( Delta ) )
    for TT in TakeOut:
        Weight = QueryDicc[ TT ]
        Inserted = False
        for DD in range( len( Delta ) ):
            if( ( Weight - ( Delta[ DD ] )[ 0 ] ) > 0 ):
                Weight -= ( Delta[ DD ] )[ 0 ]                
            else:
                ( Delta[ DD ] )[ 0 ] -= Weight
                Delta.insert( DD, [ Weight, TT ] )
                Inserted = True
                break
        if( Inserted == False ):
            Delta.append( [ Weight, TT ] )
    #print( "DELTA2 " + repr( Delta ) )

#print( "=============================" )

                
# Now we print the results
Output = []
for SS in Simulation:
    NumList = [ int( NN ) for NN in SS ]
    NumList.sort()
    Output = Output + NumList
for RR in range( TotalCases ):
    print( Output[ RR ] )
