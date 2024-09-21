#include "MutantStack.hpp"
#include <list>

int main()
{
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
		//[...]
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
	std::cout << "----------------" << std::endl;
	{
		MutantStack<int> mstack;
		for (int i = 0; i < 10; i++)
			mstack.push(i);
		std::cout << mstack.top() << std::endl;
		std::cout << mstack.size() << std::endl;
		mstack.pop();
		std::cout << mstack.top() << std::endl;

		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
			std::cout << *it << ", ";
	}
}

// Test for std::list

// #include <iostream>
// #include <list>
// #include <stack>

// int main()
// {
//     {
//         std::list<int> mlist;
//         mlist.push_back(5);
//         mlist.push_back(17);
//         std::cout << mlist.back() << std::endl;  // Equivalent to mstack.top()
//         mlist.pop_back();                        // Equivalent to mstack.pop()
//         std::cout << mlist.size() << std::endl;

//         mlist.push_back(3);
//         mlist.push_back(5);
//         mlist.push_back(737);
//         // [...]
//         mlist.push_back(0);

//         std::list<int>::iterator it = mlist.begin();
//         std::list<int>::iterator ite = mlist.end();
//         ++it;
//         --it;
//         while (it != ite)
//         {
//             std::cout << *it << std::endl;
//             ++it;
//         }

//         // In C++98, you can't directly initialize a std::stack with a std::list
//         std::stack<int> s;
//         for (std::list<int>::iterator it = mlist.begin(); it != mlist.end(); ++it)
//         {
//             s.push(*it);  // Manually push list elements into the stack
//         }
//     }
//     std::cout << "----------------" << std::endl;
//     {
//         std::list<int> mlist;
//         for (int i = 0; i < 10; i++)
//             mlist.push_back(i);
//         std::cout << mlist.back() << std::endl;  // Equivalent to mstack.top()
//         std::cout << mlist.size() << std::endl;
//         mlist.pop_back();                        // Equivalent to mstack.pop()
//         std::cout << mlist.back() << std::endl;

//         for (std::list<int>::iterator it = mlist.begin(); it != mlist.end(); ++it)
//             std::cout << *it << ", ";
//         std::cout << std::endl;
//     }
// }
