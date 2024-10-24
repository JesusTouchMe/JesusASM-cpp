#ifndef JESUSASM_LDI_INSTRUCTION_H
#define JESUSASM_LDI_INSTRUCTION_H

#include "jasm/instruction/Instruction.h"

namespace jasm {
	class LdiInstruction : public Instruction {
	public:
		LdiInstruction(std::uint64_t index);

		virtual bool print(std::ostream& out) override;

	private:
		std::uint64_t mIndex;
	};
}

#endif // JESUSASM_LDI_INSTRUCTION_H
