import sys
import math

# Read NCases
NCases = int( sys.stdin.readline() )

while( NCases > 0 ):
    NCases -= 1
    Soldiers = int( sys.stdin.readline() )

    a = 1.0
    b = 1.0
    c = float( ( -2 ) * Soldiers )

    Solution1 = ( ( ( -1 ) * b ) + math.sqrt( ( b**2 ) - ( 4 * a * c ) ) ) / ( 2 * a )
    Solution2 = ( ( ( -1 ) * b ) - math.sqrt( ( b**2 ) - ( 4 * a * c ) ) ) / ( 2 * a )

    Solution = int( max( [ Solution1, Solution2 ] ) )
    print( Solution )
