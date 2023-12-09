#include "menu_items.hpp"

#include <cstddef>

#include "menu_functions.hpp"

const ABar::MenuItem ABar::STUDY_SUMM = {
	"1 - Хочу научиться складывать!", ABar::study_summ, &ABar::STUDY
};
const ABar::MenuItem ABar::STUDY_SUBSTRACT = {
	"2 - Хочу научиться вычитать!", ABar::study_substract, &ABar::STUDY
};
const ABar::MenuItem ABar::STUDY_MULTIPLY = {
	"3 - Хочу научиться умножать!", ABar::study_multiply, &ABar::STUDY
};
const ABar::MenuItem ABar::STUDY_DIVIDE = {
	"4 - Хочу научиться делить!", ABar::study_divide, &ABar::STUDY
};
const ABar::MenuItem ABar::STUDY_GO_BACK = {
	"0 - Выйти в главное меню", ABar::study_go_back, &ABar::STUDY
};

namespace {
	const ABar::MenuItem* const study_children[] = {
		&ABar::STUDY_GO_BACK,
		&ABar::STUDY_SUMM,
		&ABar::STUDY_SUBSTRACT,
		&ABar::STUDY_MULTIPLY,
		&ABar::STUDY_DIVIDE,
	};
	const int study_size = sizeof(study_children) / sizeof(study_children[0]);
}

const ABar::MenuItem ABar::STUDY = {
	"1 - Хочу учиться математике!", ABar::show_menu, &ABar::MAIN, study_children, study_size
};
const ABar::MenuItem ABar::EXIT = {
	"0 - Я лучше пойду полежу...", ABar::exit, &ABar::MAIN
};

namespace {
	const ABar::MenuItem* const main_children[] = {
		&ABar::EXIT,
		&ABar::STUDY
	};
	const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const ABar::MenuItem ABar::MAIN = {
	nullptr, ABar::show_menu, nullptr, main_children, main_size
};