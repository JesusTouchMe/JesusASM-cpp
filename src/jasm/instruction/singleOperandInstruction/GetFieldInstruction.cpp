#include "jasm/instruction/singleOperandInstruction/GetFieldInstruction.h"

#include <format>

namespace jasm {
	GetFieldInstruction::GetFieldInstruction(std::uint64_t index)
		: mIndex(index) { }

	bool GetFieldInstruction::print(std::ostream& out) {
		out << std::format("getfield {}", mIndex);
		return true;
	}
}
