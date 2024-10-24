#ifndef JESUSASM_NEW_INSTRUCTION_H
#define JESUSASM_NEW_INSTRUCTION_H

#include "jasm/instruction/Instruction.h"

namespace jasm {
	class NewInstruction : public Instruction {
	public:
		NewInstruction(std::uint64_t index);

		virtual bool print(std::ostream& out) override;

	private:
		std::uint64_t mIndex;
	};
}

#endif // JESUSASM_NEW_INSTRUCTION_H
