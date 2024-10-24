#include "jasm/printer/AsmBuilderPrinter.h"

namespace jasm {
	AsmBuilderPrinter::AsmBuilderPrinter(Builder& builder)
		: mBuilder(builder) { }

	void AsmBuilderPrinter::print(std::ostream& out) {
		out << ".module " << mBuilder.mModuleName << "\n";
		out << ".entry " << mBuilder.mEntry << "\n";

		for (const auto& value : mBuilder.mValues) {
			if (value->print(out)) {
				out << "\n";
			}
		}
	}
}