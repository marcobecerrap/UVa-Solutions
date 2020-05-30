import sys

def SimplifyWord( Word ):
    Word = Word.lower()
    Word = "".join( sorted( Word ) )
    return Word

Corpus = []

for InputString in sys.stdin:
    InputString = InputString.strip()

    if( InputString == "#" ):
        break

    newWords = [ str( WW ) for WW in InputString.split() ]
    Corpus += newWords


listAnagrams = list()
diccNotAnagrams = {}

for WW in Corpus:
    simpleWW = SimplifyWord( WW )
    if simpleWW in listAnagrams: # Already an anagram, nothing to do.
        continue
    elif simpleWW in diccNotAnagrams: # Just found an anagram
        del diccNotAnagrams[ simpleWW ]
        listAnagrams.append( simpleWW )
    else: # New simplified word, could be an "not anagram"
        diccNotAnagrams[ simpleWW ] =  WW

Ananagrams = list()
for KK in diccNotAnagrams:
    Ananagrams.append( diccNotAnagrams[ KK ] )

for AA in sorted( Ananagrams ):
    print( AA )
    

#print( repr( Corpus ) )
#print( repr( diccNotAnagrams ) )


    

