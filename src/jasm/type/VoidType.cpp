#include "jasm/type/VoidType.h"

namespace jasm {
	VoidType::VoidType()
		: Type("void", "V") { }

	bool VoidType::isVoidType() const {
		return true;
	}
}
