#include "jasm/instruction/Function.h"

#include <format>

namespace jasm {
	Function::Function(std::string_view name, FunctionType* type, std::set<Modifier> modifiers, std::uint16_t locals)
		: mName(name)
		, mType(type)
		, mModifiers(std::move(modifiers))
		, mLocals(locals) { }

	bool Function::print(std::ostream& out) {
		out << std::format("function {}{} {}(", GetModifiersAsString(mModifiers), mType->getReturnType()->getName(), mName);
		
		const std::vector<Type*>& argumentTypes = mType->getArgumentTypes();

		if (!argumentTypes.empty()) {
			for (auto i = 0; i < argumentTypes.size() - 1; i++) {
				out << argumentTypes[i]->getName() << ", ";
			}

			out << argumentTypes.back()->getName();
		}

		out << "):\n.locals" << mLocals;

		return true;
	}
}