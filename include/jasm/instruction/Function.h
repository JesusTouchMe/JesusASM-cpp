#ifndef JESUSASM_FUNCTION_VALUE_H
#define JESUSASM_FUNCTION_VALUE_H

#include "jasm/instruction/Value.h"
#include "jasm/type/FunctionType.h"

#include <cstdint>

namespace jasm {
	class Function : public Value {
	public:
		Function(std::string_view name, FunctionType* type, std::set<Modifier> modifiers, std::uint16_t locals);

		virtual bool print(std::ostream& out) override;

	private:
		std::string mName;
		FunctionType* mType;
		std::set<Modifier> mModifiers;
		std::uint16_t mLocals;
	};
}

#endif // JESUSASM_FUNCTION_VALUE_H
