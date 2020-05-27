import sys

InputCases = int( sys.stdin.readline() )
for KK in range( InputCases ):
    Medicine = int( sys.stdin.readline() )
    print( 'Case #', ( KK + 1 ), ': ', ( 2*( Medicine - 1 ) + 1 ), sep='' )
