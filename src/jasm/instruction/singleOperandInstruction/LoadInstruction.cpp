#include "jasm/instruction/singleOperandInstruction/LoadInstruction.h"

#include <format>

namespace jasm {
	LoadInstruction::LoadInstruction(std::uint64_t index)
		: mIndex(index) { }

	bool LoadInstruction::print(std::ostream& out) {
		out << std::format("load {}", mIndex);
		return true;
	}

	LoadObjInstruction::LoadObjInstruction(std::uint64_t index)
		: mIndex(index) {}

	bool LoadObjInstruction::print(std::ostream& out) {
		out << std::format("loadobj {}", mIndex);
		return true;
	}
}
