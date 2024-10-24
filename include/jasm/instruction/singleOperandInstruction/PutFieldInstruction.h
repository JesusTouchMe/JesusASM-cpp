#ifndef JESUSASM_PUTFIELD_INSTRUCTION_H
#define JESUSASM_PUTFIELD_INSTRUCTION_H

#include "jasm/instruction/Instruction.h"

namespace jasm {
	class PutFieldInstruction : public Instruction {
	public:
		PutFieldInstruction(std::uint64_t index);

		virtual bool print(std::ostream& out) override;

	private:
		std::uint64_t mIndex;
	};
}

#endif // JESUSASM_PUTFIELD_INSTRUCTION_H
