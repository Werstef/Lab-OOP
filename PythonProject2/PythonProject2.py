import matrix

MatrixA = matrix.Matrix()
print("This is our starting matrix")
for i in range(10):
    for j in range (10):
        print(MatrixA.listofElements[i][j], end = " ")
    print("")

MatrixA.createLines()
MatrixA.createBZone()
print("\n")
print("This is our matrix after the lines and the 'b' zone have been randomly selected")
for i in range(10):
    for j in range (10):
        print(MatrixA.listofElements[i][j], end = " ")
    print("")

MatrixA.playGame()
print("\n")
