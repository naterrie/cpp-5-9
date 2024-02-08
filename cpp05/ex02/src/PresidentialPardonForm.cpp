#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm("PresidentialPardonForm", 25, 5), _target(other._target)
{
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
		this->_target = other._target;
	return (*this);
}

const std::string&	PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (!this->getSigned())
		throw AForm::FormNotSignedException();
	else
		std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
