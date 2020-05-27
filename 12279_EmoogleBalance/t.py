import sys

Count = 1
for InputCases in sys.stdin:
    Cases = int( InputCases )
    if Cases == 0:
        break
    
    InputString = sys.stdin.readline()
    InputList = [ int( NN ) for NN in InputString.split() ]
    NoTreats = InputList.count( 0 )
    Treats = len( InputList ) - NoTreats
    #print( InputList )
    print( 'Case ', Count, ': ', ( Treats - NoTreats ), sep='' )

    Count += 1
