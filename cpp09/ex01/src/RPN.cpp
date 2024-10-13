#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN::~RPN()
{}

RPN &RPN::operator=(const RPN &src)
{
	(void)src;
	return *this;
}

int RPN::calculate(const std::string &expression)
{
	std::stack<int> stack;

	for (size_t i = 0; i < expression.length(); i++)
	{
		char c = expression[i];

		if (c == ' ')
			continue;
		else if (std::isdigit(c))
			stack.push(c - '0');
		else if (_isOperator(c))
			_applyOperator(c, stack);
		else if (c == '\0')
			break;
		else
			throw std::invalid_argument("Error: invalid character in expression");
	}

	if (stack.size() != 1)
		throw std::invalid_argument("Error: invalid expression");

	return stack.top();
}

void RPN::_applyOperator(char op, std::stack<int> &stack)
{
	if (stack.size() < 2)
		throw std::runtime_error("Error: not enough operands");

	int b = stack.top();
	stack.pop();
	int a = stack.top();
	stack.pop();

	switch (op)
	{
		case '+':
			stack.push(a + b);
			break;
		case '-':
			stack.push(a - b);
			break;
		case '*':
			stack.push(a * b);
			break;
		case '/':
			if (b == 0)
				throw std::runtime_error("Error: division by zero");
			stack.push(a / b);
			break;
		default:
			throw std::invalid_argument("Error: invalid operator");
	}
}

bool RPN::_isOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}
