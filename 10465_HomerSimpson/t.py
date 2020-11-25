import sys

def PrintOutput( Eaten, T ):
    if( T == 0 ):
        print( Eaten )
    else:
        print( '{} {}'.format( Eaten, T ) )

#DEBUG = False    
for InputString in sys.stdin:
    #if( DEBUG == True ): print( "==============================" )
    Input = [ int( NN ) for NN in ( InputString.rstrip() ).split() ]
    #if( DEBUG == True ): print( Input )

    t_0 = Input[ 0 ]
    t_1 = Input[ 1 ]
    if ( t_0 > t_1 ):
        t_0, t_1 = t_1, t_0
    t_Total = Input[ 2 ]

    Served = { t_0 : 0, t_1: 0 }
    Count = t_Total // t_0
    Served[ t_0 ] = Count
    t_Left = t_Total % t_0
    MaxHamburgers = Count
    ServedLeftMin = { t_0 : Served[ t_0 ], t_1 : Served[ t_1 ] }
    #print( Served )
    #print( Count )
    #print( t_Left )


    if( len( Served.keys() ) == 1 ): # Same value for both hamburgers
        #if( DEBUG == True ): print( "case 1" )
        PrintOutput( Count, t_Left )
        continue
    elif( Count == 0 ):              # Can't eat any hamburger
        #if( DEBUG == True ): print( "case 2" )
        PrintOutput( Count, t_Left )
        continue
    elif( t_Left == 0 ):             # No time left
        #if( DEBUG == True ): print( "case 3" )
        PrintOutput( Count, t_Left )
        continue
    else:        
        GotAns = False
        t_LeftMin = t_Left
        for II in range( Count ):
            Served[ t_0 ] -= 1
            t_Left += t_0

            if( t_Left >= t_1 ):
                Served[ t_1 ] += 1
                t_Left -= t_1

            if( t_Left < t_LeftMin ):
                t_LeftMin = t_Left
                ServedLeftMin[ t_0 ] = Served[ t_0 ]
                ServedLeftMin[ t_1 ] = Served[ t_1 ]
            

            if( t_Left == 0 ):
                #if( DEBUG == True ): print( "case 4" )
                #if( DEBUG == True ): print( Served )
                PrintOutput( ( Served[ t_0 ] + Served[ t_1 ] ), 0 )
                GotAns = True
                break
        if( GotAns == False ):
            #if( DEBUG == True ): print( "case 5" )
            #if( DEBUG == True ): print( Served )
            #if( DEBUG == True ): print( ServedLeftMin )
            PrintOutput( ServedLeftMin[ t_0 ] + ServedLeftMin[ t_1 ], t_LeftMin )
            
            
        

