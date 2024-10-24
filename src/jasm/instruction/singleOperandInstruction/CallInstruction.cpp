#include "jasm/instruction/singleOperandInstruction/CallInstruction.h"

#include <format>

namespace jasm {
	CallInstruction::CallInstruction(std::uint64_t index)
		: mIndex(index) { }

	bool CallInstruction::print(std::ostream& out) {
		out << std::format("call {}", mIndex);
		return true;
	}
}