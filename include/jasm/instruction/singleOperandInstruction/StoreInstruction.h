#ifndef JESUSASM_STORE_INSTRUCTION_H
#define JESUSASM_STORE_INSTRUCTION_H

#include "jasm/instruction/Instruction.h"

namespace jasm {
	class StoreInstruction : public Instruction {
	public:
		StoreInstruction(std::uint64_t index);

		virtual bool print(std::ostream& out) override;

	private:
		std::uint64_t mIndex;
	};

	class StoreObjInstruction : public Instruction {
	public:
		StoreObjInstruction(std::uint64_t index);

		virtual bool print(std::ostream& out) override;

	private:
		std::uint64_t mIndex;
	};
}

#endif // JESUSASM_STORE_INSTRUCTION_H
