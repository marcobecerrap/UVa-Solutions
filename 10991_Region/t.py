import sys
import math

InputCases = int( sys.stdin.readline() )

for PP in range( InputCases ):
    InputString = sys.stdin.readline()
    Radius = [ float( R ) for R in InputString.split() ]
     #print( Radius )

    L_a = Radius[ 0 ] + Radius[ 1 ]
    L_b = Radius[ 1 ] + Radius[ 2 ]
    L_c = Radius[ 0 ] + Radius[ 2 ]

    A_a = math.acos( ( L_a*L_a - L_b*L_b - L_c*L_c ) / ( -2 * L_b * L_c ) )
    A_b = math.acos( ( L_b*L_b - L_a*L_a - L_c*L_c ) / ( -2 * L_a * L_c ) )
    A_c = math.acos( ( L_c*L_c - L_a*L_a - L_b*L_b ) / ( -2 * L_a * L_b ) )

    # Semiperimeter
    S = 0.5*( L_a + L_b + L_c )

    Atriangle = math.sqrt( S*( S - L_a )*( S - L_b )*( S - L_c ) )

    Apie_a = 0.5*A_a*Radius[ 2 ]*Radius[ 2 ]
    Apie_b = 0.5*A_b*Radius[ 0 ]*Radius[ 0 ]
    Apie_c = 0.5*A_c*Radius[ 1 ]*Radius[ 1 ]

    Asectors = Apie_a + Apie_b + Apie_c

    #print( 'At ', Atriangle )
    #print( 'As ', Asectors )
    print( '%.6f'%( Atriangle - Asectors ) )
    #print( '---------' )
    
    #print( 'L_a ', L_a )
    #print( 'L_b ', L_b )
    #print( 'L_c ', L_c )

    #print( 'A_a ', A_a )
    #print( 'A_b ', A_b )
    #print( 'A_c ', A_c )
