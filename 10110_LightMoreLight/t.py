import sys
import math

for InputString in sys.stdin:
    TotalBulbs = int( InputString )

    if( TotalBulbs == 0 ):
        break

    # All divisors come in pairs (on/off), with exception of an integer SQRT, which would be unique.    
    IsToggleOn = False
    SqrtTotalBulbs = int( math.sqrt( float( TotalBulbs ) ) )
    if( ( SqrtTotalBulbs**2 ) == TotalBulbs ):
        IsToggleOn = True 

    if( IsToggleOn == True  ):
        print( "yes" )
    else:
        print( "no" )
        
