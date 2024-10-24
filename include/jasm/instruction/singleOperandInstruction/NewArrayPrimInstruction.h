
#ifndef JESUSASM_NEWARRAY_PRIM_INSTRUCTION_H
#define JESUSASM_NEWARRAY_PRIM_INSTRUCTION_H

#include "jasm/instruction/Instruction.h"

namespace jasm {
	class NewArrayPrimInstruction : public Instruction {
	public:
		NewArrayPrimInstruction(std::uint8_t typeId);

		virtual bool print(std::ostream& out) override;

	private:
		std::uint8_t mTypeId;
	};
}

#endif // JESUSASM_NEWARRAY_PRIM_INSTRUCTION_H
