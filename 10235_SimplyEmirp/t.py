import sys

commentsAllowed = True


#Make cribe
cribeLimit = 1000000
primeCribe = [ True ] * cribeLimit
primeCribe[ 0 ]  = False
primeCribe[ 1 ] =  False

idx = 2
while( idx < cribeLimit ):
    if primeCribe[ idx ] == False:
        idx += 1
        continue
    else:
        #if commentsAllowed:
        #    print( str( idx ) + " is prime" )
        prime = idx
        multiple = prime * 2
        while( multiple < cribeLimit ):
            primeCribe[ multiple ] = False
            multiple += prime
        idx += 1


for InputString in sys.stdin:

    Num = int( InputString )
    strNum = str( Num )
    strRevNum = strNum[ len( strNum ): : -1 ]
    RevNum = int( strRevNum )

    isPrime = False
    isEmirp = False
    if primeCribe[ Num ] == True:
        isPrime = True
        if primeCribe[ RevNum ] == True and RevNum != Num:
            isEmirp = True
            print( str( Num ) + " is emirp." )
        else:
            print( str( Num ) + " is prime." )
    else:
        print( str( Num ) + " is not prime." )

    #print( "Num: " + str( Num ) + " - Rev: " + str( RevNum ) )
