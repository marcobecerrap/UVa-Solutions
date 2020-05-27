import sys

InputCases = int( sys.stdin.readline() )

for K in range( InputCases ):
    SizeStores = int( sys.stdin.readline() )
    InputLine = sys.stdin.readline()
    Stores = [ int( S ) for S in InputLine.split() ]
    MaxStore = max( Stores )
    MinStore = min( Stores )
    print( 2*( MaxStore - MinStore ) )



    
