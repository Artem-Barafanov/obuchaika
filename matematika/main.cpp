#include <clocale>
#include <iostream>

#include "menu.hpp"
#include "menu_functions.hpp"

int main() {
	std::setlocale(LC_ALL, "");

	ABar::MenuItem study_summ = { "1 - Хочу учиться складывать!", ABar::study_summ };
	ABar::MenuItem study_substract = { "2 - Хочу учиться вычитать!", ABar::study_substract };
	ABar::MenuItem study_multiply = { "3 - Хочу учиться умножать!", ABar::study_multiply };
	ABar::MenuItem study_divide = { "4 - Хочу учиться делить!", ABar::study_divide };
	ABar::MenuItem study_go_back = { "0 - Выйти в главное меню", ABar::study_go_back };

	ABar::MenuItem* study_children[] = {
		&study_go_back,
		&study_summ,
		&study_substract,
		&study_multiply,
		&study_divide,
	};
	const int study_size = sizeof(study_children) / sizeof(study_children[0]);

	ABar::MenuItem study = { "1 - Хочу учиться математике!", ABar::study };
	ABar::MenuItem exit = { "0 - Я лучше пойду полежу...", ABar::exit };

	ABar::MenuItem* main_children[] = { &exit, &study };
	const int main_size = sizeof(main_children) / sizeof(main_children[0]);

	int user_input;
	do {
		std::cout << "Обучайка приветствует тебя, мой юный ученик!" << std::endl;
		for (int i = 1; i < main_size; i++) {
			std::cout << main_children[i]->title << std::endl;
		}
		std::cout << main_children[0]->title << std::endl;
		std::cout << "Обучайка > ";

		std::cin >> user_input;
		main_children[user_input]->func();

		std::cout << std::endl;
	} while (true);
	return 0;
}