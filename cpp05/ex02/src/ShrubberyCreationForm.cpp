#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : Form("ShrubberyCreationForm", 145, 137), _target(other._target)
{
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this == &other)
		return (*this);
	this->_target = other._target;
	return (*this);
}

const std::string&	ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw Form::GradeTooLowException();
	else if (!this->getSigned())
		throw Form::FormNotSignedException();
	else
	{
		std::ofstream	file(this->_target + "_shrubbery");
		if (!file.is_open())
			throw Form::FileNotOpenException();
    file << "                                                         ." << std::endl;
    file << "                                              .         ;  " << std::endl;
    file << "                 .              .              ;%     ;;   " << std::endl;
    file << "                   ,           ,                :;%  %;   " << std::endl;
    file << "                    :         ;                   :;%;'     .,   " << std::endl;
    file << "           ,.        %;     %;            ;        %;'    ,;" << std::endl;
    file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
    file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
    file << "               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
    file << "                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
    file << "                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
    file << "                    `:%;.  :;bd%;          %;@%;'" << std::endl;
    file << "                      `@%:.  :;%.         ;@@%;'   " << std::endl;
    file << "                        `@%.  `;@%.      ;@@%;         " << std::endl;
    file << "                          `@%%. `@%%    ;@@%;        " << std::endl;
    file << "                            ;@%. :@%%  %@@%;       " << std::endl;
    file << "                              %@bd%%%bd%%:;     " << std::endl;
    file << "                                #@%%%%%:;;" << std::endl;
    file << "                                %@@%%%::;" << std::endl;
    file << "                                %@@@%(o);  . '         " << std::endl;
    file << "                            `.. %@@@o%;:(.,'         " << std::endl;
    file << "                               `)@@@o%::;         " << std::endl;
    file << "                                %@@(o)::;        " << std::endl;
    file << "                               .%@@@@%::;         " << std::endl;
    file << "                               ;%@@@@%::;.          " << std::endl;
    file << "                              ;%@@@@%%:;;;. " << std::endl;
    file << "                          ...;%@@@@@%%:;;;;,.." << std::endl;
		file << std::endl;
		file.close();
	}
}

const char*	ShrubberyCreationForm::FileNotOpenException::what() const throw()
{
	return ("File could not be opened");
}
