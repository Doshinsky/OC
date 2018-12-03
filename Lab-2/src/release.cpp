#include "/usr/include/llvm/Bitcode/BitcodeReader.h"
#include "/usr/include/llvm/Bitcode/BitcodeWriter.h"
#include "/usr/include/llvm/IR/Function.h"
#include "/usr/include/llvm/IR/LLVMContext.h"
#include "/usr/include/llvm/IR/Module.h"
#include "/usr/include/llvm/Support/CommandLine.h"
#include "/usr/include/llvm/Support/ErrorOr.h"
#include "/usr/include/llvm/Support/MemoryBuffer.h"
#include "/usr/include/llvm/Support/raw_ostream.h"

using namespace llvm;

static cl::opt<std::string>

FileName(cl::Positional, cl::desc("Bitcode file"), cl::Required);

int main(int argc, char** argv)
{
  cl::ParseCommandLineOptions(argc, argv, "LLVM hello world!\n");
  LLVMContext context;
  ErrorOr<std::unique_ptr<MemoryBuffer>> mb = MemoryBuffer::getFile(FileName);
  if (std::error_code ec = mb.getError()) {
    errs() << ec.message();
    return -1;
  }

  //ErrorOr<Module *> m = parseBitcodeFile(mb->get(), context);
  Expected<std::unique_ptr<Module>> m = parseBitcodeFile(mb->get()->getMemBufferRef(), context);
  if (std::error_code ec = errorToErrorCode(m.takeError())) {
    errs() << "Error reading bitcode: " << ec.message() << "\n";
    return -1;
  }

  for (Module::const_iterator I = (*m)->getFunctionList().begin(), E = (*m)->getFunctionList().end(); I != E; ++I) {
    if (!I->isDeclaration()) {
      outs() << I->getName() << " has " << I->size() << " basic blocks.\n";
    }
  }
  return 0;
}
