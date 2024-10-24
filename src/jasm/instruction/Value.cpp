#include "jasm/instruction/Value.h"

namespace jasm {
	std::string GetModifierName(Modifier modifier)  {
		switch (modifier) {
			case Modifier::Public: return "public";
			case Modifier::Private: return "private";
		}

		std::cout << "hey!\n";
		std::exit(1);
	}

	std::string GetModifiersAsString(const std::set<Modifier>& modifiers) {
		std::string res;

		for (const auto modifier : modifiers) {
			res += GetModifierName(modifier) + ' ';
		}

		return res;
	}
}