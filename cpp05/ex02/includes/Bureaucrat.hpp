#pragma once

# include <iostream>
# include <stdexcept>

class AForm;

class Bureaucrat
{
	private:

		const std::string	_name;
		int					_grade;

	public:

		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		Bureaucrat&			operator=(const Bureaucrat& other);

		const std::string&	getName() const;
		int					getGrade() const;

		void				signForm(const AForm &form) const;
		void				incrementGrade();
		void				decrementGrade();

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
