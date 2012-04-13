/*
 * Copyright 2012, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef BCC_EXECUTION_ENGINE_OBJECT_LOADER_IMPL_H
#define BCC_EXECUTION_ENGINE_OBJECT_LOADER_IMPL_H

#include <cstring>

namespace bcc {

class SymbolResolverInterface;

class ObjectLoaderImpl {
public:
  ObjectLoaderImpl() { }

  virtual bool load(const void *pMem, size_t pMemSize) = 0;

  virtual bool relocate(SymbolResolverInterface &pResolver) = 0;

  virtual bool prepareDebugImage(void *pDebugImg, size_t pDebugImgSize) = 0;

  virtual void *getSymbolAddress(const char *pName) const = 0;

  virtual ~ObjectLoaderImpl() { }
};

} // namespace bcc

#endif // BCC_EXECUTION_ENGINE_OBJECT_LOADER_IMPL_H
