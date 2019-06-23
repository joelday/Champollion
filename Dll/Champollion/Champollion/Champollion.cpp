#define _CRT_SECURE_NO_WARNINGS

#include "Champollion.h"
#include "Pex/Binary.hpp"
#include "PexStreamReader.hpp"
#include "Decompiler/PscCoder.hpp"
#include "Decompiler/AsmCoder.hpp"
#include "Decompiler/StreamWriter.hpp"

#include "Objbase.h"

using namespace System;

void pex_to_psc(char* pex, int length, std::string& result)
{
    std::stringstream buffer;
    buffer.write(pex, length);

    std::istream inputStream(buffer.rdbuf());

    Pex::PexStreamReader reader(&inputStream);

    Pex::Binary binary;
    reader.read(binary);

    std::basic_stringstream<char> pscStream;
    Decompiler::PscCoder coder(new Decompiler::StreamWriter(pscStream));

    coder.code(binary);

    result = pscStream.str();
}

void pex_to_asm(char* pex, int length, std::string& result)
{
    std::stringstream buffer;
    buffer.write(pex, length);

    std::istream inputStream(buffer.rdbuf());

    Pex::PexStreamReader reader(&inputStream);

    Pex::Binary binary;
    reader.read(binary);

    std::basic_stringstream<char> pscStream;
    Decompiler::AsmCoder coder(new Decompiler::StreamWriter(pscStream));

    coder.code(binary);

    result = pscStream.str();
}

System::String^ Champollion::PexConvert::ToPsc(array<System::Byte>^ pex)
{
    char* input = new char[pex->Length];
    Runtime::InteropServices::Marshal::Copy(pex, 0, IntPtr(input), pex->Length);

    std::string result;
    pex_to_psc(input, pex->Length, result);
    delete[] input;

    return gcnew System::String(result.c_str());
}

System::String^ Champollion::PexConvert::ToAsm(array<System::Byte>^ pex)
{
    char* input = new char[pex->Length];
    Runtime::InteropServices::Marshal::Copy(pex, 0, IntPtr(input), pex->Length);

    std::string result;
    pex_to_asm(input, pex->Length, result);
    delete[] input;

    return gcnew System::String(result.c_str());
}
