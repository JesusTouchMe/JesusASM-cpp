#include "jasm/instruction/Directive.h"

namespace jasm {
	SectionDirective::SectionDirective(std::string_view name)
		: mName(name) { }

	bool SectionDirective::print(std::ostream& out) {
		out << "section " << mName;
		return true;
	}
}