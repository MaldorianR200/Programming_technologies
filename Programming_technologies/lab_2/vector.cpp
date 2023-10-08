

/*

int MyVector::counter = 0;

int MyVector::GetCounter()
{
	return counter;
}

MyVector::MyVector():arr(nullptr), current(0), max_size(0)
{
	counter++;
}

MyVector::MyVector(int max_size) : current(0)
{
	counter++;
	if (max_size <= 0)
	{
		arr = nullptr;
		this->max_size = 0;
		return;
	}
	arr = new int[this->max_size = max_size];
	for (int i = 0; i < this->max_size; ++i)
		arr[i] = 0;
}

MyVector::MyVector(int *arr, int max_size) : current(0)
{
	++counter;
	if (max_size <= 0)
	{
		this->arr = nullptr;
		this->max_size = 0;
		return;
	}
	this->arr = new int[this->max_size = max_size];
	for (int i = 0; i < this->max_size; ++i)
		this->arr[i] = arr[i];
	current = this->max_size;
}

MyVector::MyVector(const MyVector& right):current(right.current), 
										  max_size(right.max_size)
{
	counter++;
	this->arr = new int[max_size];
	for (int i = 0; i < this->current; ++i)
		this->arr[i] = right.arr[i];
}

MyVector::~MyVector()
{
	--counter;
	delete[] arr;
}

int MyVector::GetElemByIndex(int index) const
{
	if(current)
		return arr[index%current];
	return -1;
}

int& MyVector::GetElemByIndex(int index)
{
	if (current)
		return arr[index % current];
}

void MyVector::PrintMyVector() const
{
	for (int i = 0; i < current; ++i)
		std::cout << arr[i] << '\t';
	std::cout << std::endl;
}

void MyVector::AddElemToMyVector(int val)
{
	if (current == max_size)
	{
		max_size = max_size * 2 + 1;
		int* temp = new int[max_size];
		for (int i = 0; i < current; ++i)
			temp[i] = arr[i];
		delete[] arr;
		arr = temp;
	}
	arr[current++] = val;
}

void MyVector::RemoveElemFromMyVector(int val)
{
	int i = 0;
	for (; i < current; ++i)
	{
		if (arr[i] == val)
		{
			break;
		}
	}
	for (int j = i; j < current-1; ++j)
	{
		arr[j] = arr[j + 1];
	}
	--current;
}

void MyVector::RemoveElemFromBack()
{
	if(current)
		--current;
}

MyVector& MyVector::operator=(const MyVector& right)
{
	if (this != &right)
	{
		delete[]arr;
		arr = new int[max_size = right.max_size];
		for (int i = 0; i < right.current; ++i)
			arr[i] = right[i];
		current = right.current;
	}
	return *this;
}

int& MyVector::operator[](int index)
{
	return arr[index];
}

int MyVector::operator[](int index) const
{
	return arr[index];
}

MyVector MyVector::operator+(const MyVector& right) const
{
	MyVector result(max_size + right.max_size);
	result.current = current + right.current;
	for (int i = 0; i < current; ++i)
	{
		result[i] = arr[i];
	}
	for (int i = 0; i < right.current; ++i)
	{
		result[current + i] = right[i];
	}
	return result;
}

MyVector& MyVector::operator+=(int a)
{
	for (int i = 0; i < current; ++i)
	{
		arr[i] += a;
	}
	return *this;
}

MyVector& MyVector::operator++()
{
	(*this) += 1;
	for (int i = 0; i < current; ++i)
	{
		++ arr[i];
	}
	return *this;
}

MyVector MyVector::operator++(int)
{
	MyVector temp(*this);
	++(*this);
	return temp;
}

int operator+(int left, const MyVector& right)
{
	int res = left;
	for (int i = 0; i < right.GetSize(); ++i)
		res += right[i];
	return res;
}

std::ostream& operator<<(std::ostream& out, const MyVector& obj)
{
	obj.PrintMyVector();
	return out;
}

std::istream& operator>>(std::istream& in, MyVector& obj)
{
	int n = 0;
	in >> n;
	for (int i = 0; i < n; ++i)
	{
		int val;
		in >> val;
		obj.AddElemToMyVector(val);
	}
	return in;
}

*/