class Stack
{
private:
	char A[101];
	int top; //top of stack
public:
	void Push(int x);
	void Pop();
	int Top();
	bool isEmpty;
};
