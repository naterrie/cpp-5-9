#pragma once

#include "Bureaucrat.hpp"

class AForm
{
	private:

		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:

		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		virtual ~AForm();

		AForm&				operator=(const AForm& other);

		virtual void		execute(const Bureaucrat& executor) const = 0;
		const std::string&	getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void				beSigned(const Bureaucrat& bureaucrat);

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

		class FormNotSignedException: public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const AForm& Aform);
