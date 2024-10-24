#include "jasm/instruction/singleOperandInstruction/LdiInstruction.h"

#include <format>

namespace jasm {
	LdiInstruction::LdiInstruction(std::uint64_t index)
		: mIndex(index) { }

	bool LdiInstruction::print(std::ostream& out) {
		out << std::format("ldi {}", mIndex);
		return true;
	}
}
