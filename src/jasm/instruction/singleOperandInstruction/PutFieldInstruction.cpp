#include "jasm/instruction/singleOperandInstruction/PutFieldInstruction.h"

#include <format>

namespace jasm {
	PutFieldInstruction::PutFieldInstruction(std::uint64_t index)
		: mIndex(index) { }

	bool PutFieldInstruction::print(std::ostream& out) {
		out << std::format("getfield {}", mIndex);
		return true;
	}
}
