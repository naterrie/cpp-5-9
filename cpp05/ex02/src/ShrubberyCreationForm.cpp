#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm("ShrubberyCreationForm", 145, 137), _target(other._target)
{
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
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
		throw AForm::GradeTooLowException();
	else if (!this->getSigned())
		throw AForm::FormNotSignedException();
	else
	{
		std::ofstream file((executor.getName() + "_shrubbery").c_str());
		if (!file.is_open())
			throw ShrubberyCreationForm::FileNotOpenException();
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
