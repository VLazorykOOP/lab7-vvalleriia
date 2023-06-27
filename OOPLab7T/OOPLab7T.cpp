#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <string>
#include <time.h>
#include <stack>
using namespace std;

/*Написати функцію - шаблон послідовного пошуку в масиві по
ключу.Функція повертає індекс останнього, знайденого елемента в
масиві, рівного ключу.Написати специфікацію функції - шаблон для типу char*/
template<typename T1, typename T2> T2 find(const T1* array, T2 size, T1 key)
{
	T2 ind = -1;
	for (T2 i = 0; i < size; i++)
	{
		if (array[i] == key)
		{
			ind = i;
		}
	}
	return ind;
}
template<> int find(const char* array, int size, char key)
{
	int ind = -1;
	for (int i = 0; i < size; i++)
	{
		if (array[i] == key)
		{
			ind = i;
		}
	}
	return ind;
}
void task1()
{
	cout << "Test: \n";
	cout << " Enter key: ";
	char key;
	cin >> key;
	cout << " Enter char array: ";
	char* array = new char[100];
	cin >> array;
	int size = sizeof(array) / sizeof(char);

	int ind;
	ind = find(array, size, key);
	if (ind == -1)
	{
		cout << "There is no match";
	}
	else
	{
		cout << ind << endl;
	}
}

/* Написати функцію - шаблон функцію впорядкування методом
«Вставки».Написати специфікацію функції - шаблон для типу char*/
template<typename T1, typename T2> void insertSort(T1* arr, T2 n) {
	T2 i, j;
	T1 key;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
template<> void insertSort(char* arr, int n) {
	int i, j;
	char key;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
void task2()
{
	cout << "Test:" << endl;
	cout << " Enter char array: ";
	char* array = new char[100];
	cin >> array;
	int size = sizeof(array) / sizeof(char);
	cout << "Unsorted Array: \n";
	cout << array;

	insertSort(array, size);
	cout << endl << "Sorted Array: \n";
	cout << array;
}
//Створити параметризований масив з конструкторами,
//деструктором і перевантаженими операторами[], =, +, +=, -, -=.
template<typename T> class Arr
{
	T* ar;
	int size;
	int state;
public:
	Arr() : ar(nullptr), size(0), state(0) {}
	Arr(int n)
	{
		if (n > 0)
		{
			size = n;
			ar = new T[size];
			for (int i = 0; i < size; i++)
			{
				ar[i] = 0;
			}
		}
		state = -1;
	}
	Arr(int n, T value)
	{
		if (n > 0)
		{
			size = n;
			ar = new T[size];
			for (int i = 0; i < size; i++)
			{
				ar[i] = value;
			}
		}
		state = -1;
	}
	~Arr()
	{
		if (ar) delete[] ar;
	}

	T& operator[](const int index)
	{
		if (index < 0)
		{
			state = -1;
			return ar[size - 1];
		}
		return ar[index];
	}
	Arr operator=(Arr& s)
	{
		size = s.size;
		ar = new T[size];
		for (int i = 0; i < size; i++)
		{
			ar[i] = s.ar[i];
		}
		return *this;
	}
	Arr operator+(Arr& s)
	{
		if (size > s.size)
		{
			size = s.size;
		}
		Arr temp(size);
		for (int i = 0; i < size; i++)
		{
			temp.ar[i] = ar[i] + s.ar[i];
		}
		return temp;
	}
	Arr operator+=(Arr& s)
	{
		if (size > s.size)
		{
			size = s.size;
		}
		for (int i = 0; i < size; i++)
		{
			ar[i] = ar[i] + s.ar[i];
		}
		return *this;
	}
	Arr operator-(Arr& s)
	{
		if (size > s.size)
		{
			size = s.size;
		}
		Arr temp(size);
		for (int i = 0; i < size; i++)
		{
			temp.ar[i] = ar[i] - s.ar[i];
		}
		return temp;
	}
	Arr operator-=(Arr& s)
	{
		if (size > s.size)
		{
			size = s.size;
		}
		for (int i = 0; i < size; i++)
		{
			ar[i] = ar[i] - s.ar[i];
		}
		return *this;
	}
	Arr(Arr& src)
	{
		size = src.size;
		ar = new T[size];
		state = 0;
		for (int i = 0; i < size; i++) ar[i] = src.ar[i];
	}
	Arr(Arr&& src)
	{
		size = src.size;
		ar = new T[size];
		state = 0;
		for (int i = 0; i < size; i++) ar[i] = src.ar[i];
	}

	void Output()
	{
		for (int i = 0; i < size; i++)
		{
			cout << "   " << ar[i];
		}
		cout << endl;
	}
};
void task3()
{
	cout << "Test:" << endl;
	cout << " Enter array size: ";
	int size;
	cin >> size;
	cout << " Enter array value: ";
	int value;
	cin >> value;

	Arr<int> ar1 = Arr<int>();
	Arr<int> ar2 = Arr<int>(size);
	Arr<int> ar3 = Arr<int>(size, value);

	cout << "ar1(): ";
	ar1.Output();
	cout << "ar2(size): ";
	ar2.Output();
	cout << "ar3(size, value): ";
	ar3.Output();

	ar2 += ar3;
	cout << "ar2 += ar3: ";
	ar2.Output();
	ar2 -= ar3;
	cout << "ar2 -= ar3: ";
	ar2.Output();
	cout << "ar3[1]: " << ar3[1] << endl;
	Arr<int> ar4 = ar2 + ar3;
	cout << "ar4 = ar2 + ar3: ";
	ar4.Output();
	Arr<int> ar5 = ar2 - ar3;
	cout << "ar5 = ar2 - ar3: ";
	ar5.Output();
}




// Побудувати клас, що описує лінійний двох зв’язний список.
//Побудувати клас ітератор, що дозволяє проходити список.
template<typename T>
struct El
{
public:
	El* prev = nullptr;
	El* next = nullptr;
	T value;
};
template<typename T>
class List
{
	El<T>* head;
public:
	List()
	{
		head = nullptr;
	}
	List(T t)
	{
		push(t);
	}
	class Iterator
	{
		El<T>* ptr;
	public:
		Iterator(El<T>* p)
		{
			ptr = p;
		}
		Iterator operator++(int i)
		{
			ptr = ptr->next;
			return *this;
		}
		Iterator operator--(int i)
		{
			ptr = ptr->prev;
			return *this;
		}
		bool operator!=(const Iterator& i1)
		{
			return i1.ptr != this->ptr;
		}
		bool operator==(const Iterator& i1)
		{
			return i1.ptr == this->ptr;
		}
		Iterator& operator=(const Iterator& i)
		{
			return this->ptr = i.ptr;
			return *this;
		}
		El<T>* operator->()
		{
			return ptr;
		}
		T& operator*()
		{
			return ptr->value;
		}
		El<T>* operator()()
		{
			return ptr;
		}
	};
	Iterator begin()
	{
		return  Iterator(head);
	}
	Iterator end()
	{
		if (head == nullptr)return nullptr;
		El<T>* temp = head;
		while (temp->next != nullptr)
			temp = temp->next;
		return  Iterator(temp);
	}
	void push(T value)
	{
		if (head == nullptr)
		{
			head = new El<T>();
			head->value = value;
			return;
		}
		El<T>* el = new El<T>();
		el->value = value;
		El<T>* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = el;
		el->prev = temp;
	}
	T pop()
	{
		if (head == nullptr)return NULL;
		El<T>* temp = end()();
		T t = temp->value;
		temp = temp->prev;
		temp->next = nullptr;
		return t;
	}
	int length()
	{
		if (head == nullptr)return 0;
		El<T>* temp = head;
		int i = 1;
		while (temp->next != nullptr)
		{
			temp = temp->next;
			i++;
		}
		return i;
	}
	T& operator[](int in)//доступ ло елеметів зі списку 
	{
		if (in<0 || in>length())throw exception("Out of range");
		El<T>* temp = head;
		int i = 0;
		while (temp->next != nullptr && i != in)
		{
			temp = temp->next;
			i++;
		}
		return temp->value;
	}
	void show()
	{
		if (head == nullptr)
			return;
		El<T>* temp = head;
		while (temp != nullptr)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}
	}
}; ;
void task4()
{
	List<double> l = List<double>();
	cout << "Size: " << endl;
	int s;
	double d;
	cin >> s;
	cout << "Size " << s << endl;
	for (int i = 0; i < s; i++)
	{
		cin >> d;
		l.push(d);
	}
	cout << endl << "List: " << endl;
	for (int i = 0; i < l.length(); i++)
	{
		cout << l[i] << " ";
	}
	cout << endl << endl;
	cout << "Delete last element" << endl;
	l.pop();
	cout << "Index -> value: " << endl << endl;
	for (List<double>::Iterator i = l.begin(); i != nullptr; i++)
	{
		cout << *i << " " << i->value << endl;
	}
}

int task_manager()
{
	int task_number;
RENUMBER:	printf("Menu:\n     1.  Task 1\n     2.  Task 2\n     3.  Task 3\n     4.  Task 4\n");
	printf("Enter task number you wanna do: ");
	scanf_s("%d", &task_number);
	if (task_number < 1 || task_number > 4)
	{
		system("cls");
		printf("There is only 4 options!\n\n");
		goto RENUMBER;
	}
	return task_number;
}
int main()
{
	setlocale(LC_ALL, "ukr");
TASK:	int task_number = task_manager();
	switch (task_number)
	{
	case 1:
		task1();
		break;
	case 2:
		task2();
		break;
	case 3:
		task3();
		break;
	case 4:
		task4();
		break;
	default:
		break;
	}

	string answer;
FIN:	printf("\nDo you want to do one more task? Enter 'yes' if you do, and 'no' if you don`t: ");
	cin >> answer;
	if (answer == "yes")
	{
		system("cls");
		goto TASK;
	}
	if (answer == "no")
	{
		system("cls");
		printf("Bye!");
	}
	else
	{
		printf("Please enter 'yes' or 'no'\n");
		goto FIN;
	}
}
