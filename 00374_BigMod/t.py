import sys

for InputString in sys.stdin:
    B = int( InputString )
    P = int( sys.stdin.readline() )
    M = int( sys.stdin.readline() )    
    Space = sys.stdin.readline()

    Res = pow( B, P, M )
    
    print( Res )
