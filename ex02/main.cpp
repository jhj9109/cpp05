#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const std::string BLACK = "\033[30m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[37m";
const std::string DEFAULT = "\033[39m";

int main()
{
    Bureaucrat one = Bureaucrat("man", 1);
    PresidentialPardonForm ppf = PresidentialPardonForm("target1");
    RobotomyRequestForm rrf = RobotomyRequestForm("target2");
    ShrubberyCreationForm scf = ShrubberyCreationForm("target3");

    std::cout << BLUE << std::endl;
    one.signForm(ppf);
    one.executeForm(ppf);

    std::cout << RED << std::endl;
    one.signForm(rrf);
    one.executeForm(rrf);

    std::cout << GREEN << std::endl;
    one.signForm(scf);
    one.executeForm(scf);

    std::cout << MAGENTA << std::endl;
}