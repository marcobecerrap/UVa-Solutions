import sys

for InputString in sys.stdin:
    [ ListSize, ConstraintSize] = [ int( NN ) for NN in InputString.split()  ]
    #print( M, '-', N )

    if ListSize == 0 and ConstraintSize == 0:
        break

    
    ConstraintList = []
    #PrintConstraintList = []
    for TT in range( ConstraintSize ):
        InputConstraint = sys.stdin.readline()
        CC = [ int( SS ) for SS in InputConstraint.split() ]
        ConstraintList.append( [ CC[ 0 ] - 1, CC[ 1 ] - 1 ] )
        #PrintConstraintList.append( [ CC[ 0 ], CC[ 1 ] ] )
        
    ConstraintList.sort()
    ConstraintList.reverse()
    #print( ConstraintList )

    #PrintConstraintList.sort()
    #PrintConstraintList.reverse()
    #print( PrintConstraintList )

    UsedList = [ False ] * ListSize

    OrderedList = []
    for FF in ConstraintList:
        if UsedList[ FF[ 1 ] ] == False:
            UsedList[ FF[ 1 ] ] = True
            if UsedList[ FF[ 0 ] ] == False:
                OrderedList = [ FF[ 1 ] ] + OrderedList
            else:
                Idx = OrderedList.index( FF[ 0 ] )
                OrderedList = OrderedList[ 0 : (Idx + 1 ) ] + [ FF[ 1 ] ] + OrderedList[ Idx+1 : len( OrderedList ) ]
                
        if UsedList[ FF[ 0 ] ] == False:
            UsedList[ FF[ 0 ] ] = True
            OrderedList = [ FF[ 0 ] ] + OrderedList

    for RR in range( len( UsedList ) ):
        if UsedList[ RR ] == False:
            OrderedList = [ RR ] + OrderedList

    for GG in range( len( OrderedList ) ):
        OrderedList[ GG ] += 1

    #print( str( OrderedList ) )
    print( ' '.join( str( XX ) for XX in OrderedList ) )
