import sys
import heapq

#Days = [ "Sa", "Su", "Mo", "Tu", "We", "Th", "Fr" ]

# Get TotalCases
TotalCases = int( ( sys.stdin.readline() ).strip() )

for CC in range( TotalCases ):

    #print( "============================" )
    
    TotalSimDays = int( ( sys.stdin.readline() ).strip() )
    TotalParties = int( ( sys.stdin.readline() ).strip() )

    #print( "SIM DAYS = " + str( TotalSimDays ) )

    PartyHartal = []
    for HH in range( TotalParties ):
        PartyHartal.append( int( ( sys.stdin.readline() ).strip() ) )
    # print( repr( PartyHartal ) )


    # Start Heap Queue with parties Hartals
    SimStrike = []
    for HH in range( TotalParties ):
        heapq.heappush( SimStrike, ( PartyHartal[ HH ], HH ) )

    #print( repr( SimStrike ) )


    # Start Simulation
    CountStrikeDays = 0
    CountWorkDays = 0
    CountWeekendDays = 0
    for DD in range( TotalSimDays + 1 ):

        NextStrike, Party = SimStrike[ 0 ]

        if( ( DD % 7 ) == 0 or ( DD % 7 ) == 6 ): # Weekend
            CountWeekendDays += 1

            # Make Strike (take out strike elements from queue)
            if( DD == NextStrike ):
                MakeStrike = True
                while( MakeStrike == True ):
                    NextStrike, Party = heapq.heappop( SimStrike )
                    heapq.heappush( SimStrike, ( ( NextStrike + PartyHartal[ Party ] ) , Party ) )

                    NextStrike, Party = SimStrike[ 0 ]
                    if( DD == NextStrike ):
                        continue
                    else:
                        MakeStrike = False                
        
        else: # Working Day
            if( DD == NextStrike ):

                CountStrikeDays += 1

                # Make Strike (take out strike elements from queue)
                MakeStrike = True
                while( MakeStrike == True ):
                    NextStrike, Party = heapq.heappop( SimStrike )
                    heapq.heappush( SimStrike, ( ( NextStrike + PartyHartal[ Party ] ) , Party ) )

                    NextStrike, Party = SimStrike[ 0 ]
                    if( DD == NextStrike ):
                        continue
                    else:
                        MakeStrike = False                
            else:
                CountWorkDays += 1

        #print( "Sim[ " + Days[ ( DD % 7 ) ] + " " + str( DD ) + " ] Work[ " + str( CountWorkDays ) + " ] Strike[ " + str( CountStrikeDays ) + " ] WE[ " + str( CountWeekendDays ) + " ] ==== " + repr( SimStrike ) )
    print( str( CountStrikeDays ) )
                
    


        
