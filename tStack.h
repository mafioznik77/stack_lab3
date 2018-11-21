using namespace std;

template <class T>
class TStack
{
	int MaxSize, Size;
	T*mas;
public:
	TStack(int _MaxSize = 100);
	TStack(const TStack &T);
    ~TStack();
	
	int IsFull();
	int IsEmpty();
	
	T Pop();
	T Top();
	void Push(T a);
	void Clr();
};
    
    template <class T>
	TStack<T>::TStack(int _MaxSize)
	{
		if(_MaxSize < 0) 
			throw MaxSize;

		MaxSize = _MaxSize;
		Size = 0;
		mas = new T[MaxSize];
	}

    template <class T>
	TStack<T>::TStack(const TStack &v)
	{
		MaxSize = v.MaxSize;
		Size = v.Size;
		mas = new T[MaxSize];

		for(int i = 0; i < Size; i++){
			mas[i] = v.mas[i];
	     }
	}
	
	template <class T>
	TStack<T>::~TStack()
	{
		delete[] mas;
	}
    
	template <class T>
	int TStack<T>::IsFull()
	{
		return (MaxSize == Size);
	}
	
	template <class T>
	int TStack<T>::IsEmpty()
	{
		if(Size == 0)
			return 1;
		else return 0;
	}
	
	template <class T>
	T TStack<T>::Pop() 
	{
		if(IsEmpty())
			throw 0;
		Size--;
		
		return mas[Size];
	}
	
	template <class T>
	T TStack<T>::Top()
	{
		if(IsEmpty()) 
			throw 0;

		return mas[Size - 1];
	}
	
	template <class T>
	void TStack<T>::Push(T a)
	{
		if(IsFull()) 
			throw Size;
        else{
			mas[Size] = a;
			Size++;
		}
	}

	template <class T>
	void TStack<T>::Clr()
	{
		Size = 0;
	}