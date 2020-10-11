#include <iostream>
using namespace std;

class matrix
{
    int Row, Col;  //строки и столбцы
    double** Value;  // элементы матрицы
public:

    matrix(int, int);  //конструктор
    matrix(const matrix&); //копирующий конструктор - создает копию объекта m
    int GetRow(); //метод получает значение числа строк
    int GetCol(); //метод получает значение числа столбцов

    friend ostream& operator<<(ostream& ostr, matrix& m);//перегрузка оператора вывода
    friend istream& operator>>(istream& istr, matrix& m);//перегрузка оператора ввода
    friend matrix operator-(matrix& m1, matrix& m2);//перегрузка оператора минус (бинарный)
    friend bool operator== (matrix& m1, matrix& m2);//перегрузка оператора сравнения

    ~matrix(); //деструктор

    matrix& operator=(const matrix& m)
    {
        matrix tmp(m);
        swap(tmp);
        return *this;
    }

private:
    void swap(matrix& m)
    {
        {
            int tmp = Row; Row = m.Row; m.Row = tmp;
            tmp = Col; Col = m.Col; m.Col = tmp;
        }
        double** tmp = Value; Value = m.Value; m.Value = tmp;
    }

};


matrix::matrix(int row, int col)
{
    Row = row;  //переменным Row и Col присваиются вводимые значения числа строк и столбцов матрицы
    Col = col;
    Value = new double* [row];  //конструктор создает двумерный динамический массив
    for (int i = 0; i < row; i++) Value[i] = new double[col];
}

matrix::matrix(const matrix& m) //копирующий конструктор - создает копию матрицы m
    :Row(m.Row), Col(m.Col)
{
    Value = new double* [Row];
    for (int i = 0; i < Row; i++)  Value[i] = new double[Col];
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
            Value[i][j] = m.Value[i][j];
    } // значения элементов матрицы будут такими же, как у матрицы m
}

int matrix::GetRow() //функция получает значение числа строк
{
    return (Row);
}

int matrix::GetCol() //функция получает значение числа столбцов
{
    return (Col);
}

istream& operator>>(istream& istr, matrix& m) // перегрузка оператора ввода матрицы
{
    for (int i = 0; i < m.GetRow(); i++)
        for (int j = 0; j < m.GetCol(); j++)
            istr >> m.Value[i][j];
    return(istr);
}

ostream& operator<<(ostream& ostr, matrix& m) //перегрузка оператора вывода матрицы
{
    for (int i = 0; i < m.GetRow(); i++)
    {
        for (int j = 0; j < m.GetCol(); j++)
            ostr << m.Value[i][j] << "\t";
        ostr << "\n";
    }
    return(ostr);
}


matrix operator-(matrix& m1, matrix& m2) //перегрузка оператора минус (бинарный)
{
    matrix temp1(m1.GetRow(), m1.GetCol());
    for (int i = 0; i < m1.GetRow(); i++)
        for (int j = 0; j < m1.GetCol(); j++)
            temp1.Value[i][j] = m1.Value[i][j] - m2.Value[i][j];
    return(temp1);
}

bool operator==(matrix& m1, matrix& m2)
{
    if (m1.GetRow()!= m2.GetRow() && m1.GetCol() != m2.GetCol())
        return false;
    int i,j;
    for (i = 0; i < m1.GetRow(); i++)
        for (j = 0; j < m1.GetCol(); j++)
            if (m1.Value[i][j] != m2.Value[i][j])
                return false;
    return true;
}

matrix::~matrix() //деструктор
{
    for (int i = 0; i < Row; i++)
        delete[] Value[i]; //деструктор удаляет из памяти динамический массив, созданный конструктором
    delete[] Value;
}

int main()
{
    matrix a(2, 3);
    cout << "enter matrix a(2x3)";
    cin >> a;
    matrix b(2, 3);
    cout << "enter matrix b(2x3)";
    cin >> b;
    cout << "enter matrix c(2x2)";
    matrix c(2, 2);
    cin >> c;
    matrix d(2, 2);
    cout << "enter matrix d(2x2)";
    cin >> d;
    if (b == c)
        cout << "b==c";
    d= d - c;
    cout << d;
    return 0;
}