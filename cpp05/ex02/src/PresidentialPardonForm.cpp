#include "PresidentialPardonForm.hpp"

PresidentialPardon::PresidentialPardon() : Form("PresidentialPardon", 25, 5), _target("default")
{
}

PresidentialPardon::PresidentialPardon(const std::string& target) : Form("PresidentialPardon", 25, 5), _target(target)
{
}

PresidentialPardon::PresidentialPardon(const PresidentialPardon& other) : Form("PresidentialPardon", 25, 5), _target(other._target)
{
	*this = other;
}

PresidentialPardon::~PresidentialPardon()
{
}

PresidentialPardon&	PresidentialPardon::operator=(const PresidentialPardon& other)
{
	if (this == &other)
		return (*this);
	this->_target = other._target;
	return (*this);
}

const std::string&	PresidentialPardon::getTarget() const
{
	return (this->_target);
}

void	PresidentialPardon::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw Form::GradeTooLowException();
	else if (!this->getSigned())
		throw Form::FormNotSignedException();
	else
		std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
