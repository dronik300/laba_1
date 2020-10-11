#include <iostream>
using namespace std;

class matrix
{
    int Row, Col;  //������ � �������
    double** Value;  // �������� �������
public:

    matrix(int, int);  //�����������
    matrix(const matrix&); //���������� ����������� - ������� ����� ������� m
    int GetRow(); //����� �������� �������� ����� �����
    int GetCol(); //����� �������� �������� ����� ��������

    friend ostream& operator<<(ostream& ostr, matrix& m);//���������� ��������� ������
    friend istream& operator>>(istream& istr, matrix& m);//���������� ��������� �����
    friend matrix operator-(matrix& m1, matrix& m2);//���������� ��������� ����� (��������)
    friend bool operator== (matrix& m1, matrix& m2);//���������� ��������� ���������

    ~matrix(); //����������

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
    Row = row;  //���������� Row � Col ����������� �������� �������� ����� ����� � �������� �������
    Col = col;
    Value = new double* [row];  //����������� ������� ��������� ������������ ������
    for (int i = 0; i < row; i++) Value[i] = new double[col];
}

matrix::matrix(const matrix& m) //���������� ����������� - ������� ����� ������� m
    :Row(m.Row), Col(m.Col)
{
    Value = new double* [Row];
    for (int i = 0; i < Row; i++)  Value[i] = new double[Col];
    for (int i = 0; i < Row; i++)
    {
        for (int j = 0; j < Col; j++)
            Value[i][j] = m.Value[i][j];
    } // �������� ��������� ������� ����� ������ ��, ��� � ������� m
}

int matrix::GetRow() //������� �������� �������� ����� �����
{
    return (Row);
}

int matrix::GetCol() //������� �������� �������� ����� ��������
{
    return (Col);
}

istream& operator>>(istream& istr, matrix& m) // ���������� ��������� ����� �������
{
    for (int i = 0; i < m.GetRow(); i++)
        for (int j = 0; j < m.GetCol(); j++)
            istr >> m.Value[i][j];
    return(istr);
}

ostream& operator<<(ostream& ostr, matrix& m) //���������� ��������� ������ �������
{
    for (int i = 0; i < m.GetRow(); i++)
    {
        for (int j = 0; j < m.GetCol(); j++)
            ostr << m.Value[i][j] << "\t";
        ostr << "\n";
    }
    return(ostr);
}


matrix operator-(matrix& m1, matrix& m2) //���������� ��������� ����� (��������)
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

matrix::~matrix() //����������
{
    for (int i = 0; i < Row; i++)
        delete[] Value[i]; //���������� ������� �� ������ ������������ ������, ��������� �������������
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