#ifndef JESUSASM_ASM_BUILDER_PRINTER_H
#define JESUSASM_ASM_BUILDER_PRINTER_H

#include "jasm/Builder.h"

namespace jasm {
	// made for printing a builder
	class AsmBuilderPrinter {
	public:
		AsmBuilderPrinter(Builder& builder);

		void print(std::ostream& out);

	private:
		Builder& mBuilder;
	};
}

#endif // JESUSASM_ASM_BUILDER_PRINTER_H