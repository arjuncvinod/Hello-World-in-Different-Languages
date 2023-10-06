def add_matrices(matrix1, matrix2):
    # Check if the dimensions of the matrices are the same
    if len(matrix1) != len(matrix2) or len(matrix1[0]) != len(matrix2[0]):
        return None  # Return None if dimensions don't match
    
    result = []
    
    # Iterate through the rows
    for i in range(len(matrix1)):
        row = []
        # Iterate through the columns
        for j in range(len(matrix1[0])):
            row.append(matrix1[i][j] + matrix2[i][j])
        result.append(row)
    
    return result

# Input for matrix1
matrix1 = []
rows1 = int(input("Enter the number of rows for matrix  1: "))
cols1 = int(input("Enter the number of columns for matrix 1: "))
print("Enter the elements of matrix 1:")

for i in range(rows1):
    row = []
    for j in range(cols1):
        element = int(input(f"Enter element at row {i+1}, column {j+1}: "))
        row.append(element)
    matrix1.append(row)

# Input for matrix2
matrix2 = []
rows2 = int(input("Enter the number of rows for matrix 2: "))
cols2 = int(input("Enter the number of columns for matrix 2: "))
print("Enter the elements of matrix 2:")

for i in range(rows2):
    row = []
    for j in range(cols2):
        element = int(input(f"Enter element at row {i+1}, column {j+1}: "))
        row.append(element)
    matrix2.append(row)

result = add_matrices(matrix1, matrix2)

if result:
    for row in result:
        print(row)
else:
    print("Matrix dimensions do not match. Cannot add.")
