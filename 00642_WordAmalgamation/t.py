import sys


Corpus = list()
Scrambled = list()


# Read corpus
for InputString in sys.stdin:
    InputString = InputString.strip()
    if( InputString == "XXXXXX" ):
        break
    Corpus.append( InputString )

    
# Read dictionary    
for InputString in sys.stdin:
    InputString = InputString.strip()
    if( InputString == "XXXXXX" ):
        break
    Scrambled.append( InputString )

    
# Make sorted word dictionary
dicSortedCorpus = {}
for WW in Corpus:
    sortedWW = "".join( sorted( WW ) )

    if( sortedWW in dicSortedCorpus ):
        dicSortedCorpus[ sortedWW ].append( WW )
    else:
        dicSortedCorpus[ sortedWW ] = list()
        dicSortedCorpus[ sortedWW ].append( WW )

# Check if sorted scrambled words are in the sorted corpus
for WW in Scrambled:
    sortedWW = "".join( sorted( WW ) )

    if( sortedWW in dicSortedCorpus ):
        dicSortedCorpus[ sortedWW ].sort()
        for SS in ( dicSortedCorpus[ sortedWW ] ):
            print( SS )
    else:
        print( "NOT A VALID WORD" )

    print( "******" )
