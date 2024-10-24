#ifndef JESUSASM_NEWARRAY_INSTRUCTION_H
#define JESUSASM_NEWARRAY_INSTRUCTION_H

#include "jasm/instruction/Instruction.h"

namespace jasm {
	class NewArrayInstruction : public Instruction {
	public:
		NewArrayInstruction(std::uint64_t index);

		virtual bool print(std::ostream& out) override;

	private:
		std::uint64_t mIndex;
	};
}

#endif // JESUSASM_NEWARRAY_INSTRUCTION_H
