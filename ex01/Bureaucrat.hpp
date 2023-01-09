#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
#include <string>
#include <exception>
#include <iostream>

class Form;

class Bureaucrat
{
private:
    static const unsigned int MAX_GRADE = 1;
    static const unsigned int MIN_GRADE = 150;

    // 아래를 private라고 명시하지는 않음
    const std::string name_; // const로 명시
    unsigned int grade_;

public:
    Bureaucrat(const std::string &name = "anonymous", const unsigned int grade = 150);
    Bureaucrat(const Bureaucrat &bureaucrat);
    Bureaucrat &operator=(const Bureaucrat &bureaucrat);
    virtual ~Bureaucrat(void);

    // getter
    const std::string &getName(void) const;
    unsigned int getGrade(void) const;

    // setter 랄까?
    void increaseGrade(void);
    void decreaseGrade(void);

    // ex01 추가 동작
    void signForm(Form &form);

    // 오류
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif