#ifndef JESUSASM_INSTRUCTION_H
#define JESUSASM_INSTRUCTION_H

#include "jasm/instruction/Value.h"

#include <algorithm>
#include <cstdint>

namespace jasm {
	template <auto N>
	struct OpcodeStringBuilder {
		consteval OpcodeStringBuilder(const char(&str)[N]) {
			std::copy_n(str, N, value);
		}

		char value[N];
	};

	class Instruction : public Value {
	public:
		virtual ~Instruction() { }
	};
}

#endif // JESUSASM_INSTRUCTION_H
