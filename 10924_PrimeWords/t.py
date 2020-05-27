import sys

LetterValues = {
    'a':1,
    'b':2,
    'c':3,
    'd':4,
    'e':5,
    'f':6,
    'g':7,
    'h':8,
    'i':9,
    'j':10,
    'k':11,
    'l':12,
    'm':13,
    'n':14,
    'o':15,
    'p':16,
    'q':17,
    'r':18,
    's':19,
    't':20,
    'u':21,
    'v':22,
    'w':23,
    'x':24,
    'y':25,
    'z':26,
    'A':27,
    'B':28,
    'C':29,
    'D':30,
    'E':31,
    'F':32,
    'G':33,
    'H':34,
    'I':35,
    'J':36,
    'K':37,
    'L':38,
    'M':39,
    'N':40,
    'O':41,
    'P':42,
    'Q':43,
    'R':44,
    'S':45,
    'T':46,
    'U':47,
    'V':48,
    'W':49,
    'X':50,
    'Y':51,
    'Z':52
    }

# Generate prime table
PrimeTable = [None]*( 20*53 )
PrimeTable[ 0 ] = False
PrimeTable[ 1 ] = False
PrimeTable[ 2 ] = True
PrimeList = [ 2 ]
for N in range( 4 , len( PrimeTable ), 2 ):
    PrimeTable[ N ] = False

for N in range( 3, len( PrimeTable ) ):
    if PrimeTable[ N ] == None:
        PrimeTable[ N ] = True
        PrimeList.append( N )
        for P in range( ( 2*N ), len( PrimeTable ), N ):
            PrimeTable[ P ] = False
    else:
        continue
#print( PrimeList )
    
#print( len( PrimeTable ) )

for InputString in sys.stdin:    
    Letters = list( InputString.rstrip() )
    #print( Letters )
    TotalValue = 0
    for L in Letters:
        TotalValue += LetterValues[ L ]
    #print( TotalValue )

    if TotalValue == 1:
        print( 'It is a prime word.' )
        continue

    if PrimeTable[ TotalValue ] == True:
        print( 'It is a prime word.' )
    else:
        print( 'It is not a prime word.' )
    

        
    
