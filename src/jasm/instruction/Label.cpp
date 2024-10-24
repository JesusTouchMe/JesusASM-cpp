#include "jasm/instruction/Label.h"

#include <format>

namespace jasm {
	Label::Label(std::string_view name)
		: mName(name) { }

	bool Label::print(std::ostream& out) {
		out << std::format("{}:", mName);
	}
}