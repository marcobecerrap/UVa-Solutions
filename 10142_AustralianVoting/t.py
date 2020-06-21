import sys
import math

# Get TotalCases
TotalCases = int( ( sys.stdin.readline() ).strip() )
EmptyString = sys.stdin.readline()

for CC in range( TotalCases ):

    if( CC > 0 ):
        print( "" )

    # Get Candidates
    TotalCandidates = int( ( sys.stdin.readline() ).strip() )
    CandidateList = []
    for FF in range( TotalCandidates ):
        CandidateList.append( ( sys.stdin.readline() ).strip() )

    # Get Votes
    StillHaveVotes = True
    Ballot = []
    while( StillHaveVotes == True ):
        InputVote = ( sys.stdin.readline() ).strip()
        Vote = [ ( int( VV ) - 1 ) for VV in InputVote.split() ]
        if( len( Vote ) == len( CandidateList ) ):
            Ballot.append( Vote.copy() )
        else:
            StillHaveVotes = False

    EliminatedCandidates = []
    GotWinner = False    
    HalfVotes = math.floor( len( Ballot ) / 2 )

    while( GotWinner == False  ):
        
        # Make Vote Storage Dicctionary
        Votes = {}
        for AA in range( len( CandidateList ) ):
            if( AA in EliminatedCandidates ):
                continue
            else:            
                Votes[ CandidateList[ AA ] ] = 0

        # Make Voting
        for BB in Ballot:
            while( BB[ 0 ] in EliminatedCandidates ):
                BB.pop( 0 )
            Votes[ CandidateList[ BB[ 0 ] ] ] += 1

        # Check Victory Conditions
        VotesList = list( Votes.values() )
        VoteMax = max( VotesList )
        VoteMin = min( VotesList )       

        if( VoteMax > HalfVotes ):
            GotWinner = True
            for AA in range( len( CandidateList ) ):
                if( AA in EliminatedCandidates ):
                    continue
                else:
                    if( Votes[ CandidateList[ AA ] ] == VoteMax ):
                        print( CandidateList[ AA ] )
        elif( VoteMax == VoteMin ):
            GotWinner = True
            for AA in range( len( CandidateList ) ):
                if( AA in EliminatedCandidates ):
                    continue
                else:
                    if( Votes[ CandidateList[ AA ] ] == VoteMax ):
                        print( CandidateList[ AA ] )
        else:
            for AA in range( len( CandidateList ) ):
                if( AA in EliminatedCandidates ):
                    continue
                else:
                    if( Votes[ CandidateList[ AA ] ] == VoteMin ):
                        EliminatedCandidates.append( AA )

            
    

