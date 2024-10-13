#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <stdexcept>
#include <iostream>
#include <cstdlib>

class RPN
{
	public:
		RPN();
		~RPN();
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);

		int calculate(const std::string &expression);

	private:
		void _applyOperator(char op, std::stack<int> &stack);
		bool _isOperator(char c);
};

#endif
