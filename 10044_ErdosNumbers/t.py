import sys

TotalCases = int( ( sys.stdin.readline() ).strip() )

for CC in range( TotalCases ):
    InputString = ( sys.stdin.readline() ).strip()

    TotalPapers, TotalTestAuthors = [ int( NN ) for NN in InputString.split() ]

    #print( str( TotalPapers ) + " - " + str( TotalTestAuthors ) )

    # Get list of authors p/ paper
    PaperAuthors = []
    for PP in range( TotalPapers ):
        PaperAuthors.append( [] )
        
        InputString = ( sys.stdin.readline() ).strip()
        Authors, Title = [ PP.strip() for PP in InputString.split( ":" ) ]
        #print( Authors )

        Names = [ NN for NN in Authors.split( "," ) ]

        for NN in range( len( Names ) ):
            if( ( NN % 2 ) == 0 ):
                continue
            else:
                PaperAuthors[ PP ].append( ( Names[ NN - 1 ].strip() + "," + Names[ NN ] ).strip() )
        #print( repr( PaperAuthors[ PP ] ) )

        
    # Get test authors
    TestAuthors = []
    TestAuthorsNotClean = []
    for AA in range( TotalTestAuthors ):
        InputString = sys.stdin.readline()
        TestAuthorsNotClean.append( InputString )
        TestAuthors.append( InputString.strip() )
    #print( repr( TestAuthors ) )

    # Make a set of authors merging the lists of paper authors
    SetAuthors = set( [] )
    for AA in PaperAuthors:
        SetAuthors = SetAuthors.union( set( AA ) )
    SetAuthors = SetAuthors.union( list( TestAuthors ) )
    # print( repr( SetAuthors ) )

    ListAuthors = list( SetAuthors )

    # Initialize the Erdos number of all authors with "infinity" (-1) in a dictionary
    AuthorErdos = {}
    for AA in ListAuthors:
        AuthorErdos[ AA ] = -1

    # Initialize dictionary with empty set of coauthors
    Coauthors = {}
    for AA in ListAuthors:
        Coauthors[ AA ] = set( [] )

    # Fill dictionary of coauthors
    for DD in PaperAuthors:
        SetCoauthors = set( DD )
        for AA in DD:
            Coauthors[ AA ] = Coauthors[ AA ].union( SetCoauthors )
            Coauthors[ AA ].discard( AA )
    #print( repr( Coauthors ) )

    # Compute Erdos Numbers
    if( "Erdos, P." in ListAuthors ):
        CurrentErdosNumber = 0
        AuthorsToBeTested = [ "Erdos, P." ]

        while( len( AuthorsToBeTested ) > 0 ):
            
            #print( repr( AuthorsToBeTested ) )

            NextSetAuthorsToBeTested = set()
            
            for AA in AuthorsToBeTested:
                ListAuthors.remove( AA )
                AuthorErdos[ AA ] = CurrentErdosNumber
                NextSetAuthorsToBeTested = NextSetAuthorsToBeTested.union( Coauthors[ AA ] )

            CurrentErdosNumber += 1

            AuthorsToBeTested.clear()
            for AA in list( NextSetAuthorsToBeTested ):
                if( AA in ListAuthors ):
                    AuthorsToBeTested.append( AA )
                    
    #print( repr( AuthorErdos ) )

    
    print( "Scenario " + str( CC + 1 ) )
    for AA in range( len( TestAuthors ) ):
        if( AuthorErdos[ TestAuthors[ AA ] ] >= 0 ):
            print( TestAuthorsNotClean[ AA ].rstrip() + " " + str( AuthorErdos[ TestAuthors[ AA ] ] ) )
        else:
            print( TestAuthorsNotClean[ AA ].rstrip() + " infinity" )
            

