import sys

for InputString in sys.stdin:
    InputList = [ int( NN ) for NN in InputString.split() ]
    #print( InputList )
    Result = 0
    for JJ in range( 1, InputList[ 0 ] + 1 ):
        Result += JJ * ( InputList[ 1 ]**JJ )
    print( Result )
