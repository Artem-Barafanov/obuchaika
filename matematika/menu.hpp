#pragma once

namespace ABar {
	struct MenuItem {
		const char* const title;
		void (*func)();
	};
}