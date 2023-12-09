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

	ABar::MenuItem study = { "1 - Хочу учиться математике!", ABar::show_menu, study_children, study_size };
	ABar::MenuItem exit = { "0 - Я лучше пойду полежу...", ABar::exit };

	ABar::MenuItem* main_children[] = { &exit, &study };
	const int main_size = sizeof(main_children) / sizeof(main_children[0]);

	ABar::MenuItem main = { nullptr, ABar::show_menu, main_children, main_size };

	study_summ.parent = &study;
	study_substract.parent = &study;
	study_multiply.parent = &study;
	study_divide.parent = &study;
	study_go_back.parent = &study;

	study.parent = &main;
	exit.parent = &main;

	const ABar::MenuItem* current = &main;
	do {
		current = current->func(current);
	} while (true);
	return 0;
}