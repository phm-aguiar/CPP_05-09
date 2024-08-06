#include "MutantStack.hpp"

void testDeepCopy(void)
{
	MutantStack<int> mstack;
	std::cout << "mstack: pushing 5 and 17" << std::endl;
	mstack.push(5);
	mstack.push(17);
	MutantStack<int> mstack2;
	std::cout << "mstack2: pushing 42" << std::endl;
	mstack2.push(42);
	std::cout << "mstack2 = mstack" << std::endl;
	mstack2 = mstack;
	std::cout << "mstack: pushing 42" << std::endl;
	mstack.push(42);
	std::cout << "mstack: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "mstack2: ";
	for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void testCopyConstructor(void)
{
	MutantStack<int> mstack;
	std::cout << "mstack: pushing 5 and 17" << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << "MutantStack<int> mstack2(mstack)" << std::endl;
	MutantStack<int> mstack2(mstack);
	std::cout << "mstack: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "mstack2: ";
	for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}


void testAssignmentOperator(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	MutantStack<int> mstack2;
	mstack2.push(42);
	std::cout << "mstack = mstack2" << std::endl;
	mstack2 = mstack;
	std::cout << "mstack: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "mstack2: ";
	for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}


void testBasicOperations(void)
{
	MutantStack<int> mstack;
	std::cout << "pushing 5" << std::endl;
	mstack.push(5);
	std::cout << "pushing 17" << std::endl;
	mstack.push(17);
	std::cout << "top: " << mstack.top() << std::endl;
	std::cout << "pop" << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
}

void testIterator(void)
{
	MutantStack<int> mstack;
	std::cout << "pushing 5, 17, 3, 5, 42, 0" << std::endl;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(42);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "test ++it" << std::endl;
	std::cout << "MutantStack: ";
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::cout << "test --it" << std::endl;
	--it;
	std::cout << "MutantStack: ";
	while (it != mstack.begin())
	{
		std::cout << *it << " ";
		--it;
	}
	std::cout << *it << std::endl;
}

void	testMainSubject(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

int	main(void)
{
	std::cout << "======================" << std::endl;
	testIterator();
	std::cout << "======================" << std::endl;
	testBasicOperations();
	std::cout << "======================" << std::endl;
	testAssignmentOperator();
	std::cout << "======================" << std::endl;
	testCopyConstructor();
	std::cout << "======================" << std::endl;
	testDeepCopy();
	std::cout << "======================" << std::endl;
	testMainSubject();
	return (0);
}
