//===--- AGC.h - Declare AGC target feature support -------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file declares the AGC TargetInfo object.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_LIB_BASIC_TARGETS_AGC_H
#define LLVM_CLANG_LIB_BASIC_TARGETS_AGC_H

#include "clang/Basic/TargetInfo.h"
#include "llvm/ADT/Triple.h"
#include "llvm/Support/Compiler.h"

namespace clang {
namespace targets {

class AGCTargetInfo : public TargetInfo {
public:
  AGCTargetInfo(const llvm::Triple &Triple) : TargetInfo(Triple) {
    TLSSupported = false;

    BoolWidth = HalfWidth = IntWidth = 16;
    LongWidth = 32;
    PointerWidth = 16;

    BoolAlign = HalfAlign = IntAlign = LongAlign = 16;
    PointerAlign = 16;
    SuitableAlign = 16;

    IntMaxType = SignedLong;
    IntPtrType = SignedInt;
    PtrDiffType = SignedInt;
    SizeType = UnsignedInt;

    resetDataLayout("e-m:e-p:16:16-n16-S16");
  }

  void getTargetDefines(const LangOptions &Opts,
                        MacroBuilder &Builder) const override;

  ArrayRef<Builtin::Info> getTargetBuiltins() const override { return None; }
  BuiltinVaListKind getBuiltinVaListKind() const override {
    return TargetInfo::VoidPtrBuiltinVaList;
  }
  const char *getClobbers() const override { return ""; }

  ArrayRef<const char *> getGCCRegNames() const override;
  ArrayRef<TargetInfo::GCCRegAlias> getGCCRegAliases() const override;

  bool validateAsmConstraint(const char *&Name,
                             TargetInfo::ConstraintInfo &Info) const override {
    return false;
  }
};
} // namespace targets
} // namespace clang

#endif
