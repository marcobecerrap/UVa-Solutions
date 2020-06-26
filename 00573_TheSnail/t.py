import sys

for InputString in sys.stdin:
    #print( "===============" )

    InputData = [ int( DD ) for DD in InputString.split() ]

    if( InputData[ 0 ] == 0 ):
        break

    WellHeight, StepUp, SlideDown, Fatigue = [ float( DD ) for DD in InputData ]
    Fatigue = Fatigue / 100

    #print( "WellHeight[" + repr( WellHeight ) + "] StepUp[" + repr( StepUp ) + "] SlideDown[" + repr( SlideDown ) + "] Fatigue[" + repr( Fatigue ) + "]" )
    
    # Simulate climbing
    ClimbHeight = 0
    FatigueDistance = StepUp * Fatigue
    EndClimbing = False
    Day = 0
    ReachedSummit = False
    while( EndClimbing == False ):
        #print( "Day[" + repr( Day + 1 ) + "] START ClimbHeigh[" + repr( ClimbHeight ) + "]" )

        # Sim sunlight
        Step = StepUp - ( Day * FatigueDistance )
        #print( "Up " + str( Step ) )
        if( Step < 0 ):
            Step = 0
        ClimbHeight = ClimbHeight + Step
        #print( "Day[" + repr( Day + 1 ) + "] DAY ClimbHeigh[" + repr( ClimbHeight ) + "]" )
        if( ClimbHeight > WellHeight ):
            ReachedSummit = True
            break

        # Sim night
        ClimbHeight = ClimbHeight - SlideDown
        #print( "Down " + str( SlideDown ) )
        #print( "Day[" + repr( Day + 1 ) + "] NIGHT ClimbHeigh[" + repr( ClimbHeight ) + "]" )
        if( ClimbHeight < 0 ):
            break
        
        Day += 1



    if( ReachedSummit == True ):
        print( "success on day " + str( Day + 1) ) 
    else:
        print( "failure on day " + str( Day + 1 ) )
