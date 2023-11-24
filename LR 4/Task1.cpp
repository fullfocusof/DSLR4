//#include <iostream>
//#include <cmath>
//#include <string>
//
//using namespace std;
//
//struct DequeNode
//{
//	int data;
//	DequeNode* next, * prev;
//};
//
//struct LongNumber
//{
//	DequeNode* first;
//	DequeNode* last;
//};
//
//void Print(LongNumber& num)
//{
//	DequeNode* temp = num.last;
//	while (temp != nullptr)
//	{
//		cout << temp->data;
//		temp = temp->prev;
//	}
//	cout << endl;
//}
//
//int GetSize(LongNumber num)
//{
//	int cnt = 0;
//
//	while (num.first != nullptr)
//	{
//		cnt++;
//		num.first = num.first->next;
//	}
//
//	return cnt;
//}
//
//void InsertBegin(LongNumber& num, int value)
//{
//	DequeNode* temp = new DequeNode;
//	temp->data = value;
//	temp->next = num.first;
//	temp->prev = nullptr;
//
//	if (num.first == nullptr)
//	{
//		num.last = temp;
//	}
//	else
//	{
//		num.first->prev = temp;
//	}
//
//	num.first = temp;
//}
//
//void InsertEnd(LongNumber& num, int value)
//{
//	DequeNode* temp = new DequeNode;
//	temp->data = value;
//	temp->next = nullptr;
//	temp->prev = num.last;
//
//	if (num.last == nullptr)
//	{
//		num.first = temp;
//	}
//	else
//	{
//		num.last->next = temp;
//	}
//
//	num.last = temp;
//}
//
//LongNumber Init(string ex)
//{
//	LongNumber result;
//	result.first = nullptr;
//	result.last = nullptr;
//
//	for (int i = 0; i < ex.size(); i++)
//	{
//		InsertBegin(result, int(ex[i] - '0'));
//	}
//
//	return result;
//}
//
//LongNumber Multiply(LongNumber& num, int value)
//{
//	LongNumber result;
//	result.first = nullptr;
//	result.last = nullptr;
//
//	DequeNode* temp = num.first;
//	int trans = 0, tempNum;
//
//	while (temp != nullptr || trans != 0)
//	{
//		if (temp != nullptr)
//		{
//			tempNum = temp->data;
//			temp = temp->next;
//		}
//		else
//		{
//			tempNum = 0;
//		}
//
//		InsertEnd(result , (tempNum * value + trans) % 10);
//		trans = (trans + tempNum * value) / 10;
//	}
//
//	return result;
//}
//
//LongNumber Factorial(int n)
//{
//	LongNumber result;
//	result.first = nullptr;
//	result.last = nullptr;
//
//	InsertBegin(result, 1);
//
//	for (int i = 2; i <= n; i++)
//	{
//		result = Multiply(result, i);
//	}
//
//	return result;
//}
//
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	while (true)
//	{
//		system("cls");
//
//		LongNumber num;
//		num.first = nullptr;
//		num.last = nullptr;
//
//		string n;
//		cout << "Введите число" << endl;
//		cin >> n;
//
//		while (stoi(n) < 1)
//		{
//			system("cls");
//			cout << "Введите верные данные" << endl;
//			cin >> n;
//		}
//
//		num = Init(n);
//
//		system("cls");
//
//		cout << "Число: ";
//		Print(num);
//
//		num = Factorial(stoi(n));
//
//		cout << "Факториал: ";
//		Print(num);
//
//		system("pause");
//	}
//}