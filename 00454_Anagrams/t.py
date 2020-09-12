import sys
import re
from collections import defaultdict
from itertools import product

TotalCases = int( ( sys.stdin.readline() ).strip() )
Empy = sys.stdin.readline()

TotalOutputs = []
for II in range( TotalCases ):
    InputStrings = []
    CleanStrings = []
    Anagrams = defaultdict( list )
    for InputString in sys.stdin:
        InputString = re.sub( r"\n", "", InputString )
        CleanString = re.sub( r"\s", "", InputString )
        if( CleanString == "" ):
            break
        InputStrings.append( InputString )
        CleanString = "".join( sorted( CleanString ) )
        CleanStrings.append( CleanString )
        Anagrams[ CleanString ].append( InputString )

    #print( InputStrings )
    #print( CleanStrings )
    #print( Anagrams )

    Output = list()


    for KK in Anagrams.keys():
        if( len( Anagrams[ KK ] ) > 1 ):
            relations = list( product( range( len( Anagrams[ KK ] ) ), repeat = 2 ) )
            #print( relations )

            for XX, YY in relations:
                if( XX < YY ):
                    if( ( Anagrams[ KK ] )[ XX ] <= ( Anagrams[ KK ] )[ YY ] ):
                        Output.append( ( Anagrams[ KK ] )[ XX ] + " = " + ( Anagrams[ KK ] )[ YY ] )
                    else:
                        Output.append( ( Anagrams[ KK ] )[ YY ] + " = " + ( Anagrams[ KK ] )[ XX ] )


    #print( "======" )

    OutputString = ""
    if( len( Output ) > 0 ):
        Output.sort()
        OutputString = "\n".join( Output ) + "\n"
    TotalOutputs.append( OutputString )


FinalOutput = "\n".join( TotalOutputs )
print( FinalOutput, end = "" )




    

    

        
            
            



