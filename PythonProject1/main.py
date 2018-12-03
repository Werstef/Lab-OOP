import module

matrix_elementsA = []
dimensionsA = module.createMatrix(matrix_elementsA) 
module.printMatrix(matrix_elementsA, dimensionsA)
module.matrixDimension(dimensionsA)

while 1 > 0:
    read = int(input("Write 1 if you want to read/modify/add an element or 0 if you want to go to the next stage: "))
    print("")
    if read == 1:
        line = int(input("Write the line in the matrix for the element you wish to search: "))
        col = int(input("Write the column in the matrix for the element you wish to search: "))
        depth = int(input("Write the depth in the matrix for the element you wish to search: "))
        print("")
        module.readWriteElement(matrix_elementsA, dimensionsA, line, col, depth)
    else:
        break


matrix_elementsUnit = []
dimensionsUnit = module.createUnitMatrix(matrix_elementsUnit)
module.printMatrix(matrix_elementsUnit, dimensionsUnit)
module.matrixDimension(dimensionsUnit)

matrix_elementsNull = []
dimensionsNull = module.createNullMatrix(matrix_elementsNull)
module.printMatrix(matrix_elementsNull, dimensionsNull)
module.matrixDimension(dimensionsNull)

print("\n\n")

print("For addition and subtraction there are 2 variants: ")
print("1) We add or substract a matrix with the same size as our first")
print("2) We add or subtract a matrix of different size as our first and make a matrix with the max sizes of both")

choose = int(input("Write 1 for option 1) and 2 for option 2)  -->  "))

if choose == 2:
    print("We will now add and subtract the next matrix created from the first one") 
    matrix_elementsB = []
    dimensionsB = module.createMatrix(matrix_elementsB) 
    module.printMatrix(matrix_elementsB, dimensionsB)
    module.matrixDimension(dimensionsB)

    print ("\n\n")

    matrix_elementsC = []
    dimensionsC = module.addSubMatrix(matrix_elementsA, dimensionsA, matrix_elementsB, dimensionsB, matrix_elementsC)
    module.printMatrix(matrix_elementsC, dimensionsC)
    module.matrixDimension(dimensionsC)
else:
    
    print("We will now create another matrix with the same size as the first one\n")
    print("REMEMBER! Choose the indices of the values you add so you will have the same size as your first matrix\n")
    while (1 > 0):
        matrix_elementsB = []
        dimensionsB = module.createMatrix(matrix_elementsB) 
        module.printMatrix(matrix_elementsB, dimensionsB)
        module.matrixDimension(dimensionsB)
        if dimensionsA[0:2] == dimensionsB[0:2]:
            print("You have entered a correct matrix, Good job!\n")
            break
        else:
            print("Error, try again and give a matrix of the same size\n")
            matrix_elementsB.clear()
            dimensionsB.clear()

    matrix_elementsC = []
    dimensionsC = module.addSubMatrix(matrix_elementsA, dimensionsA, matrix_elementsB, dimensionsB, matrix_elementsC)
    module.printMatrix(matrix_elementsC, dimensionsC)
    module.matrixDimension(dimensionsC)

    print ("\n\n")

