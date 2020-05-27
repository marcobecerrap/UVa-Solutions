import sys

InputCases = int( sys.stdin.readline() )

for JJ in range( InputCases ):
    InputItems = int( sys.stdin.readline() )
    ListString = sys.stdin.readline()
    ListItems = [ int( II ) for II in ListString.split() ]
    ListItems.sort()
    ListItems.reverse()

    Savings = 0
    for FF in range( InputItems ):
        if ( FF % 3 ) == 2:
            Savings += ListItems[ FF ]

    print( Savings )
