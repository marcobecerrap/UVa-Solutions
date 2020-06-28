import sys

TotalBlocks = int( ( sys.stdin.readline() ).strip() )

Stacks = [ [ EE ] for EE in range( TotalBlocks ) ] # Every place starts with one block in the stack
BlockInStack = [ EE for EE in range( TotalBlocks ) ] # Stack where block "n" can be found


for InputString in sys.stdin:
    #print( Stacks )
    #print( "====================" )
    #print( InputString.strip() )
    Cmd = [ EE for EE in ( InputString.strip() ).split() ]

    if( Cmd[ 0 ] == "quit" ):
        break
    else:
        BlockA = int( Cmd[ 1 ] )
        BlockB = int( Cmd[ 3 ] )
        StackA = BlockInStack[ BlockA ]
        StackB = BlockInStack[ BlockB ]
        PosA = Stacks[ StackA ].index( BlockA )
        PosB = Stacks[ StackB ].index( BlockB )
        
        if( Cmd[ 0 ] == "move" and StackA != StackB ):
            if( Cmd[ 2 ] == "onto" ):
                #===================================
                # Clean Top A
                TopA = ( Stacks[ StackA ] )[ PosA + 1 : ]
                Stacks[ StackA ] = ( Stacks[ StackA ] )[ : PosA + 1 ]
                for AA in TopA:
                    Stacks[ AA ].append( AA )
                    BlockInStack[ AA ] = AA
                # Clean Top B
                TopB = ( Stacks[ StackB ] )[ PosB + 1 : ]
                Stacks[ StackB ] = ( Stacks[ StackB ] )[ : PosB + 1 ]
                for BB in TopB:
                    Stacks[ BB ].append( BB )
                    BlockInStack[ BB ] = BB
                # Move A onto B
                Stacks[ StackA ].pop()
                Stacks[ StackB ].append( BlockA )
                BlockInStack[ BlockA ] = StackB
                #===================================
            else: # over
                #===================================
                # Clean Top A
                TopA = ( Stacks[ StackA ] )[ PosA + 1 : ]
                Stacks[ StackA ] = ( Stacks[ StackA ] )[ : PosA + 1 ]
                for AA in TopA:
                    Stacks[ AA ].append( AA )
                    BlockInStack[ AA ] = AA
                # Move A onto B
                Stacks[ StackA ].pop()
                Stacks[ StackB ].append( BlockA )
                BlockInStack[ BlockA ] = StackB
                #===================================
        elif( Cmd[ 0 ] == "pile"  and StackA != StackB ):
            if( Cmd[ 2 ] == "onto" ):
                #===================================
                # Clean Top A
                TopA = ( Stacks[ StackA ] )[ PosA : ]
                # Clean Top B
                TopB = ( Stacks[ StackB ] )[ PosB + 1 : ]
                Stacks[ StackB ] = ( Stacks[ StackB ] )[ : PosB + 1 ]
                for BB in TopB:
                    Stacks[ BB ].append( BB )
                    BlockInStack[ BB ] = BB
                # Move pile A onto B
                Stacks[ StackA ] = ( Stacks[ StackA ] )[ : PosA ]
                Stacks[ StackB ] += TopA
                for BB in TopA:
                    BlockInStack[ BB ] = StackB
                #===================================
            else: # over
                #===================================
                # Clean Top A
                TopA = ( Stacks[ StackA ] )[ PosA : ]
                # Move pile A onto B
                Stacks[ StackA ] = ( Stacks[ StackA ] )[ : PosA ]
                Stacks[ StackB ] += TopA
                for BB in TopA:
                    BlockInStack[ BB ] = StackB
                #===================================


for SS in range( TotalBlocks ):
    Output = str( SS ) + ":"
    if( len( Stacks[ SS ] ) > 0 ):
        Output += " "
    Output += " ".join( [ str( EE ) for EE in Stacks[ SS ] ] ) 
    print( Output )


        
            
            



