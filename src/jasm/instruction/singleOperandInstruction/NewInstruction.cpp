#include "jasm/instruction/singleOperandInstruction/NewInstruction.h"

#include <format>

namespace jasm {
	NewInstruction::NewInstruction(std::uint64_t index)
		: mIndex(index) { }

	bool NewInstruction::print(std::ostream& out) {
		out << std::format("newarray {}", mIndex);
		return true;
	}
}
