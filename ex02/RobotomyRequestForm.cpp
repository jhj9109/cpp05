#include "RobotomyRequestForm.hpp"
#include <sys/time.h>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", REQUIRED_SIGN_GRADE, REQUIRED_EXCUTE_GRADE), target_(target)
{
    std::cout << "RobotomyRequestForm 기본 생성자 실행 (target: " << target << ")" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form)
    : AForm(form), target_(form.target_)
{
    std::cout << "RobotomyRequestForm 복사 생성자 실행" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
    this->AForm::operator=(form);
    const_cast<std::string &>(target_) = form.target_;
    std::cout << "RobotomyRequestForm 할당 연산자 오버로딩" << std::endl;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm 기본 소멸자 실행" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    try
    {
        checkExecute(executor);
        struct timeval t;
        gettimeofday(&t, NULL);
        srand(t.tv_usec);
        int random = rand();
        if (random % 2 == 0)
        {
            std::cout << target_ << " has been robotomized" << std::endl;
        }
        else
        {
            std::cout << target_ << " has been failed to robotomized." << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Fail to excute, because " << e.what() << std::endl;
    }
}