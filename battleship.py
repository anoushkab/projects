#constants
POSITION_NUMS = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
NUM_TORPEDOS = 40
BOARD_SIZE = 10

MAX_NUM = 9
MIN_NUM = 0

HIT = "X"
MISS = "O"

WELCOME_MSG = "Welcome to Battleship!"
ROW_INPUT_MSG = "Please enter row number: "
COL_INPUT_MSG = "Please enter column number: "

REPEAT_TARGET_MSG = "What are you doing? You already hit that spot."

SHIP_LIST = ["Aircraft Carrier", "Battleship", "Cruiser", "Destroyer", "Submari\
ne"]

WIN_MSG = "Congratulations, you sunk all the ships!"
LOSE_MSG = "Sorry, you didn't win. Here is where the ships were hiding."

ERROR_MSG = "That is not a valid choice, select a number between 0 and 9 inclus\
ive."

#################################################                               
# theBoard() initializes the gameboard                                          
# input    : none                                                               
# output   : theBoard ; the 2-d list                                            
def newBoard():

    theBoard = []

    for i in range(BOARD_SIZE):
        row = []

        for j in range(BOARD_SIZE):
            row.append(" ")

        theBoard.append(row)

    return theBoard

#############################################                                   
# shipLocation() adds the ships locations to the board                          
# input        : shipBoard ; the board that needs the locations added           
# output       : shipBoard ; the board with ship locations                      

def shipLocation(shipBoard):

    for a in range(2, 7):
        shipBoard[a][7] = "A"

    for b in range(0, 4):
        shipBoard[2][b] = "B"

    for c in range(3, 5):
        shipBoard[0][c] = "C"

    for d in range(5, 8):
        shipBoard[9][d] = "D"

    for s in range(5, 8):
        shipBoard[s][4] = "S"

    return shipBoard

#############################################                                   
# printBoard() prints the board with all the info displayed                     
# input      : theBoard                                                         
# output     : None                                                             

def printBoard(theBoard):

    print()
    print("    ", end="")

    for i in range(len(POSITION_NUMS)):
        print(POSITION_NUMS[i], end="   ")

    row = 0

    while row < len(theBoard):
        print()
	print("  " +  "-----------------------------------------")
        col = 0
        print(POSITION_NUMS[row], end=" | ")

        while col < len(theBoard[row]):


            print(theBoard[row][col], end=" | ")
            col += 1

        row += 1

    print()
    print("  " +  "-----------------------------------------")

    print()

##############################################                                  
# playerBoard() adds hits and misses to the gameboard                           
# input :       theBoard ; the whole gameboard                                  
#               shipPlaces ; the gameboard with the boat loactions              
#               row      ; the row number                                       
#               col      ; the col number                                       
# output: none                                                                  

def playerBoard(theBoard, shipPlaces, row, col):

    #initializes these terms                                                    
    aim = theBoard[row][col]
    target = shipPlaces[row][col]

    #only if the user does not hit any targets                                  
    if target == " ":
        theBoard[row][col] = MISS
        shipPlaces[row][col] = MISS

    #if the user hits a space they have selected before                         
    elif target == MISS or target == HIT:
        print()
        print(REPEAT_TARGET_MSG)

    #if the user hits a target                                                  
    else:
        theBoard[row][col] = HIT
        shipPlaces[row][col] = HIT
        checkShips(shipPlaces, target)

    return(theBoard)

###############################################                                 
#checkShips() checks if an entire ship has been sunken                          
# input     : theBoard ; the gameboard with the boat locations                  
# output    : none                                                              

def checkShips(theBoard, character):

    row = 0
    count = 0

    #row cannot exceed 10                                                       
    while row != BOARD_SIZE:
        #only if the character is found in this particular row                  
        if character in theBoard[row][:]:
            count += 1

        row += 1

    #if no instances of that letter have been found in the entire board         
    if count == 0:

        for i in range(len(SHIP_LIST)):
            #this finds the ship with the corresponding letter                  
            if character == SHIP_LIST[i][0:1]:
                #assigns the ship                                               
                shipType = SHIP_LIST[i]

        print()
        print("\tYou sunk the " + shipType  + "!")

###############################################                                 
# checkBoard() checks the whole board for all the of the ships                  
# input      : theBoard ; the gameboard with boat locations                     
# output     : numTargets ; the number of spaces that needs to be hit           

def checkBoard(theBoard):

    numTargets = 0

    for i in range(len(SHIP_LIST)):
        char = SHIP_LIST[i][0:1]

        for j in range(len(theBoard)):
            if char in theBoard[j][:]:
                numTargets += 1

    return numTargets

###############################################                                 
# validIntInput() gets a valid integer from the user                            
# Input  :        minimum; the min value                                        
#                 maximum; the max value                                        
#                 message; prompts the user for input                           
# Output :        givenInt ; the valid integer                                  

def validIntInput(maximum, minimum, message):

    givenInt= int(input(message))

    #makes sure the value is greater than the min                               
    while givenInt < minimum:

        print("\t", ERROR_MSG)
        givenInt = int(input(message))

    #makes sure the value is less than the max                                  
    while givenInt > maximum:

        print("\t", ERROR_MSG)
        givenInt = int(input(message))

    return givenInt
    
################################################                                
def main():

    #initializes the gameboard                                                  
    gameBoard = newBoard()

    print()
    print("\t" + WELCOME_MSG)

    printBoard(gameBoard)

    #initializes the board with ship locations                                  
    boatBoard = newBoard()
    boatBoard = shipLocation(boatBoard)

    #initializes the count and number of targets                                
    count = NUM_TORPEDOS
    numTargets = checkBoard(boatBoard)

    #the loop runs until the user runs out of attempts or until                 
    #  they hit all the targets                                                 
    while count != 0 and numTargets != 0:

        if count >= 1:
            print("There are " + str(count) + " torpedos remaining.")

            #this checks the user input and then assigns it to row or col       
            rowNum = validIntInput(MAX_NUM, MIN_NUM, ROW_INPUT_MSG)
            colNum = validIntInput(MAX_NUM, MIN_NUM, COL_INPUT_MSG)

            #sends the gameBoard to playerboard to add a hit or miss            
            gameBoard = playerBoard(gameBoard, boatBoard, rowNum, colNum)

            #checks the number of tarhets left on the board                     
            numTargets = checkBoard(boatBoard)

            #board does not print when count is 1                               
            if count > 1:
                printBoard(gameBoard)

        count -= 1

    #these are the endgame statements                                           
    if numTargets == 0:
        if count == 0:
            printBoard(gameBoard)

        print("\t" + WIN_MSG)
        print()

    if count == 0 and numTargets != 0:

        print()
        print(LOSE_MSG)
        printBoard(boatBoard)


main()
