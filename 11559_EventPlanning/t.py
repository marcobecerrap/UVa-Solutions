import sys

for InputString in sys.stdin:
    InputData = [ int( DD ) for DD in InputString.split() ]
    Participants = InputData[ 0 ]
    Budget = InputData[ 1 ]
    NumberHotels = InputData[ 2 ]
    NumberWeeks = InputData[ 3 ]

    HotelPrices = []
    HotelVacancy = []

    #Read data
    for JJ in range( NumberHotels ):
        InputPrice = int( sys.stdin.readline() )
        HotelPrices.append( InputPrice )
        InputVacancy =  sys.stdin.readline()
        VacancyList = [ int( VV ) for VV in InputVacancy.split() ]
        HotelVacancy.append( VacancyList )

    #print( HotelPrices )
    #print( HotelVacancy )

    #Build lists for every week
    CostList=[]
    for TT in range( NumberWeeks ):
        WeekPriceVacancy=[]
        for YY in range( NumberHotels ):
            WeekPriceVacancy.append( [ HotelPrices[ YY ], HotelVacancy[ YY ][ TT ] ] )

        WeekPriceVacancy.sort()

        ToBeHosted = Participants
        TotalCost = 0
        for YY in range( NumberHotels ):
            if ToBeHosted == 0:
                break
            
            Available = WeekPriceVacancy[ YY ][ 1 ]

            if Available >= ToBeHosted:
                TotalCost += WeekPriceVacancy[ YY ][ 0 ] * ToBeHosted
                ToBeHosted = 0

        if ToBeHosted == 0:
            CostList.append( TotalCost )

        #print( WeekPriceVacancy )

    CostList.sort()

    if len( CostList ) == 0:
        print( 'stay home' )
    elif CostList[ 0 ] <= Budget:
        print( CostList[ 0 ] )
    else:
        print( 'stay home' )
        
    #print( 'TOTAL COST' )
    #print( CostList )

    
        
            
        
        
        
        
        
        
    
