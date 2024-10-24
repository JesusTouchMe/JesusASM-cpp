#ifndef JESUSASM_INSTRUCTION_H
#define JESUSASM_INSTRUCTION_H

#include "jasm/instruction/Value.h"

#include <cstdint>

namespace jasm {
	template <auto N>
	struct OpcodeStringBuilder {
		consteval OpcodeStringBuilder(const char(&str)[N]) {
			std::copy(str, str + N, value);
		}

		consteval operator const char*() { return value; }

		char value[N];
	};

	class Instruction : public Value {
	public:
		virtual ~Instruction() { }
	};
}

#endif // JESUSASM_INSTRUCTION_H
