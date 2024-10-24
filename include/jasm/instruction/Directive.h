#ifndef JESUSASM_DIRECTIVES_H
#define JESUSASM_DIRECTIVES_H

#include "jasm/instruction/Value.h"

namespace jasm {
	class Directive : public Value {
	public:
		virtual ~Directive() { }
	};

	class SectionDirective : public Directive {
	public:
		SectionDirective(std::string_view name);

		virtual bool print(std::ostream& out) override;

	private:
		std::string mName;
	};
}

#endif // JESUSASM_DIRECTIVES_H
