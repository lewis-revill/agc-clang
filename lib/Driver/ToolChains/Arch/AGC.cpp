//===--- AGC.cpp - AGC-specific Tool Helpers --------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "AGC.h"

using namespace clang::driver;
using namespace clang::driver::tools;
using namespace clang;
using namespace llvm::opt;

void agc::getAGCTargetFeatures(const Driver &D, const ArgList &Args,
                               std::vector<StringRef> &Features) {
  // TODO: Implement any AGC target features for the driver.
  return;
}
