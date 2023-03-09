#include <math.h>
//#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <Windows.h>

class Game {
	int type;
	int attempt;
	int high;
	int res;
public:
	Game() :type(1), attempt(10), high(100) {}
	void setRes(int _res) {
		res = _res;
	}
	void setType(int _type) {
		type = _type;
	}
	void setAttempt(int _attempt) {
		attempt = _attempt;
	}
	void setHigh(int _high) {
		high = _high;
	}

	int getType() {
		return type;
	}

	int start() {
		if (type == 1) res = playPerson();
		else if (type == 2) res = playComp();
		return res;
	}

	int playPerson() {
		srand(time(0));
		int number = rand() % high;
		int version;
		std::cout << "Введите число - ";
		std::cin >> version;
		for (int i = 0; i < attempt - 1; i++) {
			if (version < number) {
				system("cls");
				std::cout << "Больше" << std::endl;
			}
			else if (version > number) {
				system("cls");
				std::cout << "Меньше" << std::endl;
			}
			else if (version == number) {
				return 1;
				break;
			}
			std::cout << "Введите число - ";
			std::cin >> version;
		}
		if (version != number) return 0;

	}
	int playComp() {
		int low = 0;
		int mid = (high + low) / 2;
		int sign = 0;
		int isk;
		while (sign != 1) {
			system("cls");
			std::cout << mid << std::endl;
			std::cout << "Введите 0, если ваше число ниже" << std::endl << "Введите 1, если ваше число угадано" << std::endl;
			std::cout << "Введите 2, если ваше число выше" << std::endl;
			isk = mid;
			std::cin >> sign;
			if (sign == 0) high = mid - 1;
			else if (sign == 2) low = mid + 1;
			else if (sign == 1) {
				return isk;
				break;
			}
			mid = (high + low) / 2;
			if (mid == isk) {
				return -1;
				break;
			} 
		}
	}
	void setSettings() {
		int var;
		do {
			system("cls");
			std::cout << "Что хотите изменить: " << std::endl;
			std::cout << "1.Высшее число" << std::endl;
			std::cout << "2.Кол-во попыток" << std::endl;
			std::cin >> var;
			switch (var) {
			case 1:
				system("cls");
				std::cout << "Введите высшее число - ";
				std::cin >> high;
				break;
			case 2:
				system("cls");
				std::cout << "Введите кол-во попыток - ";
				std::cin >> attempt;
				break;
			}
		} while (var != 1 && var != 2);
	}
};

int main() {
	SetConsoleOutputCP(CP_UTF8);
	int user, res;
	int high = 100;
	int attempt = 10;
	Game game;
	do {
		do {
			system("cls");
			std::cout << "1.ИГРАТЬ" << std::endl;
			std::cout << "2.ВЕДУЩИЙ" << std::endl;
			std::cout << "3.НАСТРОЙКИ" << std::endl;
			std::cout << "4.ВЫХОД" << std::endl;
			std::cout << "ВАШ ВЫБОР - ";
			std::cin >> user;
			switch (user) {
			case 1:
				system("cls");
				game.setType(1);
				res = game.start();
				if (res == 1) {
					system("cls");
					std::cout << "Победа!" << std::endl;
					system("pause");
				}
				else if (res == 0) {
					system("cls");
					std::cout << "Вы проиграли!" << std::endl;
					system("pause");
				}
				break;
			case 2:
				system("cls");
				game.setType(2);
				res =  game.start();
				if (res == -1) {
					system("cls");
					std::cout << "Ты обманул меня!" << std::endl;
					system("pause");
				}
				else {
					system("cls");
					std::cout << "Ваше число = " << res << std::endl;
					system("pause");
				}
				break;
			case 3:
				system("cls");
				game.setSettings();
				break;
			case 4:
				system("cls");
				std::cout << "Для подтверждения выхода нажмите любую клавишу";
				break;
			default:
				break;
			}
		} while (user <= 0 || user > 4);
	} while (user != 4);
	return 0;
}