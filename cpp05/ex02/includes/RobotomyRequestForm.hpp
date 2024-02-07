#pragma once

# include "Form.hpp"

class RobotomyRequest : public Form
{
	private:

		const std::string	_target;

	public:

		RobotomyRequest();
		RobotomyRequest(const std::string& target);
		RobotomyRequest(const RobotomyRequest& other);
		~RobotomyRequest();

		RobotomyRequest&	operator=(const RobotomyRequest& other);

		const std::string&	getTarget() const;

		void				execute(const Bureaucrat& executor) const;
};
