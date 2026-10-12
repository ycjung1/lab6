#pragma once 
#include "dayOfYear.h"
#include <string>

namespace JungYunchae2649114
{
    class holiday
    {
        std::string name;
        dayOfYear date;
        bool parkingEnforcement;

        public:
        // -생성자: 모든 멤버변수 초기화, 기본값 설정
        holiday(const std::string& n = "no name yet", dayOfYear d =dayOfYear{1, 1}, bool p = false)
            : name{n}, date{d}, parkingEnforcement{p} {}
        
            // -print: 표준스트림출력으로 멤버변수들 출력
        void print() const  //holiday::print()
        {
            std::cout << name << ": ";
            date.print(); //dayOfYear::print()
            if (parkingEnforcement)
                std::cout << "Parking laws will be enforced.\n";
            else std::cout << "Parking laws will NOT de enforced.\n";
        }

        void input()
        {
            std::cout << "Enter holiday name: ";
            std::getline(std::cin >> std::ws, name); //std::cin >> name;
            date.input();
            std::cout << "Enter parking law enforcement: 1(true) or 0(false): ";
            std::cin >> parkingEnforcement;
        }

        friend std::ostream& operator<<(std::ostream& os, const holiday& h)
        {
            //os << h.name << ": " << h.date;
            os << h.name << ": ";
            os << h.date;
            if (h.parkingEnforcement)
                os << "Parking laws will be enforced.\n";
            else os << "Parking laws will NOT de enforced.\n";

            return os;
        }

        friend std::istream& operator>>(std::istream& is, holiday& h)
        {
            std::cout << "Enter holiday name: ";
            std::getline(is >> std::ws, h.name);
            is >> h.date;

            std::cout << "Enter parking law enforcement: 1(true) or 0(false): ";
            is >> h.parkingEnforcement;

            return is;
        }

        const std::string& getName() const {return name;}
        void setName(const std::string&n) {name = n;}

        const dayOfYear& getDate() const {return date;}
        void setDate(const dayOfYear& d) {date = d;}

        void setParkingEnforcemant(bool p) {parkingEnforcement = p;}
    };
}


