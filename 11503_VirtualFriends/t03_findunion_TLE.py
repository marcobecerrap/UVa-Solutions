import sys

People = [] # Names of people
PeopleID = {} # People IDs    
PeopleParent = {} # People parent
GroupSize = {} # Size of group with Key root parent
GroupMembers = {}

def FindRootParent( Son ):
    #Group = [] # For Compression
    
    CurrentPerson = Son
    while( PeopleID[ CurrentPerson ] != PeopleParent[ CurrentPerson ] ):
        #Group.append( CurrentPerson )
        CurrentPerson = People[ PeopleParent[ CurrentPerson ] ]

    # Compress path in group by pointing everyone to the root parent
    #for PP in Group:
    #    PeopleParent[ PP ] = PeopleID[ CurrentPerson ]
    
    return CurrentPerson


TotalCases = int( ( sys.stdin.readline() ).strip() )
for CC in range( TotalCases ):

    #print( "================" )

    People.clear() # Names of people
    PeopleID.clear() # People IDs    
    PeopleParent.clear() # People parent
    GroupSize.clear()
    GroupMembers.clear()
    IDcount = 0
    
    TotalInteractions = int( ( sys.stdin.readline() ).strip() )    
    for II in range( TotalInteractions ):

        print("==============================")
        Friend_0, Friend_1 = [ FF for FF in ( ( sys.stdin.readline() ).strip() ).split() ]
        print( Friend_0 + " " + Friend_1 )

        if( Friend_0 in People ):
            pass
        else:
            People.append( Friend_0 )
            PeopleID[ Friend_0 ] = IDcount
            PeopleParent[ Friend_0 ] = IDcount
            GroupSize[ Friend_0 ] = 1
            GroupMembers[ Friend_0 ] = [ Friend_0 ]
            IDcount += 1

        if( Friend_1 in People ):
            pass
        else:
            People.append( Friend_1 )
            PeopleID[ Friend_1] = IDcount
            PeopleParent[ Friend_1 ] = IDcount
            GroupSize[ Friend_1 ] = 1
            GroupMembers[ Friend_1 ] = [ Friend_1 ]
            IDcount += 1

        #print( "ADD INTERACTION: " + Friend_0 + " " + Friend_1 )
        #print( "parents: "  + FindRootParent( Friend_0 ) + " " + FindRootParent( Friend_1 ) )
        #print( repr( People ) )


        # FIND root parents of Friends
        #RootParent_0 = FindRootParent( Friend_0 )
        #RootParent_1 = FindRootParent( Friend_1 )

        RootParent_0 = People[ PeopleParent[ Friend_0 ] ]
        RootParent_1 = People[ PeopleParent[ Friend_1 ] ]

        #print( "Parent of " + Friend_0 + " is " + RootParent_0 + ", group size is " + str( PeopleGroupSize[ RootParent_0 ] ) )
        #print( "Parent of " + Friend_1 + " is " + RootParent_1 + ", group size is " + str( PeopleGroupSize[ RootParent_1 ] ) )

        if( RootParent_0 == RootParent_1 ):
            print( str( GroupSize[ RootParent_0 ] ) )
        else:
            # UNION of groups
            TotalGroupSize = GroupSize[ RootParent_0 ] + GroupSize[ RootParent_1 ]
            if( GroupSize[ RootParent_0 ] > GroupSize[ RootParent_1 ] ):
                #PeopleParent[ RootParent_1 ] = PeopleID[ RootParent_0 ]
                GroupMembers[ RootParent_0 ] = GroupMembers[ RootParent_0 ] + GroupMembers[ RootParent_1 ]
                GroupSize[ RootParent_0 ] += GroupSize[ RootParent_1 ]
                for MM in GroupMembers[ RootParent_1 ]:
                    PeopleParent[ MM ] = PeopleID[ RootParent_0 ]
                del GroupMembers[ RootParent_1 ]
                print( str( GroupSize[ RootParent_0 ] ) )
            else:
                #PeopleParent[ RootParent_0 ] = PeopleID[ RootParent_1 ]
                GroupMembers[ RootParent_1 ] = GroupMembers[ RootParent_0 ] + GroupMembers[ RootParent_1 ]
                GroupSize[ RootParent_1 ] += GroupSize[ RootParent_0 ]
                for MM in GroupMembers[ RootParent_0 ]:
                    PeopleParent[ MM ] = PeopleID[ RootParent_1 ]
                del GroupMembers[ RootParent_0 ]                
                print( str( GroupSize[ RootParent_1 ] ) )

        print( "People " + repr( PeopleID ) )
        print( "Parent " + repr( PeopleParent ) )
        print( "Groups " + repr( GroupMembers ) )

            
            



