def createMatrix(matrix_elements):
    dimensions = []
    max_line = 0
    max_col = 0
    max_depth = 0
    number_of_values = int(input("Write the number of values that you want to include in the matrix: "))
    print("\n")

    for i in range (number_of_values):
        print("The value added must be greater than 0 and to not overlap an already entered adress! ")
        val_input = float(input("Write the value you want to add: "))
        i_input = int(input("Write the line in the matrix where you want to add the value: "))
        j_input = int(input("Write the column in the matrix where you want to add the value: "))
        k_input = int(input("Write the depth in the matrix where you want to add the value: "))
        print("\n")
            
        value_input = [i_input, j_input, k_input, val_input]
        max_line = max(max_line, value_input[0])
        max_col = max(max_col, value_input[1])
        max_depth = max(max_depth, value_input[2])
        matrix_elements.append(value_input)

    dimensions.append(max_line)
    dimensions.append(max_col)
    dimensions.append(max_depth)
    dimensions.append(number_of_values)
    return dimensions

def printMatrix(matrix_elements, dimensions):

    max_line = dimensions[0]
    max_col = dimensions[1]
    max_depth = dimensions[2]

    for k in range ( 0, max_depth):
        print("\n", end = "")
        for i in range (0, max_line):
            for j in range (0, max_col):
                ok = 0
                for iterator in matrix_elements:
                    if  (iterator[0] - 1 == i and iterator[1] - 1 == j and iterator[2] - 1 == k):
                        ok = 1
                        print(iterator[3], end = "")
                if( ok == 0 ):
                    print("0", end = "")
                print(" ", end = "")
            print("\n", end = "")
    print("")
    
def matrixDimension(dimensions):

    print("The dimensions of the matrix are: ")
    print("{} lines".format(dimensions[0]))
    print("{} columns".format(dimensions[1]))
    print("{} depth".format(dimensions[2]))
    if dimensions[3] != dimensions[0] * dimensions[1]  * dimensions[2]: 
        print("The matrix has {} elements different than 0".format(dimensions[3]))
    else:
        print("The null matrix has {} null elements ".format(dimensions[3]))
    print("")
     
def readWriteElement(matrix_elements, dimensions, line, col, depth):
    ok = False
    for i in range (0, dimensions[3]):
        if line == matrix_elements[i][0] and col == matrix_elements[i][1] and depth == matrix_elements[i][2]:
            ok = True
            print("The value of the specified addres is {}".format(matrix_elements[i][3]))
            break
    if not ok:
        print("The value of the specified address is 0 or is not yet included in the matrix")
    read = int(input("Would you like to change the value of the specified address? If yes, type 1, else type 0: "))
    print("")
    if(read == 1):
        value = float(input("Write the value you wish to put in the matrix: "))
        if(ok == True):
            matrix_elements[i][3] = value
            printMatrix(matrix_elements, dimensions)
        else:
            aux_element = [line, col, depth, value]
            matrix_elements.append(aux_element)
            if line > dimensions[0]:
                dimensions[0] = line
            if col > dimensions[1]:
                dimensions[1] = col
            if depth > dimensions[2]:
                dimensions[2] = depth
            dimensions[3] += 1
            print("\n", end = "")
            print("The value {} has been successfully added at the specified adress".format(value))
            printMatrix(matrix_elements, dimensions)
            matrixDimension(dimensions)

    return

def createUnitMatrix(matrix_elements):
    dimensions = []
    size = int(input("Write the size of the unit matrix that you want to create: "))
    dimensions.append(size)
    dimensions.append(size)
    dimensions.append(size)
    dimensions.append(size ** 2)

    for j in range (1, size + 1):
        for i in range (1, size + 1):
            element = [i, i, j, 1]
            matrix_elements.append(element)
    
    return dimensions   

def createNullMatrix(matrix_elements):
    dimensions = []
    line = int(input("Write the line size of the null matrix: "))
    col = int(input("Write the column size of the null matrix: "))
    depth = int(input("Write the depth size of the null matrix: "))
    print("")
    dimensions.append(line)
    dimensions.append(col)
    dimensions.append(depth)
    dimensions.append(line * col * depth)

    for i in range (0, line):
        for j in range (0, col):
            for k in range (0, depth):
                val = [i, j, k, 0]
                matrix_elements.append(val)


    return dimensions

def addSubMatrix(matrix_elementsA, dimensionsA, matrix_elementsB, dimensionsB, matrix_elementsC):
    dimensionsC = []
    for i in matrix_elementsA:
        matrix_elementsC.append(i)
    addSub = int(input("Write 1 if you want to add the matrixes or 0 if you want to substract the second one from the first one: "))
    if addSub == 1:
        for i in matrix_elementsC:
            for j in matrix_elementsB:
                if i[0] == j[0] and i[1] == j[1] and i[2] == j[2]:
                    i[3] += j[3]
                    matrix_elementsB.remove(j)
                    dimensionsB[3] -= 1
        matrix_elementsC.extend(matrix_elementsB)
    else:
        for i in matrix_elementsC:
            for j in matrix_elementsB:
                if i[0] == j[0] and i[1] == j[1] and i[2] == j[2]:
                    i[3] -= j[3]
                    matrix_elementsB.remove(j)
                    dimensionsB[3] -= 1
        matrix_elements_aux = matrix_elementsB
        for k in range (0, dimensionsB[3]):
            matrix_elements_aux[k][3] = - matrix_elementsB[k][3]
        matrix_elementsC.extend(matrix_elements_aux)

    max_line = max(dimensionsA[0], dimensionsB[0])
    max_col = max(dimensionsA[1], dimensionsB[1])
    max_depth = max(dimensionsA[2], dimensionsB[2])


    dimensionsC.append(max_line)
    dimensionsC.append(max_col)
    dimensionsC.append(max_depth)
    dimensionsC.append(len(matrix_elementsC))

    return dimensionsC