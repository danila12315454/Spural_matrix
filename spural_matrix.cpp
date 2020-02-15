#include<iostream>
using namespace std;

int** init_matrix(int**,int);
void print(int**, int);
int** spiral(int**, int);

int main()
{
int size;
cin >> size;
int** matrix = NULL;
matrix = init_matrix(matrix, size);
spiral(matrix, size);
print(matrix, size);
return 0;
}

int** init_matrix(int** matrix, int size)
{
matrix = new int*[size];
for(int i = 0; i < size; i++)
{
matrix[i] = new int[size];
for(int j = 0; j < size; j++)
matrix[i][j] = 0;
}
return matrix;
}

void print(int** matrix, int size)
{
for(int j = 0; j < size; j++)
{
for(int i = 0; i < size; i++)
{
int width = 0;
int num = size*size;
while(num != 0)
{
num /= 10;
width++;
}
cout.width(width + 1);
cout << matrix[j][i];
}
cout << endl;
}
}

int** spiral(int** matrix, int size)
{
int value = 1, cur_str = 0, cur_cul = 0;
for(int border = 0; value < size*size + 1;border++)
{
for(cur_str = border, cur_cul = border; cur_cul < size - border; cur_cul++) matrix[cur_str][cur_cul] = value++;
for(cur_cul--, cur_str++; cur_str < size - border; cur_str++) matrix[cur_str][cur_cul] = value++;
for(cur_cul--, cur_str--; cur_cul >= border; cur_cul--) matrix[cur_str][cur_cul] = value++;
for(cur_cul++, cur_str--; cur_str > border; cur_str--) matrix[cur_str][cur_cul] = value++;
}
return matrix;
}

