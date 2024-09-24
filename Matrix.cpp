#include<iostream>

using namespace std;

class Matrix
{
private:
	int x11, x12, x21, x22;

public:
	Matrix(int x11, int x12, int x21, int x22)
	{
		this->x11 = x11;
		this->x12 = x12;
		this->x21 = x21;
		this->x22 = x22;
	}
	Matrix operator+ (Matrix& otherMatrix) 
	{
		Matrix sumMatrix(
			x11 + otherMatrix.x11,
			x12 + otherMatrix.x12,
			x21 + otherMatrix.x21,
			x22 + otherMatrix.x22);
		return sumMatrix;
	}
	
	Matrix operator- (Matrix& otherMatrix)
	{
		Matrix differenceMatrix(
			x11 - otherMatrix.x11,
			x12 - otherMatrix.x12,
			x21 - otherMatrix.x21,
			x22 - otherMatrix.x22
		);
		return differenceMatrix;
	}

	Matrix operator* (Matrix& otherMatrix)
	{
		Matrix productMatrix(
			x11 * otherMatrix.x11 + x12 * otherMatrix.x21,
			x11 * otherMatrix.x12 + x12 * otherMatrix.x12,
			x21 * otherMatrix.x11 + x22 * otherMatrix.x21,
			x21 * otherMatrix.x12 + x22 * otherMatrix.x22);
		return productMatrix;
		
	}

	void printMatrix()
	{
		cout << x11 << "\t" << x12 << endl;
		cout << x21 << "\t" << x22 << endl;
	}
};



int main()
{
	Matrix Matrix1(1, 2,
				   3, 4);


	Matrix OtherMatrix(5, 6,
					   7, 8);


	cout << "First Matrix: " << endl;
	Matrix1.printMatrix();

	cout << "Second Matrix: " << endl;
	OtherMatrix.printMatrix();

	Matrix sumMatrix = Matrix1 + OtherMatrix;
	Matrix differenceMatrix = Matrix1 - OtherMatrix;
	Matrix productMatrix = Matrix1 * OtherMatrix;

	cout << "Sum of the first and second matrices: " << endl;
	sumMatrix.printMatrix();
	

	cout << "Difference between the first and second matrices: " << endl;
	differenceMatrix.printMatrix();


	cout << "Product of the first and second matrices: " << endl;
	productMatrix.printMatrix();



	return 0;
}