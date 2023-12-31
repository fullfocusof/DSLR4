#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct DequeNode
{
	int data;
	DequeNode* next, * prev;
};

struct LongNumber
{
	DequeNode* first;
	DequeNode* last;
	bool isNegative;
};

void Print(LongNumber& num)
{
	if (num.isNegative && num.last->data != 0)
	{
		cout << "-";
	}
	DequeNode* temp = num.last;
	while (temp != nullptr)
	{
		cout << temp->data;
		temp = temp->prev;
	}
}

void InsertBegin(LongNumber& num, int value)
{
	DequeNode* temp = new DequeNode;
	temp->data = value;
	temp->next = num.first;
	temp->prev = nullptr;

	if (num.first == nullptr)
	{
		num.last = temp;
	}
	else
	{
		num.first->prev = temp;
	}

	num.first = temp;
}

void InsertEnd(LongNumber& num, int value)
{
	DequeNode* temp = new DequeNode;
	temp->data = value;
	temp->next = nullptr;
	temp->prev = num.last;

	if (num.last == nullptr)
	{
		num.first = temp;
	}
	else
	{
		num.last->next = temp;
	}

	num.last = temp;
}

LongNumber Init()
{
	string ex;
	cout << "������� �����" << endl;
	cin >> ex;

	LongNumber result;
	result.first = nullptr;
	result.last = nullptr;

	if (ex[0] == '-')
	{
		result.isNegative = true;
		ex = ex.substr(1);
	}
	else
	{
		result.isNegative = false;
	}

	ex.erase(0, ex.find_first_not_of('0'));
	if (ex.empty())
	{
		ex = "0";
	}

	for (int i = 0; i < ex.size(); i++)
	{
		if (isdigit(ex[i]))
		{
			InsertBegin(result, int(ex[i] - '0'));
		}
		else
		{
			break;
		}
	}

	return result;
}

int Compare(LongNumber& num1, LongNumber& num2) // 0 - "="      1 - num1>num2      -1 - num1<num2
{
	int result = 0;

	if (num1.isNegative && !num2.isNegative)
	{
		return -1;
	}
	else if (!num1.isNegative && num2.isNegative)
	{
		return 1;
	}
	else
	{
		DequeNode* curNum1 = num1.first;
		DequeNode* curNum2 = num2.first;

		if (!num1.isNegative && !num2.isNegative)
		{
			while (curNum1 != nullptr && curNum2 != nullptr)
			{
				if (curNum1->data > curNum2->data) result = 1;
				else if (curNum1->data < curNum2->data) result = -1;
				curNum1 = curNum1->next;
				curNum2 = curNum2->next;
			}

			if (curNum1 != nullptr) result = 1;
			else if (curNum2 != nullptr) result = -1;
		}
		else if (num1.isNegative && num2.isNegative)
		{
			while (curNum1 != nullptr && curNum2 != nullptr)
			{
				if (curNum1->data > curNum2->data) result = -1;
				else if (curNum1->data < curNum2->data) result = 1;
				curNum1 = curNum1->next;
				curNum2 = curNum2->next;
			}

			if (curNum1 != nullptr) result = -1;
			else if (curNum2 != nullptr) result = 1;
		}
	}

	return result;
}

void Decision(LongNumber& result, LongNumber& num1, LongNumber& num2)
{
	if()

	DequeNode* curNum1 = num1.first;
	DequeNode* curNum2 = num2.first;
	int borrow = 0;

	while (curNum1 != nullptr || curNum2 != nullptr)
	{
		int curResult = borrow + (curNum1 != nullptr ? curNum1->data : 0) - (curNum2 != nullptr ? curNum2->data : 0);

		if (curResult < 0)
		{
			curResult += 10;
			borrow = -1;
		}
		else
		{
			borrow = 0;
		}

		InsertEnd(result, curResult);
		curNum1 = curNum1 != nullptr ? curNum1->next : nullptr;
		curNum2 = curNum2 != nullptr ? curNum2->next : nullptr;
	}

	while (result.last != nullptr && result.last->data == 0)
	{
		DequeNode* temp = result.last;
		result.last = result.last->prev;
		result.last->next = nullptr;
		delete temp;
	}

}

int main()
{
	setlocale(LC_ALL, "ru");
	while (true)
	{
		system("cls");

		LongNumber num1 = Init(); cout << endl;
		LongNumber num2 = Init(); cout << endl;

		LongNumber answer;
		answer.first = nullptr;
		answer.last = nullptr;
		answer.isNegative = false;

		int compareResult = Compare(num1, num2);
		if (compareResult == 0)
		{
			InsertEnd(answer, 1);
		}
		else if(compareResult == -1)
		{
			InsertEnd(answer, 0);
		}
		else
		{
			// � ����� decision
		}

		cout << "�����: ";
		Print(num1); cout << " / "; Print(num2); cout << " = "; Print(answer); cout << endl << endl;

		system("pause");
	}
}