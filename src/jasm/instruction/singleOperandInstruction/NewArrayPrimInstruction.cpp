#include "jasm/instruction/singleOperandInstruction/NewArrayPrimInstruction.h"

#include <format>

namespace jasm {
	NewArrayPrimInstruction::NewArrayPrimInstruction(std::uint8_t typeId)
		: mTypeId(typeId) { }

	bool NewArrayPrimInstruction::print(std::ostream& out) {
		out << std::format("newarrayprim {}", mTypeId);
		return true;
	}
}
