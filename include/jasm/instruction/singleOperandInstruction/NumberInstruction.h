#ifndef JESUSASM_NUMBER_INSTRUCTION_H
#define JESUSASM_NUMBER_INSTRUCTION_H

#include "jasm/instruction/Instruction.h"

namespace jasm {
	class ByteInstruction : public Instruction {
	public:
		ByteInstruction(std::uint8_t value);

		virtual bool print(std::ostream& out) override;

	private:
		std::uint64_t mValue;
	};

	class ShortInstruction : public Instruction {
	public:
		ShortInstruction(std::uint16_t value);

		virtual bool print(std::ostream& out) override;

	private:
		std::uint64_t mValue;
	};

	class IntInstruction : public Instruction {
	public:
		IntInstruction(std::uint32_t value);

		virtual bool print(std::ostream& out) override;

	private:
		std::uint64_t mValue;
	};

	class LongInstruction : public Instruction {
	public:
		LongInstruction(std::uint64_t value);

		virtual bool print(std::ostream& out) override;

	private:
		std::uint64_t mValue;
	};
}

#endif // JESUSASM_NUMBER_INSTRUCTION_H
