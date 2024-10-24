#ifndef JESUSASM_LOAD_INSTRUCTION_H
#define JESUSASM_LOAD_INSTRUCTION_H

#include "jasm/instruction/Instruction.h"

namespace jasm {
	class LoadInstruction : public Instruction {
	public:
		LoadInstruction(std::uint64_t index);

		virtual bool print(std::ostream& out) override;

	private:
		std::uint64_t mIndex;
	};

	class LoadObjInstruction : public Instruction {
	public:
		LoadObjInstruction(std::uint64_t index);

		virtual bool print(std::ostream& out) override;

	private:
		std::uint64_t mIndex;
	};
}

#endif // JESUSASM_LOAD_INSTRUCTION_H
