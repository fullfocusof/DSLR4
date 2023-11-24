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
//	bool isNegative;
//	int num;
//};
//
//void Print(LongNumber& num)
//{
//	if (num.isNegative && num.last->data != 0)
//	{
//		cout << "-";
//	}
//	DequeNode* temp = num.last;
//	while (temp != nullptr)
//	{
//		cout << temp->data;
//		temp = temp->prev;
//	}
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
//LongNumber Init()
//{
//	string ex;
//	cout << "Введите число" << endl;
//	cin >> ex;
//
//	LongNumber result;
//	result.first = nullptr;
//	result.last = nullptr;
//
//	result.num = stoi(ex);
//
//	if (ex[0] == '-')
//	{
//		result.isNegative = true;
//		ex = ex.substr(1);
//	}
//	else
//	{		
//		result.isNegative = false;
//	}
//
//	ex.erase(0, ex.find_first_not_of('0'));
//	if (ex.empty())
//	{
//		ex = "0";
//	}
//
//	for (int i = 0; i < ex.size(); i++)
//	{
//		if (isdigit(ex[i]))
//		{
//			InsertBegin(result, int(ex[i] - '0'));
//		}
//		else
//		{
//			break;
//		}
//	}
//
//	return result;
//}
//
//LongNumber Sum(LongNumber& num1, LongNumber& num2)
//{
//	LongNumber result;
//	result.first = nullptr;
//	result.last = nullptr;
//
//	DequeNode* tempnum1 = num1.first, * tempnum2 = num2.first;
//
//	int trans = 0, tempVal1, tempVal2;
//
//	while (tempnum1 != nullptr || tempnum2 != nullptr || trans != 0)
//	{
//		if (tempnum1 != nullptr)
//		{
//			tempVal1 = tempnum1->data;
//			tempnum1 = tempnum1->next;
//		}
//		else
//		{
//			tempVal1 = 0;
//		}
//
//		if (tempnum2 != nullptr)
//		{
//			tempVal2 = tempnum2->data;
//			tempnum2 = tempnum2->next;
//		}
//		else
//		{
//			tempVal2 = 0;
//		}
//
//		InsertEnd(result, (tempVal1 + tempVal2 + trans) % 10);
//		trans = (tempVal1 + tempVal2 + trans) / 10;
//	}
//
//	return result;
//}
//
//LongNumber MultiplySingle(LongNumber& num, int value)
//{
//	LongNumber result;
//	result.first = nullptr;
//	result.last = nullptr;
//
//	if (value == 0)
//	{
//		InsertEnd(result, 0);
//		return result;
//	}
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
//		InsertEnd(result, (tempNum * value + trans) % 10);
//		trans = (trans + tempNum * value) / 10;
//	}
//
//	return result;
//}
//
//void MultiplyLong(LongNumber& result, LongNumber& num1, LongNumber& num2)
//{
//	result.first = nullptr;
//	result.last = nullptr;	
//
//	DequeNode* tempnum2 = num2.first;
//	int digitCount = 0;
//
//	while (tempnum2 != nullptr)
//	{
//		LongNumber tempResult = MultiplySingle(num1, tempnum2->data);
//
//		for (int i = 0; i < digitCount; i++)
//		{
//			InsertBegin(tempResult, 0);
//		}
//		
//		result = Sum(result, tempResult);
//
//		digitCount++;
//		tempnum2 = tempnum2->next;
//	}
//
//	result.isNegative = num1.isNegative != num2.isNegative;
//}
//
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	while (true)
//	{
//		system("cls");
//
//		LongNumber num1 = Init(); cout << endl;
//		LongNumber num2 = Init(); cout << endl;
//		LongNumber answer; 
//
//		if (num1.num > num2.num)
//		{
//			MultiplyLong(answer, num1, num2);
//		}
//		else
//		{
//			MultiplyLong(answer, num2, num1);
//		}
//
//		cout << "Ответ:" << endl;
//		Print(num1); cout << " * "; Print(num2); cout << " = "; Print(answer); cout << endl << endl;
//
//		system("pause");
//	}
//}