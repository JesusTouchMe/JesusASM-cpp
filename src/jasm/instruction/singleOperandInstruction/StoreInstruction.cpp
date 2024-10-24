#include "jasm/instruction/singleOperandInstruction/StoreInstruction.h"

#include <format>

namespace jasm {
	StoreInstruction::StoreInstruction(std::uint64_t index)
		: mIndex(index) { }

	bool StoreInstruction::print(std::ostream& out) {
		out << std::format("store {}", mIndex);
		return true;
	}

	StoreObjInstruction::StoreObjInstruction(std::uint64_t index)
		: mIndex(index) {}

	bool StoreObjInstruction::print(std::ostream& out) {
		out << std::format("storeobj {}", mIndex);
		return true;
	}
}
