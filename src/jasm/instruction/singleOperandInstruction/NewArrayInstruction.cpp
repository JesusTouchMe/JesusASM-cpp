#include "jasm/instruction/singleOperandInstruction/NewArrayInstruction.h"

#include <format>

namespace jasm {
	NewArrayInstruction::NewArrayInstruction(std::uint64_t index)
		: mIndex(index) { }

	bool NewArrayInstruction::print(std::ostream& out) {
		out << std::format("newarray {}", mIndex);
		return true;
	}
}
