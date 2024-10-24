#ifndef JESUSASM_LDC_INSTRUCTION_H
#define JESUSASM_LDC_INSTRUCTION_H

#include "jasm/instruction/Instruction.h"

namespace jasm {
	class LdcInstruction : public Instruction {
	public:
		LdcInstruction(std::uint64_t index);

		virtual bool print(std::ostream& out) override;

	private:
		std::uint64_t mIndex;
	};
}

#endif // JESUSASM_LDC_INSTRUCTION_H
