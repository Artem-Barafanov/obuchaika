﻿#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

const ABar::MenuItem* ABar::show_menu(const MenuItem* current) {
	std::cout << "Обучайка приветствует тебя, мой юный ученик!" << std::endl;
	for (int i = 1; i < current->children_count; i++) {
		std::cout << current->children[i]->title << std::endl;
	}
	std::cout << current->children[0]->title << std::endl;
	std::cout << "Обучайка > ";

	int user_input;
	std::cin >> user_input;

	return current->children[user_input];
}

const ABar::MenuItem* ABar::exit(const MenuItem* current) {
	std::exit(0);
}

const ABar::MenuItem* ABar::study_summ(const MenuItem* current) {
	// TODO
	std::cout << current->title << std::endl;
	return current->parent;
}

const ABar::MenuItem* ABar::study_substract(const MenuItem* current) {
	// TODO
	std::cout << current->title << std::endl;
	return current->parent;
}

const ABar::MenuItem* ABar::study_multiply(const MenuItem* current) {
	// TODO
	std::cout << current->title << std::endl;
	return current->parent;
}

const ABar::MenuItem* ABar::study_divide(const MenuItem* current) {
	// TODO
	std::cout << current->title << std::endl;
	return current->parent;
}

const ABar::MenuItem* ABar::study_go_back(const MenuItem* current) {
	// TODO
	std::cout << current->title << std::endl;
	return current->parent->parent;
}