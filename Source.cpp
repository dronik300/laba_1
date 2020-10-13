#include <iostream>
using namespace std;

int input_check(char s[])
{
    int i = 0, n = 0;
    while (s[i])
    {
        if (int(s[i]) >= 48 && int(s[i]) <= 57)
            n = n * 10 + int(s[i] - 48);
        else
        {
            cout << "Vvedeno ne chislo, vvedite chislo\n";
            cin >> s;
            return input_check(s);
        }
        i++;
    }
    return n;
}

class matrix
{
    int Row, Col;  
    int** Value;

public:
    matrix()
    {
        Row = 0;
        Col = 0;
        Value = new int* [Row];
        for (int i = 0; i < Row; i++)
            Value[i] = new int[Col];
        for (int i = 0; i < Row; i++)
            for (int j = 0; j < Col; j++)
                Value[i][j] = 0;
    }

    matrix(int, int);  //конструктор
    matrix(int, int, int**);  //конструктор
    matrix(const matrix&); //копирующий конструктор - создает копию объекта m
    void Print_element(int , int j);
    void Set_element(int, int, int);
    int GetRow(); //число строк
    int GetCol(); //число столбцов

    friend ostream& operator<<(ostream& ostr, matrix& m);//перегрузка оператора вывода
    friend istream& operator>>(istream& istr, matrix& m);//перегрузка оператора ввода
    friend matrix operator-(matrix& m1, matrix& m2);//перегрузка минуса 
    friend bool operator== (matrix& m1, matrix& m2);//перегрузка сравнения

    ~matrix(); 

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
        int** tmp = Value; Value = m.Value; m.Value = tmp;
    }

};


matrix::matrix(int row, int col, int** mas)
{
    Row = row;  
    Col = col;
    Value = new int* [row];  
    for (int i = 0; i < row; i++) Value[i] = new int[col];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            Value[i][j] = mas[i][j];
}

matrix::matrix(int row, int col)
{
    Row = row;
    Col = col;
    Value = new int* [row];
    for (int i = 0; i < row; i++) Value[i] = new int[col];
}

matrix::matrix(const matrix& m) //копирующий конструктор - создает копию матрицы m
    :Row(m.Row), Col(m.Col) // инициализация строк и столбцов
{
    Value = new int* [Row];
    for (int i = 0; i < Row; i++)  Value[i] = new int[Col];
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
            Value[i][j] = m.Value[i][j];
    }
}
int matrix::GetRow() //число строк
{
    return (Row);
}

int matrix::GetCol() //число столбцов
{
    return (Col);
}

void matrix::Print_element(int i, int j)
{
    cout << Value[i][j] << "\n";
}

void matrix::Set_element(int i, int j, int num)
{
    Value[i][j]=num;
}

istream& operator>>(istream& in, matrix& m) // ввод матрицы
{
    for (int i = 0; i < m.GetRow(); i++)
        for (int j = 0; j < m.GetCol(); j++)
            in >> m.Value[i][j];
    return(in);
}

ostream& operator<<(ostream& out, matrix& m) //вывод матрицы
{
    for (int i = 0; i < m.GetRow(); i++)
    {
        for (int j = 0; j < m.GetCol(); j++)
            out << m.Value[i][j] << "\t";
        out << "\n";
    }
    return(out);
}


matrix operator-(matrix& m1, matrix& m2) //перегрузка минуса
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

matrix::~matrix() 
{
    for (int i = 0; i < Row; i++)
        delete[] Value[i];
    delete[] Value;
}

int main()
{
    matrix a,b,c,d;
    matrix mas[3];
    int** el;
    int i, j, row, col,k, num;
    char data[10];
    for( k=0; k<3; k++)
    {
        cout << "enter Row \n";
        cin >> data;
        row = input_check(data);
        cout << "enter Col\n";
        cin >> data;
        col = input_check(data);
        el = new int* [row];
        for (int i = 0; i < row; i++)
            el[i] = new int[col];
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                cin >> data;
                el[i][j] = input_check(data);
            }
        mas[k] = { row, col, el };
    }

    cout << "--------------------------------\n";
    cout << "mas[1]\n";
    cout << mas[0];

    cout << "--------------------------------\n";
    cout << "mas[2]\n";
    cout << mas[1];

    cout << "--------------------------------\n";
    cout << "mas[3]\n";
    cout << mas[2];
    cout << "--------------------------------\n";

    cout << "enter row\n";
    cin >> data;
    row = input_check(data);
    cout << "enter col\n";
    cin >> data;
    col = input_check(data);
    cout << "enter mas index\n";
    cin >> data;
    k = input_check(data);
    mas[k-1].Print_element(row-1,col-1);

    cout << "enter row\n";
    cin >> data;
    row = input_check(data);
    cout << "enter col\n";
    cin >> data;
    col = input_check(data);
    cout << "enter num\n";
    cin >> data;
    num = input_check(data);
    cout << "enter mas index\n";
    cin >> data;
    k = input_check(data);
    mas[k-1].Set_element(row-1, col-1,num);
    cout << mas[k-1] << "\n";
    matrix raz;
    raz = mas[0] - mas[1];
    cout <<"=======================\n"<<"mas[0]-mas[1]\n"<< raz;
    return 0;
}
