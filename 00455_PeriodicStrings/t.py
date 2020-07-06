import sys
import re

TotalCases = int( ( sys.stdin.readline() ).strip() )

PeriodicPattern = re.compile( r"^(.+?)\1*$" )

Output = []
for _ in range( TotalCases ):
    Blank = sys.stdin.readline()
    InputString = ( sys.stdin.readline() ).rstrip()

    Pattern = PeriodicPattern.findall( InputString )
    Output.append( str( len( Pattern[ 0 ] ) ) )

print( "\n\n".join( Output ) )
    

        
            
            



