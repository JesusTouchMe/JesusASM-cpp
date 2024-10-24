#include "jasm/Builder.h"

#include "jasm/printer/AsmBuilderPrinter.h"

#include "jasm/type/PrimitiveType.h"

int main() {
	jasm::Builder builder("Test");

	builder
		.entry(0)
		.section("constpool")
		.constFunction("Test", "main", jasm::FunctionType::Get(jasm::Type::GetVoidType(), { }))
		.section("code")
		.function("main", jasm::FunctionType::Get(jasm::Type::GetVoidType(), { }), { jasm::Modifier::Public }, 0)
		.ldi(34)
		.ldi(2)
		.mul()
		.inc()
		.hlt();

	jasm::AsmBuilderPrinter printer(builder);
	printer.print(std::cout);
}