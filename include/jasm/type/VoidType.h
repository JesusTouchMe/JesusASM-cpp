#ifndef JESUSASM_VOID_TYPE_H
#define JESUSASM_VOID_TYPE_H

#include "jasm/type/Type.h"

namespace jasm {
	class VoidType : public Type {
	public:
		VoidType();

		bool isVoidType() const override;
	};
}

#endif // JESUSASM_VOID_TYPE_H
