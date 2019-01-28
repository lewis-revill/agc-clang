//===--- AGCToolchain.h - AGC ToolChain Implementation ----------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_AGCTOOLCHAIN_H
#define LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_AGCTOOLCHAIN_H

#include "Gnu.h"

namespace clang {
namespace driver {
namespace toolchains {

class LLVM_LIBRARY_VISIBILITY AGCToolChain : public Generic_ELF {
public:
  AGCToolChain(const Driver &D, const llvm::Triple &Triple,
               const llvm::opt::ArgList &Args);

  bool IsIntegratedAssemblerDefault() const override { return true; }
  void addClangTargetOptions(const llvm::opt::ArgList &DriverArgs,
                             llvm::opt::ArgStringList &CC1Args,
                             Action::OffloadKind) const override;
};

} // end namespace toolchains
} // end namespace driver
} // end namespace clang

#endif
