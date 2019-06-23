#pragma once

#using <mscorlib.dll>
#include <string>

void pex_to_psc(char* pex, int length, std::string& result);
void pex_to_asm(char* pex, int length, std::string& result);

namespace Champollion
{
    public ref class PexConvert abstract sealed
    {
    public:
        static System::String^ ToPsc(array<System::Byte>^ pex);
        static System::String^ ToAsm(array<System::Byte>^ pex);
    };
}
