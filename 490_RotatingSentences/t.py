import sys

StringList = list()
StringListSize = list()


for InputString in sys.stdin:

    InputString = InputString.rstrip()

    StringList.append( InputString )
    StringListSize.append( len( InputString ) )


MaxStringSize = max( StringListSize )

FWD = 0
while( FWD < len( StringList )  ):
    if( StringListSize[ FWD ] < MaxStringSize ):
        Difference = ( MaxStringSize - StringListSize[ FWD ] )
        StringListSize[ FWD ] = MaxStringSize
        StringList[ FWD ] = StringList[ FWD ] + ( ' ' * Difference )
    FWD += 1



StringList.reverse()
StringListSize.reverse()

for NN in range( MaxStringSize ):
    Row = ""
    for FF in range( len( StringList ) ):
        Row += ( StringList[ FF ] )[ NN ]
    print( Row )
    


    
            


