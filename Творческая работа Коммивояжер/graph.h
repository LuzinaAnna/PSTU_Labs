#pragma once
#include <glut.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int n;
int** help;
int* result;
int*** mat;

int WinW;
int WinH;


bool flag = false;

const int maxSize = 20;
int amountVerts;
//Описание функций класса
template<class T>
class Graph
{
	vector<T> vertList;
	vector<T> labelList;
	bool* visitedVerts = new bool[vertList.size()];
public:
	int adjMatrix[maxSize][maxSize] = { 0 };
	Graph();
	~Graph();
	void DrawAnswer();
	void DrawGraph();
	void InsertEdge(const T& vertex1, const T& vertex2, int weight);
	void InsertVertex(const T& vertex);
	void DeleteVertex();
	int GetVertPos(const T& vertex);
	bool IsEmpty();
	bool IsFull();
	int GetAmountVerts();
	int GetAmountEdges();
	int GetWeight(const T& vertex1, const T& vertex2);
	vector<T> GetNbrs(const T& vertex);
	void Print();
};


int R;

struct vertCoord
{
	int x, y;
};
vertCoord vertC[20];

Graph<int> graph;
//Реализация матрицы смежности
void answer(int*** mat, int n, int** help, int* path)
{

	for (int l = 0; l < n; l++)
	{
		for (int i = 0; i < n; i++)
		{
			int min = 1000000;
			for (int j = 0; j < n; j++)
				if (mat[i][j] && min > *mat[i][j])
					min = *mat[i][j];
			for (int j = 0; j < n; j++)
				if (mat[i][j])
					*mat[i][j] -= min;
		}
		for (int j = 0; j < n; j++)
		{
			int min = 1000000;
			for (int i = 0; i < n; i++)
				if (mat[i][j] && min > *mat[i][j])
					min = *mat[i][j];
			for (int i = 0; i < n; i++)
				if (mat[i][j])
					*mat[i][j] -= min;
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				help[i][j] = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (mat[i][j] && !*mat[i][j])
				{
					int hmin = 1000000;
					int vmin = 1000000;

					for (int l = 0; l < n; l++)
						if (l != i && mat[l][j] && hmin > *mat[l][j])
							hmin = *mat[l][j];

					for (int l = 0; l < n; l++)
						if (l != j && mat[i][l] && vmin > *mat[i][l])
							vmin = *mat[i][l];

					help[i][j] = hmin + vmin;
				}
			}

		int mcost = 0, mi = 0, mj = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (mat[i][j] && mcost < help[i][j])
				{
					mcost = help[i][j];
					mi = i;
					mj = j;
				}
		path[mi] = mj;

		for (int i = 0; i < n; i++)
			mat[i][mj] = nullptr;

		for (int i = 0; i < n; i++)
			mat[mi][i] = nullptr;

		mat[mj][mi] = nullptr;
	}
}

//Подкотовка матрицы смежности к изменениям
void preparation(int***& mat, int& n, int**& help, int*& result)
{
	n = amountVerts;

	help = new int* [n];

	result = new int[n];

	mat = new int** [n];

	for (int i = 0; i <= n; i++)
	{
		help[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		mat[i] = new int* [n];
		for (int j = 0; j < n; j++)
		{
			if (graph.adjMatrix[i][j] == 0) {
				mat[i][j] = nullptr;
				continue;
			}
			mat[i][j] = new int(graph.adjMatrix[i][j]);
		}
	}
}

//Поиск кратчайшего пути
void tsalesman(int*** mat, int n, int** help, int* result)
{
	int* mas = new int[2];
	for (int i = 0;i < n;i++)
	{
		mas[i] = 0;
	}

	preparation(mat, n, help, result);
	int s = 0;
	answer(mat, n, help, result);
	cout << "\nОтрезки путей: ";
	for (int i = 0, j = 0; i < n; i++)
	{
		j = result[i];
		cout << i + 1 << " -> " << j + 1 << '\t';
		s += graph.adjMatrix[i][j];
	}
	cout << endl;
	cout << "\nКратчайший путь: ";
	int temp = 0;
	for (int l = 0; l < n;)
	{
		for (int i = 0, j = 0; i < n; i++)
		{
			if (temp == 0 || i + 1 == temp)
			{
				if (temp == 0) cout << i + 1;
				j = result[i];
				temp = j + 1;
				if (temp > 0)	cout << " -> " << temp;
				l++;
			}
		}
	}
	cout << "\nРасстояние: " << s;
	cout << endl;
}


template<class T>
std::vector<T> Graph<T>::GetNbrs(const T& vertex) {
	std::vector<T> nbrsList;
	int vertPos = this->GetVertPos(vertex);
	if (vertPos != (-1)) {

		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i) {
			if (this->adjMatrix[vertPos][i] != 0 &&
				this->adjMatrix[i][vertPos] != 0) 

				nbrsList.push_back(this->vertList[i]);

		}
	}
	return nbrsList;
}

//Функция добавления вершины
template<class T>
void Graph<T>::InsertVertex(const T& vertex) {
	if (!this->IsFull()) {
		this->vertList.push_back(vertex);
	}
	else {
		cout << "Граф уже заполнен.Невозможно добавить новую вершину. " << endl;
		return;
	}
}

//Функция удаления последнего элемента графа
template<class T>
void Graph<T>::DeleteVertex()
{

	this->vertList.pop_back();

}

//Функция возвращающая количество ребер
template<class T>
int Graph<T>::GetAmountEdges()
{
	int amount = 0;
	if (!this->IsEmpty())
	{ 
		for (int i = 0, vertListSize = this->vertList.size();
			i < vertListSize; ++i)
		{
			for (int j = 0; j < vertListSize; ++j)
			{
				if (this->adjMatrix[i][j] ==
					this->adjMatrix[j][i] &&
					this->adjMatrix[i][j] != 0) 
					amount += 1; 
			}
		}
		return (amount / 2); 
	}
	else
		return 0; 
}

//Функция увеличения графа
template<class T>
int Graph<T>::GetWeight(const T& vertex1, const T& vertex2) 
{
	if (!this->IsEmpty()) {
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		return adjMatrix[vertPos1][vertPos2];
	}
	return 0;
}

//Функция возвращающая количество вершин
template<class T>
int Graph<T>::GetAmountVerts()
{
	return this->vertList.size();
}

//Функция проверки на пустоту графа
template<class T>
bool Graph<T>::IsEmpty()
{
	if (this->vertList.size() != 0)
		return false;
	else
		return true;
}

//Функция проверки на  заполненность графа
template<class T>
bool Graph<T>::IsFull() 
{
	return (vertList.size() == maxSize);
}

template <class T>
int Graph<T>::GetVertPos(const T& vertex)
{
	for (int i = 0; i < this->vertList.size(); ++i)
	{
		if (this->vertList[i] == vertex)
			return i;
	}
	return -1;
}

//Обнуление матрицы смежности
template<class T>
Graph<T>::Graph()
{
	for (int i = 0; i < maxSize; ++i)
	{
		for (int j = 0; j < maxSize; ++j)
		{
			this->adjMatrix[i][j] = 0;
		}
	}
}

template<class T>
Graph<T>::~Graph()
{

}

//Функция создания графа
Graph<int> makeGraph()
{
	Graph<int> graph; //создание графа, содержащего вершины с номерами целого типа
	int amountEdges, sourceVertex, targetVertex, edgeWeight; //создание графа, содержащего вершины с номерами целого типа
	cout << "Введите количество вершин графа: "; cin >> amountVerts; cout << endl; 
	cout << "Введите количество ребер графа: "; cin >> amountEdges; cout << endl; 
	for (int i = 1; i <= amountVerts; ++i) {
		int* vertPtr = &i; 
		graph.InsertVertex(*vertPtr); 
	}

	//Растояние между вершинами подбирается с помощью рандома
	for (int i = 0; i < amountEdges; ++i)
	{
		sourceVertex=rand()%amountVerts+1; 
		int* sourceVertPtr = &sourceVertex; 

		targetVertex= rand() % amountVerts + 1;
		while (sourceVertex == targetVertex)
		{
			targetVertex = rand() % amountVerts + 1;
		}
		int* targetVertPtr = &targetVertex; 

		edgeWeight=rand()%100+1; 
		graph.InsertEdge(*sourceVertPtr, *targetVertPtr, edgeWeight); 
	}
	return graph;
}

//Функция добавления ребра
template<class T>
void Graph<T>::InsertEdge(const T& vertex1, const T& vertex2, int weight)
{
	if (this->GetVertPos(vertex1) != (-1) && this->GetVertPos(vertex2) != (-1)) 
	{
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		if (this->adjMatrix[vertPos1][vertPos2] != 0
			&& this->adjMatrix[vertPos2][vertPos1] != 0) 
		{
			return;
		}
		else
		{
			this->adjMatrix[vertPos1][vertPos2] = weight;
			this->adjMatrix[vertPos2][vertPos1] = weight;
		}
	}
	else
	{
		cout << "Обеих вершин (или одной из них) нет в графе " << endl;
		return;
	}
}

//Функция вывода матрицы смежности
template<class T>
void Graph<T>::Print()
{
	if (!this->IsEmpty()) 
	{
		cout << "Матрица смежности графа: " << endl;
		cout << "  ";
		for (int i = 1, vertListSize = this->vertList.size(); i <= vertListSize; ++i)
		{
			cout << i << "\t ";
		}
		cout << endl;
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i)
		{
			cout << this->vertList[i] << " ";
			for (int j = 0; j < vertListSize; ++j)
			{
				cout << " " << this->adjMatrix[i][j] << "\t ";
			}
			cout << endl;
		}

	}
}

//Функция задания координат вершинам
void setCoord(int i, int n)
{
	int R_;

	int x0 = WinW / 2;
	int y0 = WinH / 2;
	if (WinW > WinH)
	{
		R = 5 * (WinH / 13) / n;
		R_ = WinH / 2 - R - 10;
	}
	else
	{
		R = 5 * (WinW / 13) / n;
		R_ = WinW / 2 - R - 10;
	}
	float theta = 2.0f * 3.1415926f * float(i) / float(n);
	float y1 = R_ * cos(theta) + y0;
	float x1 = R_ * sin(theta) + x0;

	vertC[i].x = x1;
	vertC[i].y = y1;
}

//Функция отрисовки кругов
void drawCircle(int x, int y, int R) 
{
	glColor3f(1.0, 1.0, 1.0);
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 720; i++)
	{
		float theta = 2.0f * 3.141592653f * float(i) / float(720);
		y1 = R * cos(theta) + y;
		x1 = R * sin(theta) + x;;
		glVertex2f(x1, y1);
	}
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	float x2, y2;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 720; i++)
	{
		float theta = 2.0f * 3.141592653f * float(i) / float(720);
		y2 = R * cos(theta) + y;
		x2 = R * sin(theta) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
}

//Функция печати длины путей
void drawText(int nom, int x1, int y1)
{
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;
	string s = to_string(nom);
	glRasterPos2i(x1 - 5, y1 - 5);
	for (int j = 0; j < s.length(); j++)
		glutBitmapCharacter(font, s[j]);
}

//Функция отрисовки вершины с номером
void drawVertex(int n)
{
	for (int i = 0; i < n; i++)
	{
		drawCircle(vertC[i].x, vertC[i].y, R);
		drawText(i + 1, vertC[i].x, vertC[i].y);
	}
}

//Функция отрисовки ребра между вершинами
void drawLine(int text, int x0, int y0, int x1, int y1)
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();

	drawText(text, (x0 + x1) / 2 + 10, (y0 + y1) / 2 + 10);
}

//Функция отрисовки ребер кратчайшего пути
void Line( int x0, int y0, int x1, int y1)
{
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();
}

//Функция отрисовки графа
template<class T>
void Graph<T>::DrawGraph()
{
	int n = vertList.size();
	for (int i = 0; i < n; i++)
	{
		setCoord(i, n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int a = adjMatrix[i][j];
			if (a != 0)
			{
				drawLine(a, vertC[i].x, vertC[i].y, vertC[j].x, vertC[j].y);
			}
		}
	}
	drawVertex(n);
}

void reshape(int w, int h)
{
	WinW = w;
	WinH = h;
	glViewport(0, 0, (GLsizei)WinW, (GLsizei)WinH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)WinW, 0, (GLdouble)WinH);
	glutPostRedisplay();
}

//Функция печати текста внутри кнопок действий
void drawMenuText(string text, int x1, int y1)
{
	GLvoid* font = GLUT_BITMAP_HELVETICA_18;
	string s = text;
	glRasterPos2i(x1 + 5, y1 - 20);
	for (int j = 0; j < s.length(); j++)
		glutBitmapCharacter(font, s[j]);
}

//Функция отрисовки меню действий
void drawMenu()
{
	int shift = 60;
	int height = 730;

	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(shift - 5, height - 55);
	glVertex2i(shift + 170, height - 55);
	glVertex2i(shift + 170, height - shift - 275);
	glVertex2i(shift - 5, height - shift - 275);
	glEnd();

	glColor3d(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2i(shift, height - shift - 30);
	glVertex2i(shift + 165, height - shift - 30);
	glVertex2i(shift + 165, height - shift);
	glVertex2i(shift, height - shift);
	glEnd();
	glColor3d(0.0, 1.0, 0.0);
	drawMenuText("Insert", shift, height - shift - 2);

	glColor3d(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2i(shift, height - shift - 70);
	glVertex2i(shift + 165, height - shift - 70);
	glVertex2i(shift + 165, height - shift - 40);
	glVertex2i(shift, height - shift - 40);
	glEnd();
	glColor3d(1.0, 0.0, 0.0);
	drawMenuText("Delete last element", shift, height - shift - 42);

	glColor3d(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2i(shift, height - shift - 110);
	glVertex2i(shift + 165, height - shift - 110);
	glVertex2i(shift + 165, height - shift - 80);
	glVertex2i(shift, height - shift - 80);
	glEnd();
	glColor3d(0.0, 0.0, 1.0);
	drawMenuText("Print matrix", shift, height - shift - 82);

	glColor3d(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2i(shift, height - shift - 150);
	glVertex2i(shift + 165, height - shift - 150);
	glVertex2i(shift + 165, height - shift - 120);
	glVertex2i(shift, height - shift - 120);
	glEnd();
	glColor3d(0.0, 1.0, 1.0);
	drawMenuText("Answer", shift, height - shift - 122);

	glColor3d(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2i(shift, height - shift - 190);
	glVertex2i(shift + 165, height - shift - 190);
	glVertex2i(shift + 165, height - shift - 160);
	glVertex2i(shift, height - shift - 160);
	glEnd();
	glColor3d(1.0, 0.0, 1.0);
	drawMenuText("New graph", shift, height - shift - 162);

	glColor3d(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2i(shift, height - shift - 230);
	glVertex2i(shift + 165, height - shift - 230);
	glVertex2i(shift + 165, height - shift - 200);
	glVertex2i(shift, height - shift - 200);
	glEnd();
	glColor3d(0.7, 0.1, 0.3);
	drawMenuText("Draw answer", shift, height - shift - 202);

	glColor3d(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2i(shift, height - shift - 270);
	glVertex2i(shift + 165, height - shift - 270);
	glVertex2i(shift + 165, height - shift - 240);
	glVertex2i(shift, height - shift - 240);
	glEnd();
	glColor3d(0.2, 0.4, 0.8);
	drawMenuText("Quit", shift, height - shift - 242);
}

//Функция отрисовки ответа
template<class T>
void Graph<T>::DrawAnswer()
{
	int n = vertList.size();
	for (int i = 0; i < n; i++)
	{
		setCoord(i, n);
	}
	//ответ для 9 вершин(9,45)
	/*Line(vertC[0].x, vertC[0].y, vertC[6].x, vertC[6].y);
	Line(vertC[1].x, vertC[1].y, vertC[7].x, vertC[7].y);
	Line(vertC[2].x, vertC[2].y, vertC[1].x, vertC[1].y);
	Line(vertC[3].x, vertC[3].y, vertC[2].x, vertC[2].y);
	Line(vertC[4].x, vertC[4].y, vertC[8].x, vertC[8].y);
	Line(vertC[5].x, vertC[5].y, vertC[3].x, vertC[3].y);
	Line(vertC[6].x, vertC[6].y, vertC[5].x, vertC[5].y);
	Line(vertC[7].x, vertC[7].y, vertC[4].x, vertC[4].y);
	Line(vertC[8].x, vertC[8].y, vertC[0].x, vertC[0].y);*/

	//ответ для 5 вершин (5,20)
	Line(vertC[0].x, vertC[0].y, vertC[4].x, vertC[4].y);
	Line(vertC[1].x, vertC[1].y, vertC[3].x, vertC[3].y);
	Line(vertC[2].x, vertC[2].y, vertC[0].x, vertC[0].y);
	Line(vertC[3].x, vertC[3].y, vertC[2].x, vertC[2].y);
	Line(vertC[4].x, vertC[4].y, vertC[1].x, vertC[1].y);
	drawVertex(n);
}

//Функция действий после нажатия мышкой
void mouseClick(int btn, int stat, int x, int y) {
	int shift = 60;
	int height = 730;

	if (stat == GLUT_DOWN) {

		if (x > shift && x < shift + 135 && y >  shift && y < shift + 30)
		{
			int sourceVertex;
			int targetVertex;
			int edgeWeight;


			cout << "Исходная вершина: "; cin >> sourceVertex; cout << endl;
			int* sourceVertPtr = &sourceVertex;
			cout << "Конечная вершина: "; cin >> targetVertex; cout << endl;
			int* targetVertPtr = &targetVertex;

			if (sourceVertex > amountVerts || targetVertex > amountVerts) {
				amountVerts++;
				int* vertPtr = &amountVerts;
				graph.InsertVertex(*vertPtr);
			}

			cout << "Вес ребра: "; cin >> edgeWeight; cout << endl;
			graph.InsertEdge(*sourceVertPtr, *targetVertPtr, edgeWeight); // 
		}
		if (x > shift && x < shift + 135 && y > shift + 40 && y < shift + 70)
		{
				graph.DeleteVertex();
		}
		if (x > shift && x < shift + 135 && y >  shift + 80 && y < shift + 100)
		{
			graph.Print();
		}
		if (x > shift && x < shift + 135 && y >  shift + 120 && y < shift + 140)
		{
			tsalesman(mat, n, help, result);
		}
		if (x > shift && x < shift + 135 && y >  shift + 160 && y < shift + 180)
		{
			graph = makeGraph();
		}
		if (x > shift && x < shift + 135 && y >  shift + 200 && y < shift + 230)
		{
			graph.DrawAnswer();
			flag ^= true;
		}
		if (x > shift && x < shift + 135 && y >  shift + 240 && y < shift + 270)
		{
			exit(0);
		}
	}
	glutPostRedisplay();
}

//Функция работы окна
void display()
{
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH); //ставим начало координат в левый нижний угол
	glViewport(0, 0, WinW, WinH);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	graph.DrawGraph();
	if (flag)
	{ 
		graph.DrawAnswer();
	}
	drawMenu();
	glutSwapBuffers();
}

void visual()
{

}
