#ifndef JESUSASM_CALL_INSTRUCTION_H
#define JESUSASM_CALL_INSTRUCTION_H

#include "jasm/instruction/Instruction.h"

namespace jasm {
	class CallInstruction : public Instruction {
	public:
		CallInstruction(std::uint64_t index);

		virtual bool print(std::ostream& out) override;

	private:
		std::uint64_t mIndex;
	};
}

#endif // JESUSASM_CALL_INSTRUCTION_H