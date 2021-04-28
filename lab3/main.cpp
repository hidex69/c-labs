#include <iostream>


class Matrix
{
private:
	int **mx;
	int rows, cols;
public:
	friend std::ostream& operator<<(std::ostream &os, Matrix *mtx);
	int getRows() {
		return rows;
	}
	int getCols() {
		return cols;
	}
	void setRows(int rows) {
		this->rows = rows;
	}
	void setCols(int cols) {
		this->cols = cols;
	}
	void setElement(int data, int x, int y) {
		mx[x][y] = data;
	}
	int& getElement(int x, int y) {
		return mx[x][y];
	}
	Matrix(int rows1, int cols2) : rows(rows1), cols(cols2) {
		mx = new int*[rows];
		for(int i = 0; i < cols; i++) {
			mx[i] = new int[cols];
		}
		std::cout << "Matrix has created" << std::endl;
	}
	Matrix(const Matrix *mx1) {
		rows = mx1->rows;
		cols = mx1->cols;
		mx = new int*[rows];
		for(int i = 0; i < rows; i++) {
			mx[i] = new int[cols];
		}
		for(int i = 0;  i < rows; i++) {
			for(int j = 0; j < cols; j++) {
				mx[i][j] = mx1->mx[i][j];
			}
		}
	}
	Matrix() : rows(2), cols(2) {
		mx = new int*[rows];
		for(int i = 0; i < cols; i++) {
			mx[i] = new int[cols];
		}
		std::cout << "Matrix has created" << std::endl;
	}
	void inputMatrix() {
		std::cout << "Enter matrix: " << std::endl;
		int val;
		for(int i = 0; i < rows; i++) {
			for(int j = 0; j < cols; j++) {
				std::cin >> val;
				mx[i][j] = val;
			}
		}
	}
	Matrix* operator+(Matrix *mx1) {
		Matrix *result = new Matrix(rows, cols);
		for(int i = 0; i < rows; i++) {
			for(int j = 0; j < cols; j++) {
				result->mx[i][j] = mx[i][j] + mx1->mx[i][j];
			}
		}
		return result;
	}
	Matrix* operator-(Matrix *mx1) {
		Matrix *result = new Matrix(rows, cols);
		for(int i = 0; i < rows; i++) {
			for(int j = 0; j < cols; j++) {
				result->mx[i][j] = mx[i][j] - mx1->mx[i][j];
			}
		}
		return result;
	}
	~Matrix() {
		for(int i = 0; i < rows; i++) {
			delete[] mx[i];
		}
		delete[] mx;
		std::cout << "Matrix has deleted" << std::endl;
	}
};


std::ostream& operator<<(std::ostream &os, Matrix *mtx) {
		for(int i = 0; i < mtx->rows; i++) {
			for(int j = 0; j < mtx->cols; j++) {
				os << mtx->mx[i][j] << ' ';
			}
			os << '\n';
		}
		return os;
	}  


int main(int argc, char const *argv[])
{
	Matrix *mtx1 = new Matrix(2, 2);
	Matrix *mtx2 = new Matrix(2, 2);
	Matrix *mtx3 = new Matrix(2, 2);

	mtx1->inputMatrix();
	mtx2->inputMatrix();


	mtx3 = *mtx1 - mtx2;



	std::cout << "RESULT: \n" << mtx3 << std::endl;





	Matrix *mtx = new Matrix(2, 2);
	mtx->inputMatrix();


	Matrix *copy = new Matrix(mtx);


	mtx->setElement(10, 0, 0);


	std::cout << "First matrix: \n" << mtx << "Second one : \n" << copy << std::endl;  

	delete mtx;
	delete copy;




	Matrix *array = new Matrix[3];
	for(int i = 0; i < 3; i++) {
		std::cout << "Matrix N" << i + 1 << std::endl;
		array[i].inputMatrix();
	}

	delete[] array;

	system("pause");
	return 0;
}

