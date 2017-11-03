Assigment no 2 in C++

Leveres innen 20 nov innen 23:59  Poeng 1 Må leveres en filopplasting Tilgjengelig 25 okt i 0:00–21 nov i 23:59 28 dager
Write a c++ program for matrix multiplication with following specifications:


Part 1>
	Use constructor dynamic memory allocation for matrix
	Use getdata() function to input values for matrix
	Use show() to display the matrix
	Use mul() to multiply two matrices
	
	Example Output:
		enter m,n:2 2

		Enter the matrix of size2x2
		2 3
		2 3

		Enter the matrix of size2x2
		4 5
		4 5

		The matrix for object p:
		2 3
		2 3

		The matrix for object q:
		4 5
		4 5

		The resultant matrix
		20 25
		20 25

		
Part 2>
	Use operator*() for matrix multiplication instead of mul()
	Make operator*() as friend function
 
 
Part 3>
	To perform the write operation to a file in addition to screen.
	Output:

	Enter File name: one.txt

	Enter contents to store in file



Example of design:
	matrix
	**a
	 m,n

	matrix()
	void getdata()
	void show()
	~matrix()
	mul(matrix &x,matrix &y)
	operator*(matrix &x,matrix &y)
