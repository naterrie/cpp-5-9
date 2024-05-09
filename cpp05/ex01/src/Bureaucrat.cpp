#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
	*this = other;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

const	std::string&	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::signForm(Form &form)
{
	if (form.getSigned())
	{
		std::cout << this->_name << "  couldn’t sign " << form.getName() << " because already signed" << std::endl;
		return ;
	}
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signs " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw (GradeTooHighException());
	else
		this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw (GradeTooLowException());
	else
		this->_grade++;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}
