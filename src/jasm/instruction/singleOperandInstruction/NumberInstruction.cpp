#include "jasm/instruction/singleOperandInstruction/NumberInstruction.h"

#include <format>

namespace jasm {
	ByteInstruction::ByteInstruction(std::uint8_t value)
		: mValue(value) { }

	bool ByteInstruction::print(std::ostream& out) {
		out << std::format("byte {}", mValue);
		return true;
	}
	
	ShortInstruction::ShortInstruction(std::uint16_t value)
		: mValue(value) { }

	bool ShortInstruction::print(std::ostream& out) {
		out << std::format("short {}", mValue);
		return true;
	}

	IntInstruction::IntInstruction(std::uint32_t value)
		: mValue(value) { }

	bool IntInstruction::print(std::ostream& out) {
		out << std::format("int {}", mValue);
		return true;
	}

	LongInstruction::LongInstruction(std::uint64_t value)
		: mValue(value) { }

	bool LongInstruction::print(std::ostream& out) {
		out << std::format("long {}", mValue);
		return true;
	}
}
