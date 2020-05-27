import sys

InputCases = int( sys.stdin.readline() )

print( 'Lumberjacks:' )

for JJ in range( InputCases ):
    InputString = sys.stdin.readline()
    InputList = [ int( LL ) for LL in InputString.split() ]

    OrderedRight = InputList.copy()
    OrderedLeft = InputList.copy()

    OrderedRight.sort()
    OrderedLeft.sort()
    OrderedLeft.reverse()

    if OrderedRight == InputList:
        print( 'Ordered' ) 
    elif OrderedLeft == InputList:
        print( 'Ordered' )
    else:
        print( 'Unordered' )
