#include "Bureaucrat.hpp"

int main(void){
	Bureaucrat jeff("jeff", 1);
	Bureaucrat larry("larry", 150);

	try {
		jeff.incrementGrade();
	} catch (const std::exception& e) {
		std::cout << jeff.getName() << " is already at the highest grade: "
		          << jeff.getGrade() << std::endl;
		std::cout << "TLDR: " << e.what() << std::endl;
	}
	std::cout << "===========================================" << std::endl;
	try {
		larry.decrementGrade();
	} catch (const std::exception& e) {
		std::cout << "At this point just fire " << larry.getName()
		          << ", his grade is: " << larry.getGrade() << std::endl;
		std::cout << "TLDR: " << e.what() << std::endl;
	}
	return (0);
}
