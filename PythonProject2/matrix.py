import random

class Matrix:

    # instance attributes
    def __init__(self):
        self.listofElements = [['a' for it1 in range(10)] for it2 in range(10)]

    def createLines(self):
        #the lines will have the index to the lower value between the two
        #ex: if the lineX is between 5 and 6, it will have the 5 index
        self.lineX = random.randint(0, 8)
        self.lineY = random.randint(0, 8)

    def createBZone(self):
        # we decide which zone to create
        # 0 is the top left zone
        # 1 is the top right zone
        # 2 is the bottom left zone
        # 3 is the bottom right zone  
        randomZone = random.randint(0, 3)
        if(randomZone == 0):
            for it1 in range(0, self.lineX + 1):
                for it2 in range(0, self.lineY + 1):
                    self.listofElements[it1][it2] = 'b'
        if(randomZone == 1):
            for it1 in range(0, self.lineX + 1):
                for it2 in range(self.lineY + 1, 10):
                    self.listofElements[it1][it2] = 'b'
        if(randomZone == 2):
            for it1 in range(self.lineX + 1, 10):
                for it2 in range(0, self.lineY + 1):
                    self.listofElements[it1][it2] = 'b'
        if(randomZone == 3):
            for it1 in range(self.lineX + 1, 10):
                for it2 in range(self.lineY + 1, 10):
                    self.listofElements[it1][it2] = 'b'

    def correct(self, answerX, answerY):
        print("\n")
        if answerX == self.lineX and answerY == self.lineY:
            #We print the lines with +1 for each as the matrix we used was from line 0 to line 9, the problem asks for lines 1 to 10
            print("The computer has found the right lines:\nthe line between row {0} and row {1}\nthe line between column {2} and column {3}".format(answerX + 1, answerX + 2, answerY + 1, answerY + 2))
        else:
            print("The computer hasn't found the right lines, surprisingly I might add")

    def playGame(self):
        matrix_elements = self.listofElements
        if matrix_elements[0][0] == 'b' :
            corner = 0
        if matrix_elements[0][9] == 'b' :
            corner = 1
        if matrix_elements[9][0] == 'b' :
            corner = 2
        if matrix_elements[9][9] == 'b' :
            corner = 3  

        if corner == 0:
            it1 = 0
            it2 = 0
            while matrix_elements[it1][it2] != 'a':
                it2 += 1
            answerY = it2 - 1
            it2 = 0
            while matrix_elements[it1][it2] != 'a':
                it1 += 1
            answerX = it1 - 1

        if corner == 1:
            it1 = 0
            it2 = 9
            while matrix_elements[it1][it2] != 'a':
                it2 -= 1
            answerY = it2
            it2 = 9
            while matrix_elements[it1][it2] != 'a':
                it1 += 1
            answerX = it1 - 1

        if corner == 2:
            it1 = 9
            it2 = 0
            while matrix_elements[it1][it2] != 'a':
                it2 += 1
            answerY = it2 - 1
            it2 = 0
            while matrix_elements[it1][it2] != 'a':
                it1 -= 1
            answerX = it1
    
        if corner == 3:
            it1 = 9
            it2 = 9
            while matrix_elements[it1][it2] != 'a':
                it2 -= 1
            answerY = it2
            it2 = 9
            while matrix_elements[it1][it2] != 'a':
                it1 -= 1
            answerX = it1

        self.correct(answerX, answerY)