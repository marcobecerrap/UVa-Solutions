import sys

for InputString in sys.stdin:
    Input = [ int( I ) for I in InputString.split() ]
    #print( Input )
    
    if Input[ 0 ] == 0 and Input[ 1 ] == 0 and Input[ 2 ] == 0 and Input[ 3 ] == 0 and Input[ 4 ] == 0:
        break
    
    Count = 0
    for XX in range( Input[ 4 ] + 1 ):
        F = Input[ 0 ]*XX*XX + Input[ 1 ]*XX + Input[ 2 ]
        if ( F % Input[ 3 ] ) == 0:
            Count += 1
    print( Count )
    #print( '---------' )
            
