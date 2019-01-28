//===--- AGC.cpp - Implement AGC target feature support -------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements the AGC TargetInfo object.
//
//===----------------------------------------------------------------------===//

#include "AGC.h"
#include "clang/Basic/MacroBuilder.h"
#include "llvm/ADT/StringSwitch.h"

using namespace clang;
using namespace clang::targets;

ArrayRef<const char *> AGCTargetInfo::getGCCRegNames() const {
  static const char *const GCCRegNames[] = {"r0", "r1", "r2", "r3",
                                            "r4", "r5", "r6", "r7"};
  return llvm::makeArrayRef(GCCRegNames);
}

ArrayRef<TargetInfo::GCCRegAlias> AGCTargetInfo::getGCCRegAliases() const {
  static const TargetInfo::GCCRegAlias GCCRegAliases[] = {
      {{"a"}, "r0"},  {{"l"}, "r1"}, {{"q"}, "x2"}, {{"eb"}, "x3"},
      {{"fb"}, "x4"}, {{"z"}, "x5"}, {{"bb"}, "x6"}};
  return llvm::makeArrayRef(GCCRegAliases);
}

void AGCTargetInfo::getTargetDefines(const LangOptions &Opts,
                                     MacroBuilder &Builder) const {
  Builder.defineMacro("__ELF__");
  Builder.defineMacro("__agc");
}
