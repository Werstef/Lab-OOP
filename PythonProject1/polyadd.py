from numpy.polynomial import polynomial as P

def get_input_matrices(size=2):
    matrix_one = []
    for i in range(size):
        row = []
        for j in range(size):
            user_input = input ('C: ').split(' ')
            user_input = [int(number) for number in user_input]
            row.append(user_input)
        matrix_one.append(row)

    matrix_two = []
    for i in range(size):
        row = []
        for j in range(size):
            user_input = input ('C: ').split(' ')
            user_input = [int(number) for number in user_input]
            row.append(user_input)
        matrix_two.append(row)
    return matrix_one, matrix_two


def add_poly_matrices(matrix_one, matrix_two):
    size = len(matrix_one)
    output_matrix = []
    for i in range(size):
        row = []
        for j in range(size):
            sum = P.polyadd(matrix_one[i][j], matrix_two[i][j])
            row.append(sum)
        output_matrix.append(row)
    return output_matrix

matrix_one, matrix_two = get_input_matrices()
output_matrix = add_poly_matrices(matrix_one, matrix_two)
print(output_matrix)
