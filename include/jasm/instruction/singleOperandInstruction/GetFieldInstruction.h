#ifndef JESUSASM_GETFIELD_INSTRUCTION_H
#define JESUSASM_GETFIELD_INSTRUCTION_H

#include "jasm/instruction/Instruction.h"

namespace jasm {
	class GetFieldInstruction : public Instruction {
	public:
		GetFieldInstruction(std::uint64_t index);

		virtual bool print(std::ostream& out) override;

	private:
		std::uint64_t mIndex;
	};
}

#endif // JESUSASM_GETFIELD_INSTRUCTION_H