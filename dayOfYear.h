#pragma once //한번만 include하게끔 만드는 헤더가드

#include <iostream>

// 1. 본인이름학번의 네임스페이스
// -본인이름학번 네임스페이스 예: 이름이 김프로이고 학번이 1234567일 경우 KimPro1234567
// using 지시자는 cpp파일에서는 영역 { block } 안에서 사용, 헤더파일엔 using 지시자는 사용하지 않고 네임스페이스 지정자를 사용합니다.
// -using 지시자 예: { using namespace std; cout << "Enter your id: "; }
// -네임스페이스 지정자 예: os << "Enter your id: ";

// 2. 클래스명.h: 클래스정의
// 1의 본인이름학번의 네임스페이스 안에 클래스를 정의하고 멤버함수들도 모두 인라인으로 구현합니다. 
// private 멤버변수 선언 (2개 이상)
// private 멤버함수 정의
// -test멤버변수1: 멤버변수1 범위가 아니면 프로그램 종료
// -test멤버변수2: 멤버변수2 범위가 아니면 프로그램 종료
// public 멤버함수 정의
// -input: 표준스트림입력으로 멤버변수들 입력, test함수들 호출
// -set 접근함수들: 멤버변수 값 설정 및 test함수 호출
// -print: 표준스트림출력으로 멤버변수들 출력
// -get 접근함수들: 멤버변수 값 리턴

namespace JungYunchae2649114{
    class dayOfYear {
        int month{};
        int day{};
        void testday(){
            if (day <1 ||day > 31 ) {
                std::cout << "Invalid value.\n";
                std::exit(1);
            }
        }
        void testmonth(){
            if (month < 1 || month > 12) {
                std::cout << "Invalid value.\n";
                std::exit(1);
            }
        }

        public:
        //생성자: 모든 멤버변수 초기화, 기본값 설정, test함수들 호출
        dayOfYear(int m = 1, int d = 1)//기본값 설정
        : day{d}, month{m}
        {
            testday();
            testmonth();
        }


        void input(){
            std::cout << "Enter month: ";
            std::cin >> month;
            std::cout << "Enter day: ";
            std::cin >> day;
            testday();
            testmonth();
        }
        void setday(int d){
            day = d;
            testday();
        }
        void setmonth(int m){
            month = m;
            testmonth();
        }
        void print() const {
            switch(month){
                case 1: std::cout << "Jen."; break;
                case 2: std::cout << "Feb."; break;
                case 3: std::cout << "Mar."; break;
                case 4: std::cout << "Apr."; break;
                case 5: std::cout << "May."; break;
                case 6: std::cout << "Jun."; break;
                case 7: std::cout << "Jul."; break;
                case 8: std::cout << "Aug."; break;
                case 9: std::cout << "Sep."; break;
                case 10: std::cout << "Oct."; break;
                case 11: std::cout << "Nov."; break;
                case 12: std::cout << "Dec."; break;
            }
            std::cout << day << std::endl;
        }
        int getday() const {return day;} //함수 안에서 멤버변수 변경X
        int getmonth() const {return month;}

        // -멤버함수로 전위증가연산자, 후위증가연산자 정의
        dayOfYear operator++()
        {
            // if(day<31)
            //     return dayOfYear{month, ++day};
            // else if (month < 12)
            //     return dayOfYear{++month, 1};
            // else return dayOfYear{1, 1};

            ++day;
            if (day > 31)
            {
                ++month; day -= 31;
            }
            if (month > 12)
            {
                month = 1;
            }
            return dayOfYear{month, day};
        }

        dayOfYear operator++(int)
        {
            dayOfYear temp{month, day};
            operator++();
            return temp;
        }
        // -프렌드함수로서 입력연산자 >>, 출력연산자 <<, 이항연산자 ==, 이항연산자 + 정의
        friend std::istream& operator>>(std::istream& is, dayOfYear& d)
        {
            std::cout << "Enter month: ";
            is >> d.month; //멤버함수가 아니므로 d붙여야함
            std::cout << "Enter day: ";
            is >> d.day;
            d.testmonth();
            d.testday();
            return is;
        }

        friend std::ostream& operator<<(std::ostream& os, const dayOfYear& d)
        {
            switch(d.month){
                case 1: os << "Jen. "; break;
                case 2: os << "Feb. "; break;
                case 3: os << "Mar. "; break;
                case 4: os << "Apr. "; break;
                case 5: os << "May. "; break;
                case 6: os << "Jun. "; break;
                case 7: os << "Jul. "; break;
                case 8: os << "Aug. "; break;
                case 9: os << "Sep. "; break;
                case 10: os << "Oct. "; break;
                case 11: os << "Nov. "; break;
                case 12: os << "Dec. "; break;
            }
            os << d.day << std::endl;
            return os;
        }

        friend bool operator==(const dayOfYear& d1, const dayOfYear& d2)
        {
            return d1.month == d2.month && d1.day == d2.day;
        }

        friend dayOfYear operator+(const dayOfYear& d1, const dayOfYear& d2)
        {
            return dayOfYear{d1.month + d2.month, d1.day + d2.day};
        }
    };
}

