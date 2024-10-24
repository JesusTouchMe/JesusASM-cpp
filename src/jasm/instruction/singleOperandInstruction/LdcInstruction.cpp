#include "jasm/instruction/singleOperandInstruction/LdcInstruction.h"

#include <format>

namespace jasm {
	LdcInstruction::LdcInstruction(std::uint64_t index)
		: mIndex(index) { }

	bool LdcInstruction::print(std::ostream& out) {
		out << std::format("ldc {}", mIndex);
		return true;
	}
}
