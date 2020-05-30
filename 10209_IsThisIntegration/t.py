import sys
import math

DebugOn = False

for InputString in sys.stdin:

    a_radius = float( InputString )

    alpha = ( a_radius ** 2 ) * ( 0.25 + ( math.pi / 12 ) - (  math.sqrt( 3 ) / 4 ) )
    beta = ( a_radius ** 2 ) * ( -0.5 + ( math.pi / 24 ) + ( math.sqrt( 3 ) / 4 ) )
    gamma = ( a_radius ** 2 ) * ( 1 - ( math.pi / 6 ) - ( math.sqrt( 3 ) / 4 ) )

    print( "%.3f %.3f %.3f" % ( ( 4 * alpha ), ( 8 * beta ), ( 4 * gamma ) ) )

# EXPLANATION

# When you trace the diagonals in the square of the square, three different figures are formed.
# The ones in the center are "alpha", the ones in the corner are "beta" and the ones in the edges are "gamma".

# Three "area" equations are established to make a system where we can obtain the functions of the area of these three figures, dependant to "a" (the edge / radius).
# 1) The area of the square : a**2 = 4*alpha + 8*beta + 4*gamma
# 2) The area of the 90º sector of the circle : ( PI * ( a**2 ) ) / 4 = 4*alpha + 6*beta + 2*gamma

# The last equation comes from the area of the intersection between two adjacent sectors that share an edge in the square.
# It is important to note that the adjacent edge with the intersecting vertex form an equilateral triangle. , so the area of this triangle is:
# At = ( ( 3**0.5 ) / 4 ) * ( a**2 )
# We can also get the area of the sector that covers the equilateral triangle, as the angle is 60º, the Area is:
# As = ( PI * ( a**2 ) ) / 6
# With this, we can obtain the Area of the intersecting 60º sectors:
# Ai = 2*As - At = 4*alpha + 4*beta + gamma

# We solve the system for alpha, beta and gamma, and we get the equations from the code above.


