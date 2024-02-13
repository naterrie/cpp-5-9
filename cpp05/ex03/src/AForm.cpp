#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{

}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	*this = other;
}

AForm::~AForm()
{
}

AForm&	AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

const std::string&	AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSigned() const
{
	return (this->_signed);
}

int	AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int	AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return ("AForm is not signed");
}

std::ostream&	operator<<(std::ostream& os, const AForm& Aform)
{
	os << "AForm " << Aform.getName() << " is ";
	if (Aform.getSigned())
		os << "signed";
	else
		os << "not signed";
	os << " and requires grade " << Aform.getGradeToSign() << " to sign and grade " << Aform.getGradeToExecute() << " to execute";
	return (os);
}
